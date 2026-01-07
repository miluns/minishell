# minishell

## *An asynchronous command-line interpreter built on UNIX process architecture.*  
**minishell** is a minimalist system shell implementation designed to explore low-level process management, file descriptor manipulation, and lexical analysis. The project prioritizes structural stability, deterministic memory management, and behavioral parity with the Bash shell.

---

## Core Features

The project implements standard POSIX shell operations with a focus on robustness:

* **Binary Execution:** Support for absolute, relative paths and environment-based `PATH` resolution.
* **Pipeline Management:** Seamless execution of multiple sequential processes via pipes (`|`).
* **Redirections:** Precise handling of file descriptors:
    * Input (`<`) and Output (`>`) redirection.
    * Append mode (`>>`) and Here-doc (`<<`) implementation.
* **Built-in Commands:** High-performance native implementations of `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
* **Environment Expansion:** Dynamic variable expansion (`$VAR`) and exit status retrieval (`$?`).
* **Signal Handling:** Interactive signal management (`ctrl-c`, `ctrl-d`, `ctrl-\`) following terminal standards.

---

## Architecture

The command lifecycle is abstracted into four distinct stages:

1.  **Lexer (Tokenization):** Deconstruction of the input stream into atomic units (words, operators, metacharacters).
2.  **Parser:** Structural analysis of tokens to generate an optimized Command Table, accounting for operator precedence.
3.  **Expander:** Resolution of environment variables and quote removal before execution.
4.  **Executor:** Recursive process creation using `fork()`, managing pipes and redirections within child processes.

---

## Technical Highlights

### Resource Management
The project adheres to a strict memory lifecycle policy. Every allocation is tracked and cleared during the transition between the parsing and execution phases, ensuring zero leaks during long-running sessions.

### Process Synchronization
Utilizes granular `waitpid` monitoring and signal masking to prevent "zombie" processes and ensure accurate exit code reporting across complex pipelines.

---

## Installation & Usage

### Prerequisites
* `cc` (gcc/clang) compiler
* `GNU Readline` library
* UNIX-based operating system (Linux/macOS)

### Build
```bash
git clone [https://github.com/miluns/minishell.git](https://github.com/miluns/minishell.git)
cd minishell
make
