# 🍴 Dining Philosophers Using Processes & System V Semaphores

## 📌 Project Overview

The **Dining Philosophers Problem** is a classic synchronization problem in Operating Systems that demonstrates how multiple processes compete for shared resources.

This project implements the Dining Philosophers problem using:

* **Linux Processes** created using `fork()`
* **System V Semaphores** for synchronization
* **Critical section management**
* **Process synchronization** using `wait()`
* **Deadlock prevention** using different fork-acquisition orders

Five philosopher processes are created, and each philosopher alternates between **Thinking**, **Hungry**, and **Eating** states.

---

## 🧠 Problem Statement

Five philosophers sit around a circular table. There is one fork between every pair of philosophers.

Each philosopher repeatedly:

1. Thinks
2. Becomes hungry
3. Picks up the two forks next to them
4. Eats
5. Releases both forks
6. Continues thinking

The challenge is to ensure that philosophers can share the forks without causing **deadlock** or allowing multiple philosophers to use the same fork simultaneously.

---

## ⚙️ Technologies & Concepts Used

| Technology / Concept    | Usage                              |
| ----------------------- | ---------------------------------- |
| C                       | Programming language               |
| Linux/Unix              | Execution environment              |
| `fork()`                | Creates philosopher processes      |
| System V Semaphores     | Synchronizes access to forks       |
| `semget()`              | Creates the semaphore set          |
| `semctl()`              | Initializes and removes semaphores |
| `semop()`               | Performs semaphore operations      |
| `wait()`                | Parent waits for child processes   |
| IPC                     | Inter-Process Communication        |
| Process Synchronization | Prevents simultaneous fork access  |

---

## 🔄 How the Program Works

The program creates **5 semaphores**, where each semaphore represents one fork.

```text
             Philosopher 0
                  |
             Fork 0 / Fork 1
                  |
       P4 ---------------- P1
       |                    |
     Fork 4              Fork 2
       |                    |
       P3 ---- Fork 3 ---- P2
```

Each philosopher is represented by a separate process.

### Philosopher States

```text
        ┌───────────┐
        │ Thinking  │
        └─────┬─────┘
              ↓
        ┌───────────┐
        │  Hungry   │
        └─────┬─────┘
              ↓
      Acquire Both Forks
              ↓
        ┌───────────┐
        │  Eating   │
        └─────┬─────┘
              ↓
       Release Forks
              ↓
          Thinking
```

---

## 🔐 Synchronization Mechanism

Each fork is represented by a binary semaphore initialized to `1`.

When a philosopher wants to pick up a fork:

```c
v.sem_op = -1;
semop(id, &v, 1);
```

The semaphore is decremented, indicating that the fork is currently being used.

After eating, the philosopher releases the fork:

```c
v.sem_op = 1;
semop(id, &v, 1);
```

The semaphore is incremented, making the fork available to another philosopher.

---

## 🛡️ Deadlock Prevention

A common problem with the Dining Philosophers solution is **deadlock**.

If every philosopher picks up their left fork first, all five philosophers could hold one fork and wait forever for the other fork.

This project avoids that situation by using **different fork acquisition orders**:

### Even-numbered philosophers

```text
Left Fork → Right Fork
```

### Odd-numbered philosophers

```text
Right Fork → Left Fork
```

For example:

```text
Philosopher 0 → Left → Right
Philosopher 1 → Right → Left
Philosopher 2 → Left → Right
Philosopher 3 → Right → Left
Philosopher 4 → Left → Right
```

This breaks the circular-wait condition and prevents the classic deadlock scenario.

---

## 📁 Project Structure

```text
dining-philosophers-system-v/
│
├── dining_philosophers.c
├── header.h
├── Makefile
├── README.md
└── screenshots/
    └── output.png
```

---

## 🛠️ Requirements

Before running the project, make sure you have:

* Linux/Unix operating system
* GCC compiler
* Basic System V IPC support

You can check GCC using:

```bash
gcc --version
```

---

## 🚀 Compilation

Compile the program using:

```bash
gcc dining_philosophers.c -o dining_philosophers
```

Or, if using the provided `Makefile`:

```bash
make
```

---

## ▶️ Running the Program

Run the compiled program:

```bash
./dining_philosophers
```

The program creates five philosopher processes.

---

## 💻 Sample Output

```text
Philosopher 0 is Thinking
Philosopher 1 is Thinking
Philosopher 2 is Thinking
Philosopher 3 is Thinking
Philosopher 4 is Thinking

Philosopher 0 is Hungry
Philosopher 0 picked Fork 0 and Fork 1
Philosopher 0 is Eating

Philosopher 1 is Hungry
Philosopher 2 is Hungry

Philosopher 0 released Fork 0 and Fork 1
Philosopher 0 Finished Eating

Philosopher 1 picked Fork 1 and Fork 2
Philosopher 1 is Eating
```

The exact output order may vary because the philosopher processes execute concurrently.

---

## 🧹 Cleanup

After all philosopher processes finish, the parent process removes the System V semaphore set using:

```c
semctl(id, 0, IPC_RMID);
```

This prevents unused IPC resources from remaining in the system.

---

## 🎯 Learning Outcomes

Through this project, I learned and demonstrated:

* Process creation using `fork()`
* Process synchronization
* Inter-Process Communication concepts
* System V semaphore operations
* Critical sections
* Resource sharing
* Deadlock conditions
* Deadlock prevention
* Process termination and synchronization using `wait()`
* Linux system programming

---

## 🔮 Possible Future Improvements

The project can be extended by:

* Adding proper error handling for all system calls
* Using command-line arguments to configure the number of philosophers
* Adding random thinking and eating times
* Implementing a different deadlock prevention technique
* Adding process IDs to the output
* Creating a visualization of philosopher states
* Comparing semaphore-based synchronization with mutex/thread-based synchronization

---

## 📚 Operating System Concepts

This project demonstrates the following Operating System concepts:

```text
Processes
    ↓
Process Creation
    ↓
fork()
    ↓
Inter-Process Synchronization
    ↓
System V Semaphores
    ↓
Critical Sections
    ↓
Deadlock Prevention
```

---

## 👨‍💻 Author

C.Varun Kumar Reddy

### Project

**Dining Philosophers Using Processes & System V Semaphores**

---

## ⭐ Conclusion

This project provides a practical implementation of the **Dining Philosophers synchronization problem** using Linux processes and System V semaphores.

By assigning a semaphore to each fork and using different fork acquisition orders for odd and even philosophers, the program demonstrates how synchronization mechanisms can be used to manage shared resources and prevent the classic circular-wait deadlock.
