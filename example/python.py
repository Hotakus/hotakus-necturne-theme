# Python Example — classes, decorators, generics, async, type hints
# Hotakus's Nocturne Theme Preview
# MODIFIED: testing git modified state coloring

from __future__ import annotations

import asyncio
import sys
from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from datetime import datetime
from enum import Enum, auto
from typing import Any, Callable, Generic, Optional, TypeVar

T = TypeVar("T")
K = TypeVar("K")




# --- Enum ---
class Status(Enum):
    PENDING = auto()    # 打发士大夫
    ACTIVE = auto()# 打发士大夫
    COMPLETED = auto()# 打发士大夫


# --- Dataclass ---
@dataclass
class Task(Generic[T]):
    id: int
    title: str
    payload: T
    status: Status = Status.PENDING
    created_at: datetime = field(default_factory=datetime.now)

    def mark_done(self) -> None:
        self.status = Status.COMPLETED


# --- ABC ---
class Processor(ABC):
    """Abstract base class for task processors."""

    def __init__(self, name: str) -> None:
        self.name = name
        self._count = 0

    @property
    def count(self) -> int:
        return self._count

    @abstractmethod
    async def process(self, task: Task[Any]) -> bool: ...

    @staticmethod
    def validate(payload: Any) -> bool:
        """Static method to validate payload."""
        return payload is not None


# --- Concrete Class with Context Manager ---
class DataProcessor(Processor):
    """Concrete implementation."""

    def __init__(self, name: str, batch_size: int = 10) -> None:
        super().__init__(name)
        self.batch_size = batch_size
        self._buffer: list[Task[Any]] = []

    async def __aenter__(self) -> DataProcessor:
        return self

    async def __aexit__(self, *args: Any) -> None:
        await self.flush()

    async def process(self, task: Task[Any]) -> bool:
        self._buffer.append(task)
        self._count += 1
        if len(self._buffer) >= self.batch_size:
            await self.flush()
        return True

    async def flush(self) -> None:
        if not self._buffer:
            return
        self._buffer.clear()


# --- Decorator ---
def retry(max_attempts: int = 3) -> Callable[..., Any]:
    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        async def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return await func(*args, **kwargs)
                except Exception as e:
                    if attempt == max_attempts:
                        raise
                    print(f"Retry {attempt}/{max_attempts}: {e}")

        return wrapper

    return decorator


# --- Async Main ---
@retry(max_attempts=2)
async def run() -> None:
    task_a = Task(id=1, title="Hello", payload={"key": "value"})
    task_b = Task(id=2, title="World", payload=[1, 2, 3])

    async with DataProcessor("main") as proc:
        await proc.process(task_a)
        await proc.process(task_b)

    # List / dict / set comprehension & generator
    squares = [x * x for x in range(10) if x % 2 == 0]
    mapping = {x: x * x for x in range(5)}
    unique = {x for x in [1, 2, 1, 3]}
    total = sum(x for x in range(100))

    # F-strings & walrus operator
    name = "World"
    greeting = f"Hello, {name.upper():>10}!"
    if (n := len(greeting)) > 10:
        print(f"{n} chars — {__file__}")


if __name__ == "__main__":
    asyncio.run(run())
