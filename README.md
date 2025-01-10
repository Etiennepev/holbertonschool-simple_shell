# Simple Shell

## 📃Description

This Simple Shell is a little recreation of the terminal of Shell in C language with less possibilities.


## Features and command supported
he can do command located in the directory $PATH



# 📄 files

| Files                   | Description                                                             |
|:------------------------|:------------------------------------------------------------------------|
|shell.h                  |header file that contain function librairies and prototype.              |
|prompt.c                 |containt what will we write in the start of the loop who waiting a input.|
|execute_command.c        |will execute the input that he will receive.                             | 
|get_file_path.c          |will take the file to the directory PATH to search the command.          |
|_getenv.c                |will get the environmentto search in.                                    |
|_realloc.c               |he will reallocate the size we need                                      |

## exemples

```c

```

## ⬇️This is how to do the installation we need to clone the repository

```c
https://github.com/Etiennepev/holbertonschool-simple_shell.git
```
after you clone the repository you need to go in with this command

```c
cd holbertonschool-simple_shell
```
## This command is how to make a compilation to use the shell

```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

we can view if we have a leaks with the valgrind command

```c
valgrind --leak-check=full ./hsh
```

## ❗Limitations of the shell
this little shell can use only command in the $PATH directory

# Flowchart


# Man page


## Authors

**Etienne Loichot**
- [GitHub](https://github.com/Etiennepev)

**Erwan Tixerand**
- [GitHub](https://github.com/ertix222)
