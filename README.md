# Modern C++ features, Multithreading, Concurrency & Parallelism

This repository is a structured collection of **C++ multithreading, concurrency, parallelism, and modern c++ features**.  
It focuses on *correctness*, *synchronization*, and *design tradeoffs* when writing multi-threaded C++ code.

The code is intentionally organized by **concept**, not by application — each file explores a specific concurrency primitive, pattern, or pitfall.

---

## 🎯 Goals of This Repository

- Develop a deep understanding of **thread safety and synchronization**
- Explore **real concurrency problems** (deadlocks, livelocks, data races)
- Implement **thread-safe abstractions**
- Compare **naïve vs correct vs scalable** designs
- Practice writing **clear, explainable concurrent C++**, that is also heavily commented to understand the code.

---

## 📂 Major Modules

### 🔹 `concurrency_threads/`
Foundational multithreading concepts using `std::thread`, `mutex`, `condition_variable`, and atomics.

Topics include:
- Atomic operations and spin locks
- Producer–consumer queues
- Condition variables and lost wakeups
- Deadlocks & livelocks (including Dining Philosophers)
- Mutex types (`mutex`, `recursive_mutex`, `shared_mutex`, `timed_mutex`)
- Lazy initialization & singleton patterns
- Thread lifetime, ownership, and argument passing

This directory focuses on *how things break* — and how to fix them.

---

### 🔹 `future_promise/`
Asynchronous task coordination using:
- `std::future` / `std::promise`
- `std::async`
- `std::packaged_task`
- Shared futures and multiple consumers

Includes examples of exception propagation and async launch policies.

---

### 🔹 `modern_c_plus_plus_features/`
Modern C++ language features essential for writing safe and expressive code:
- `auto` and range-based loops
- Lambda expressions and captures
- Move semantics and move-only types
- Smart pointers (`unique_ptr`)
- Random number engines (`mt19937`)
- Lvalue/rvalue reference overloading

---

### 🔹 `monitor_class/`
Encapsulation of synchronization using **monitor-style classes**.

Examples include:
- Thread-safe bank transfers
- Naive vs correct monitor implementations
- Internally synchronized string abstractions

Demonstrates why *encapsulation of locking* matters.

---

### 🔹 `parallelism/`
Exploration of **parallel algorithms** and execution policies.

Includes:
- Parallel STL algorithms (`reduce`, `transform`, `scan`, etc.)
- Sequential vs parallel execution
- Data races caused by incorrect execution policy usage

---

### 🔹 `semaphore/`
Examples using:
- Binary semaphores
- Counting semaphores

Demonstrates alternative synchronization strategies beyond mutexes.

---

### 🔹 `shared_pointer/`
Smart pointer ownership and concurrency pitfalls:
- Shared vs internal state
- Ownership semantics
- Safe vs unsafe sharing patterns

---

### 🔹 `thread_pool/`
A practical thread pool implementation with:
- Single-queue and multi-queue designs
- Condition-variable-based task queues
- Work stealing
- Long-running task handling

This module ties together many concurrency concepts into a reusable system.

---

## 🛠️ Build & Run

Most examples are standalone:

```bash
g++ -std=c++17 file.cpp -pthread
