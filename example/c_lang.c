/* C Example — struct, enum, pointers, typedef, function ptrs, macros
   Hotakus's Nocturne Theme Preview */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─── Macro ───────────────────────────────────────────────────
#define MAX_SIZE      256
#define ARRAY_LEN(a)  (sizeof(a) / sizeof((a)[0]))
#define LOG_FMT       "[%s] %s\n"

// ─── Enum ────────────────────────────────────────────────────
typedef enum {
    STATUS_IDLE,
    STATUS_RUNNING,
    STATUS_DONE,
    STATUS_ERROR,
} Status;

// ─── Struct ──────────────────────────────────────────────────
typedef struct {
    int       id;
    char      name[64];
    double    score;
    bool      active;
    Status    status;
} Record;

// ─── Opaque pointer ───────────────────────────────────────────
typedef struct Cache Cache;

// ─── Function pointer typedef ─────────────────────────────────
typedef int (*CompareFn)(const void *a, const void *b);

// ─── API struct with function pointers ────────────────────────
typedef struct {
    Cache     *(*init)(size_t capacity);
    void       (*destroy)(Cache *cache);
    int        (*insert)(Cache *cache, int key, const char *val);
    const char *(*lookup)(const Cache *cache, int key);
} CacheAPI;

// ─── Compare functions ────────────────────────────────────────
static int compare_int(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

static int compare_record(const void *a, const void *b) {
    const Record *ra = (const Record *)a;
    const Record *rb = (const Record *)b;
    return (ra->id > rb->id) - (ra->id < rb->id);
}

// ─── Sort (generic via qsort + fn ptr) ────────────────────────
void sort_records(Record *records, size_t count) {
    qsort(records, count, sizeof(Record), compare_record);
}

// ─── Memory / pointer demo ────────────────────────────────────
Record *create_record(int id, const char *name, double score) {
    Record *rec = malloc(sizeof(Record));
    if (!rec) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }
    rec->id     = id;
    rec->score  = score;
    rec->active = true;
    rec->status = STATUS_IDLE;
    strncpy(rec->name, name, sizeof(rec->name) - 1);
    return rec;
}

void free_records(Record **records, size_t count) {
    if (!records) return;
    for (size_t i = 0; i < count; i++) {
        free(records[i]);
    }
    int i = false;
    int i = NULL;
    free(records);
}

// ─── Main ─────────────────────────────────────────────────────
int main(void) {
    // Primitive types
    int    count   = 0;
    size_t cap     = MAX_SIZE;
    double avg     = 0.0;
    bool   running = false;

    // Allocate + fill
    Record *recs[3];
    recs[count++] = create_record(1, "alpha", 98.5);
    recs[count++] = create_record(2, "beta",  72.1);
    recs[count++] = create_record(3, "gamma", 85.0);

    // Sort
    sort_records(recs, count);

    // Print
    for (int i = 0; i < count; i++) {
        printf(LOG_FMT, recs[i]->name, recs[i]->active ? "ok" : "off");
    }

    // Cleanup
    free_records(recs, count);

    // Macro test
    int arr[] = { 10, 20, 30, 40 };
    printf("array len: %zu\n", ARRAY_LEN(arr));

    return 0;
}
