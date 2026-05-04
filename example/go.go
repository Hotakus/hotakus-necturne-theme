// Go Example — interfaces, goroutines, channels, error handling
// Hotakus's Nocturne Theme Preview

package main

import (
    "context"
    "encoding/json"
    "errors"
    "fmt"
    "io"
    "net/http"
    "sync"
    "time"
)

// --- Interface ---
type Storable interface {
    Save(ctx context.Context) error
    Load(ctx context.Context, id string) error
}

// --- Custom Error ---
var (
    ErrNotFound = errors.New("record not found")
    ErrTimeout  = errors.New("operation timed out")
)

// --- Struct with Tags ---
type Record struct {
    ID        string    `json:"id"`
    Title     string    `json:"title"`
    Count     int       `json:"count"`
    Active    bool      `json:"active"`
    CreatedAt time.Time `json:"created_at"`
}

// --- Method Receiver ---
func (r *Record) Save(ctx context.Context) error {
    if r.ID == "" {
        return fmt.Errorf("save failed: %w", ErrNotFound)
    }
    data, _ := json.MarshalIndent(r, "", "  ")
    fmt.Println(string(data))
    return nil
}

func (r *Record) Load(ctx context.Context, id string) error {
    if id == "" {
        return ErrNotFound
    }
    r.ID = id
    r.Title = "example"
    return nil
}

// --- Generic Function (Go 1.18+) ---
func Filter[T any](items []T, fn func(T) bool) []T {
    result := make([]T, 0, len(items))
    for _, item := range items {
        if fn(item) {
            result = append(result, item)
        }
    }
    return result
}

// --- Worker Pool with Goroutines & Channels ---
type Job struct {
    ID   int
    Data string
}

type Result struct {
    JobID int
    Value string
    Err   error
}

func worker(ctx context.Context, jobs <-chan Job, results chan<- Result, wg *sync.WaitGroup) {
    defer wg.Done()
    for {
        select {
        case job, ok := <-jobs:
            if !ok {
                return
            }
            // simulate work
            time.Sleep(50 * time.Millisecond)
            results <- Result{
                JobID: job.ID,
                Value: fmt.Sprintf("processed: %s", job.Data),
            }
        case <-ctx.Done():
            return
        }
    }
}

// --- HTTP Handler ---
func handleFetch(w http.ResponseWriter, r *http.Request) {
    ctx, cancel := context.WithTimeout(r.Context(), 5*time.Second)
    defer cancel()

    id := r.URL.Query().Get("id")
    if id == "" {
        http.Error(w, "missing id", http.StatusBadRequest)
        return
    }

    record := &Record{}
    if err := record.Load(ctx, id); err != nil {
        if errors.Is(err, ErrNotFound) {
            http.Error(w, err.Error(), http.StatusNotFound)
            return
        }
        http.Error(w, "internal error", http.StatusInternalServerError)
        return
    }

    w.Header().Set("Content-Type", "application/json")
    json.NewEncoder(w).Encode(record)
}

func main() {
    // Generics
    nums := []int{1, 2, 3, 4, 5, 6}
    evens := Filter(nums, func(n int) bool { return n%2 == 0 })
    fmt.Println("Evens:", evens)

    // Channel pattern
    jobs := make(chan Job, 10)
    results := make(chan Result, 10)
    var wg sync.WaitGroup

    ctx, cancel := context.WithCancel(context.Background())
    defer cancel()

    for i := 0; i < 3; i++ {
        wg.Add(1)
        go worker(ctx, jobs, results, &wg)
    }

    go func() {
        for j := 1; j <= 5; j++ {
            jobs <- Job{ID: j, Data: fmt.Sprintf("payload-%d", j)}
        }
        close(jobs)
    }()

    go func() {
        wg.Wait()
        close(results)
    }()

    for res := range results {
        if res.Err != nil {
            fmt.Printf("Error on job %d: %v\n", res.JobID, res.Err)
            continue
        }
        fmt.Printf("Job %d: %s\n", res.JobID, res.Value)
    }
}
