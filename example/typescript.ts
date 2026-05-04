// TypeScript Example — types, generics, decorators, enums, interfaces
// Hotakus's Nocturne Theme Preview

// --- Enum ---
enum Direction {
  Up = "UP",
  Down = "DOWN",
  Left = "LEFT",
  Right = "RIGHT",
}

// --- Interface & Type Alias ---
interface User {
  id: number;
  name: string;
  email?: string;
}

type ApiResponse<T> = {
  data: T;
  status: number;
  message: string;
};

// --- Decorator ---
function log(target: any, key: string, descriptor: PropertyDescriptor) {
  const original = descriptor.value;
  descriptor.value = function (...args: unknown[]) {
    console.log(`Calling ${key} with`, args);
    return original.apply(this, args);
  };
}

// --- Generic Class ---
class Repository<T extends { id: number }> {
  private items: Map<number, T> = new Map();

  add(item: T): void {
    this.items.set(item.id, item);
  }

  find(id: number): T | undefined {
    return this.items.get(id);
  }

  getAll(): T[] {
    return Array.from(this.items.values());
  }
}

// --- Generic Function with Constraints ---
function pick<T, K extends keyof T>(obj: T, keys: K[]): Pick<T, K> {
  const result = {} as Pick<T, K>;
  for (const key of keys) {
    result[key] = obj[key];
  }
  return result;
}

// --- Async/Await & Optional Chaining ---
async function fetchUser(id: number): Promise<ApiResponse<User>> {
  try {
    const res = await fetch(`/api/users/${id}`);
    const data: User = await res.json();
    const picked = pick(data, ["id", "name"]);

    return {
      data,
      status: res.status,
      message: data.email?.includes("@") ? "OK" : "No email",
    };
  } catch (error: unknown) {
    const msg = error instanceof Error ? error.message : "Unknown error";
    throw new Error(`Failed: ${msg}`);
  }
}

// --- Decorator Usage ---
class UserService {
  private repo = new Repository<User>();

  @log
  getUser(id: number): User | undefined {
    return this.repo.find(id);
  }

  @log
  addUser(user: User): void {
    this.repo.add(user);
  }
}

// --- Type Guards ---
function isString(value: unknown): value is string {
  return typeof value === "string";
}

// --- Template Literal Type ---
type EventName = `on${Capitalize<Direction>}`;

// --- Assertions & nullish ---
const canvas = document.querySelector("#app") as HTMLCanvasElement;
const status: string = "ok";
const defaultName = status ?? "anonymous";

export { Direction, User, ApiResponse, Repository, fetchUser, UserService };
