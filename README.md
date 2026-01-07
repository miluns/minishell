# minishell

**minishell** is a minimalist system shell implementation designed to explore low-level process management, file descriptor manipulation, and lexical analysis. The project prioritizes structural stability, deterministic memory management, and behavioral parity with the **Bash shell**.

Developed in collaboration with [thetopnone](https://github.com/thetopnone).
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

### Deterministic Resource Management
The shell implements a rigorous memory lifecycle policy to ensure high-uptime stability. Rather than relying on sporadic cleanup, the architecture follows a contained allocation cycle:
* **Cycle-Based Deallocation:** All data structures - lexical tokens, command tables, and expansion buffers are strictly tracked and deallocated before the next prompt.
* **Robust Error Handling:** Integrated cleanup routines ensure that memory integrity is maintained even during critical system call failures or syntax interruptions.
* **Memory Efficiency:** Verified through rigorous profiling to guarantee a zero-leak execution path, regardless of command complexity.

### Process & Signal Orchestration
Advanced orchestration ensures seamless execution and synchronization across the process tree:
* **Pipe & FD Hygiene:** Precise management of file descriptors prevents resource leaks and pipe-related hangs by ensuring atomic closure of unused ends across fork boundaries.
* **Context-Aware Signals:** Implements dynamic signal masking to handle `SIGINT`, `SIGQUIT`, and `EOF` in accordance with POSIX interactive shell specifications.
* **Status Propagation:** Employs granular `waitpid` monitoring to prevent zombie processes and ensure the accurate capture of exit codes within multi-stage pipelines.

---

## Installation

### Prerequisites
* UNIX-based operating system (Linux/macOS)
* `cc` (gcc/clang) compiler
* `GNU Readline` library
  > To compile and run this program, you must have the 'readline' development headers installed.  



  **LINUX:**  
  Debian / Ubuntu / Linux Mint / Kali Linux
  ```bash
  sudo apt-get update && sudo apt-get install libreadline-dev
  ```
  Fedora / RHEL / CentOS / AlmaLinux
  ```bash
  sudo dnf install readline-devel
  ```
  (Older versions: sudo yum install readline-devel)

  
  **macOS:**  
  Using Homebrew:
  ```bash
  brew install readline
  ```
  * NOTE for macOS:
    If the compiler cannot find the library after installation,
    you may need to export these flags or add them to your compilation command:
    ```bash
    LDFLAGS="-L$(brew --prefix readline)/lib"
    CPPFLAGS="-I$(brew --prefix readline)/include"*
    ```
### Build and usage
```bash
# Clone the repository
git clone git@github.com:miluns/minishell.git
cd minishell

# Compile the program
make

# Run minishell
./minishell
