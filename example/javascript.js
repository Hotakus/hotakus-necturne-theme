// JavaScript Example — classes, async, destructuring, template literals
// Hotakus's Nocturne Theme Preview
// STAGED: testing git staged modified state

const API_BASE_URL = "https://api.example.com";
const MAX_RETRIES = 3;

// --- Class with private fields ---
class HttpClient {
  #token = "";
  #retries = 0;

  constructor(baseUrl) {
    this.baseUrl = baseUrl;
    this.#token = localStorage.getItem("token") ?? "";
  }

  get headers() {
    return {
      Authorization: `Bearer ${this.#token}`,
      "Content-Type": "application/json",
    };
  }

  async request(method, path, body = null) {
    const url = new URL(path, this.baseUrl);

    for (let i = 0; i < MAX_RETRIES; i++) {
      try {
        const res = await fetch(url, {
          method,
          headers: this.headers,
          body: body ? JSON.stringify(body) : undefined,
        });

        if (!res.ok) {
          const { status, statusText } = res;
          throw new Error(`HTTP ${status}: ${statusText}`);
        }

        return await res.json();
      } catch (err) {
        this.#retries++;
        console.warn(`Attempt ${i + 1} failed:`, err?.message);
      }
    }

    throw new Error(`All ${MAX_RETRIES} retries exhausted`);
  }

  get(path) {
    return this.request("GET", path);
  }

  post(path, body) {
    return this.request("POST", path, body);
  }
}

// --- Destructuring & rest/spread ---
const config = { timeout: 5000, debug: false, version: "1.0" };
const { timeout, ...restConfig } = config;

const defaultHeaders = {
  "X-App": "demo",
  "X-Version": config.version,
};

const merged = { ...defaultHeaders, ...restConfig };

// --- Arrow functions & template literals ---
const formatError = (code, msg) => `[${code}] ${msg.toUpperCase()}`;

// --- Optional chaining & nullish coalescing ---
function getUserDisplay(user) {
  const name = user?.profile?.displayName ?? "Anonymous";
  const email = user?.profile?.emails?.[0] ?? "N/A";
  return `${name} <${email}>`;
}

// --- Promise chaining ---
const client = new HttpClient(API_BASE_URL);

client
  .get("/status")
  .then((data) => console.log("Status:", data))
  .catch((err) => console.error(err));

// --- Generator function ---
function* idGenerator(start = 1) {
  let id = start;
  while (true) {
    yield id++;
  }
}

const gen = idGenerator(100);
console.log(gen.next().value); // 100

// --- Regular expression ---
const EMAIL_RE = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
const isValid = EMAIL_RE.test("user@example.com");

export { HttpClient, formatError, getUserDisplay, idGenerator };
