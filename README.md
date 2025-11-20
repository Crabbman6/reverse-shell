# Reverse Shell In C | Linux 

## Disclaimer
**FOR EDUCATIONAL PURPOSES ONLY.**
This code is intended to demonstrate how operating systems handle process I/O and networking, do not use this inappropriately. 

## Concepts Covered
* **Socket Programming:** Creating TCP endpoints using `<sys/socket.h>`.
* **Structs:** Manually populating `sockaddr_in` for IPv4 networking.
* **File Descriptor Manipulation:** Using `dup2()` to redirect Stdin, Stdout, and Stderr to a network socket.
* **Process Execution:** Using `execve()` to replace the current process image with `/bin/sh`.



## How to Compile
```bash
gcc shell.c -o shell
