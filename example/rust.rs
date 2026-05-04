// Rust Example — traits, generics, lifetimes, enums, pattern matching
// Hotakus's Nocturne Theme Preview

use std::collections::HashMap;
use std::fmt;
use std::time::{Duration, Instant};

// --- Custom Error (impl Display + Debug) ---
#[derive(Debug)]
enum AppError {
    NotFound(String),
    Timeout { url: String, elapsed: Duration },
    Internal(String),
}

impl fmt::Display for AppError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            AppError::NotFound(id) => write!(f, "Not found: {}", id),
            AppError::Timeout { url, elapsed } => {
                write!(f, "Timeout after {:?}: {}", elapsed, url)
            }
            AppError::Internal(msg) => write!(f, "Internal error: {}", msg),
        }
    }
}

impl std::error::Error for AppError {}

// --- Trait with Associated Type ---
trait Cache<K, V> {
    type Error;

    fn get(&self, key: &K) -> Option<&V>;
    fn insert(&mut self, key: K, value: V) -> Result<(), Self::Error>;
    fn remove(&mut self, key: &K) -> Option<V>;
}

// --- Struct with Lifetimes ---
struct MemoryCache<'a, K: Eq + std::hash::Hash, V> {
    store: HashMap<K, V>,
    created: Instant,
    name: &'a str,
}

impl<'a, K: Eq + std::hash::Hash + Clone + fmt::Debug, V: Clone> Cache<K, V>
    for MemoryCache<'a, K, V>
{
    type Error = AppError;

    fn get(&self, key: &K) -> Option<&V> {
        self.store.get(key)
    }

    fn insert(&mut self, key: K, value: V) -> Result<(), Self::Error> {
        if self.store.len() >= 1000 {
            return Err(AppError::Internal("Cache full".into()));
        }
        self.store.insert(key, value);
        Ok(())
    }

    fn remove(&mut self, key: &K) -> Option<V> {
        self.store.remove(key)
    }
}

// --- Enums with Data ---
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(u8, u8, u8),
}

// --- Pattern Matching & If-let ---
fn handle_message(msg: &Message) -> String {
    match msg {
        Message::Quit => "quitting".into(),
        Message::Move { x, y } if *x > 0 => format!("moving right: {},{}", x, y),
        Message::Move { x, y } => format!("moving: {},{}", x, y),
        Message::Write(text) if text.is_empty() => "empty write".into(),
        Message::Write(text) => format!("writing: {}", text),
        Message::ChangeColor(r, g, b) => format!("color: #{:02X}{:02X}{:02X}", r, g, b),
    }
}

// --- Result & Option ---
fn fetch_config(path: &str) -> Result<HashMap<String, String>, AppError> {
    let raw = std::fs::read_to_string(path).map_err(|e| {
        AppError::Internal(format!("Cannot read {}: {}", path, e))
    })?;

    let mut config = HashMap::new();
    for line in raw.lines() {
        if let Some((key, value)) = line.split_once('=') {
            config.insert(key.trim().to_string(), value.trim().to_string());
        }
    }
    Ok(config)
}

// --- Iterator & Closures ---
fn main() {
    let numbers: Vec<i32> = (1..=20).filter(|n| n % 2 == 0).collect();
    let doubled: Vec<_> = numbers.iter().map(|&n| n * 2).collect();
    let sum: i32 = numbers.iter().sum();

    let mut cache = MemoryCache {
        store: HashMap::new(),
        created: Instant::now(),
        name: "default",
    };

    cache.insert("greeting", "hello".to_string()).ok();

    if let Some(value) = cache.get(&"greeting") {
        println!("{} from cache '{}'", value, cache.name);
    }

    let msg = Message::Move { x: 10, y: 20 };
    println!("Action: {}", handle_message(&msg));
}
