# Simple Shell

## 📃Description

This Simple Shell is a little recreation of the terminal of Shell in C language with less possibilities.


## Features and command supported

he can do command located in the directory $PATH


# 📄 Files

| Files                   | Description                                                                     |
|:------------------------|:--------------------------------------------------------------------------------|
|_getenv.c                |will get the value of an environment to search in the command wanted.            |
|_realloc.c               |will reallocate a memory block and copies memory area.                           | 
|built_in_command.c       |print the current environment,  free args and do an exit.                        |
|prompt.c                 |containt the boucle of the shell, divide, find the path of a command and divide. |
|shell.h                  |header file that contain function librairies and prototype that we use.          |


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

![flowchart projet](https://github.com/user-attachments/assets/1f0b0a2d-d120-40a6-96b1-539655a70242)

# Man page

![Man Page Simple_shell](https://github.com/user-attachments/assets/f2c977ed-09bf-40b3-8e68-e74ea16aa4a7)

## Authors

**Etienne Loichot**
- [GitHub](https://github.com/Etiennepev)

**Erwan Tixerand**
- [GitHub](https://github.com/ertix222)

[Authors](https://github.com/Etiennepev/holbertonschool-simple_shell/blob/main/Authors)
