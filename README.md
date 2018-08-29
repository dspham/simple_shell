simple_shell
============

## Table of Contents

Overview
Requirements


## Overview
Simple Shell is a group project by [Anne-Sophie Le Bloas](https://github.com/aslebloas)
and [Dennis Pham](https://github.com/dspham/). The goal is to create a simple 
and viable version of a Unix shell for Holberton School's first term final project. 

## Requirements
* Allowed editors: vi, vim, emacs
* Environment: `Ubuntu 14.04 LTS`
* Compiler: `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* Styling: Holberton School's [Betty Style](https://github.com/holbertonschool/Betty/wiki). 
It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) 
and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All files should end with a new line
* All header files should be include guarded
* There is a list of allowed functions and system calls - System calls are only used when needed

## Usage
The prompt `#cisfun$` is displayed and waits for the user to type a command. 
The prompt will continue to be displayed everytime a command is executed. The 
shell uses the path environment and can also run commands with multiple arguments.

## File List

** AUTHORS **
   Credits
** README.md **
   Key information about the program
** _getenv.c **
** builtins.c **
** error_check.c **
** exec_cmd.c **
** exec_path.c **
** helpers.c **
** holberton.h **
** man_1_simple_shell **
** path_concat.c **
** print_unsigned_int.c **
** simple_shell.c **
** splitstring.c **
** str_concat.c **
** tok_path.c **

## Installation

```
git clone git@github.com:dspham/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
```

* To exit the shell, the user can either type `exit` or `ctrl + d`


## Interactive and non-interactive mode
In interactive mode, the user input is accepted from the command line.
In non-interactive-mode, the user must first run the program:

 `$ ./hsh`

Then a subshell opens, which accept the commands.

## Builtins and commands

You can check the builtin commands in the man page:
`$ man ./man_1_simple_shell`

#### Builtins:
* `exit`
* `env`

## Examples
```
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ ./hsh
#cisfun$ w
 21:07:57 up 38 min,  1 user,  load average: 0.00, 0.01, 0.03
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
vagrant  pts/0    10.0.2.2         20:31    7.00s  0.06s  0.00s w
#cisfun$ whoami
vagrant
#cisfun$ echo "hello world"
"hello world"
#cisfun$ pwd
/home/vagrant/Holberton/simple_shell
#cisfun$ uname
Linux
#cisfun$ bc
bc 1.06.95
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'.
quit
#cisfun$ ls -lan
total 96
drwxrwxr-x 3 1000 1000  4096 Aug 29 20:38 .
drwxrwxr-x 3 1000 1000  4096 Aug 29 20:38 ..
drwxrwxr-x 8 1000 1000  4096 Aug 29 20:38 .git
-rw-rw-r-- 1 1000 1000   155 Aug 29 20:38 AUTHORS
-rw-rw-r-- 1 1000 1000  3896 Aug 29 20:38 README.md
-rw-rw-r-- 1 1000 1000   595 Aug 29 20:38 _getenv.c
-rw-rw-r-- 1 1000 1000   841 Aug 29 20:38 builtins.c
-rw-rw-r-- 1 1000 1000   571 Aug 29 20:38 error_check.c
-rw-rw-r-- 1 1000 1000   506 Aug 29 20:38 exec_cmd.c
-rw-rw-r-- 1 1000 1000  1240 Aug 29 20:38 exec_path.c
-rw-rw-r-- 1 1000 1000  1661 Aug 29 20:38 helpers.c
-rw-rw-r-- 1 1000 1000  1434 Aug 29 20:38 holberton.h
-rwxrwxr-x 1 1000 1000 18512 Aug 29 20:38 hsh
-rw-rw-r-- 1 1000 1000  1194 Aug 29 20:38 man_1_simple_shell
-rw-rw-r-- 1 1000 1000   673 Aug 29 20:38 path_concat.c
-rw-rw-r-- 1 1000 1000   625 Aug 29 20:38 print_unsigned_int.c
-rw-rw-r-- 1 1000 1000  1901 Aug 29 20:38 simple_shell.c
-rw-rw-r-- 1 1000 1000   953 Aug 29 20:38 splitstring.c
-rw-rw-r-- 1 1000 1000   646 Aug 29 20:38 str_concat.c
-rw-rw-r-- 1 1000 1000   817 Aug 29 20:38 tok_path.c
#cisfun$ exit
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$
```

Collaborators
-------------
* Anne-Sophie Le Bloas -  [Github](https://github.com/aslebloas) // [Twitter](https://twitter.com/anneso_special)
* Dennis Pham - [Github](https://github.com/dspham/) // [Twitter](https://twitter.com/grepdennis)