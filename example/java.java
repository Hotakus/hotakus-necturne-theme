public class Main {
    // Hotakus's Nocturne Theme Preview — Java
    // generics, inner class, enum, lambda, stream

    public enum Status {
        PENDING, ACTIVE, COMPLETED
    }

    public interface Processor<T> {
        boolean process(T item);
        default String describe() {
            return "Processor<" + getClass().getSimpleName() + ">";
        }
    }

    public static class Task<T> {
        private final int id;
        private final String title;
        private final T payload;
        private Status status = Status.PENDING;

        public Task(int id, String title, T payload) {
            this.id = id;
            this.title = title;
            this.payload = payload;
        }

        public int getId() { return id; }
        public String getTitle() { return title; }
        public T getPayload() { return payload; }
        public Status getStatus() { return status; }

        public void markDone() {
            this.status = Status.COMPLETED;
        }

        @Override
        public String toString() {
            return "Task{id=" + id + ", title='" + title + "', status=" + status + "}";
        }
    }

    public static class TaskProcessor implements Processor<Task<String>> {
        @Override
        public boolean process(Task<String> task) {
            if (task == null || task.getPayload() == null) {
                throw new IllegalArgumentException("task or payload must not be null");
            }
            System.out.println("Processing: " + task);
            task.markDone();
            return true;
        }
    }

    public static <T extends Comparable<T>> T max(T a, T b) {
        return a.compareTo(b) > 0 ? a : b;
    }

    public static void main(String[] args) {
        var processor = new TaskProcessor();

        var tasks = java.util.List.of(
            new Task<>(1, "Hello", "world"),
            new Task<>(2, "Java", "theme"),
            new Task<>(3, "Example", "test")
        );

        // Stream API + lambda
        long completed = tasks.stream()
            .filter(t -> processor.process(t))
            .peek(System.out::println)
            .count();

        System.out.println("Completed: " + completed);
        System.out.println("Max: " + max(10, 20));

        // Try-catch with resources
        try (var reader = new java.io.BufferedReader(new java.io.StringReader("test"))) {
            System.out.println(reader.readLine());
        } catch (java.io.IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
