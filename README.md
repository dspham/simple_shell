simple_shell
============

### Overview
Simple Shell is a group project by [Anne-Sophie Le Bloas](https://github.com/aslebloas) and [Dennis Pham](https://github.com/dspham/). The goal is to create a simple and viable version of a Unix shell for Holberton School's first term final project.

### Requirements
* Allowed editors: vi, vim, emacs
* Environment: `Ubuntu 14.04 LTS`
* Compiler: `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* Styling: In complicance with Holberton School's [Betty Style](https://github.com/holbertonschool/Betty/wiki). It will be checked using betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All files should end with a new line
* All header files should be include guarded
* There is a list of allowed functions and system calls - Use system calls only when needed

### Mandatory





Installing
==========
#### Source
* `git clone git@github.com:dspham/simple_shell.git`
* cd into the directory
* `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

* To exit the shell, the user can either type `exit` or `control + d`



### Usage



### Example
```
parallels@parallels-vm:~/simple_shell$ ./hsh
#cisfun$ w
 00:59:43 up  2:23,  1 user,  load average: 0.04, 0.05, 0.01
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
parallel tty7     :0               22:40    2:23m 48.73s  0.16s /sbin/upstart -
#cisfun$ whoami
parallels
#cisfun$ echo "hello"
"hello"
#cisfun$ pwd
/home/parallels/simple_shell
#cisfun$ uname
Linux
#cisfun$ bc
bc 1.06.95
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'.
quit
#cisfun$ ls -lan
total 124
drwxrwxr-x  3 1000 1000  4096 Aug 26 00:59 .
drwxr-xr-x 23 1000 1000  4096 Aug 25 22:40 ..
drwxrwxr-x  8 1000 1000  4096 Aug 26 00:57 .git
-rw-rw-r--  1 1000 1000   155 Aug 23 12:11 AUTHORS
-rw-rw-r--  1 1000 1000   936 Aug 26 00:07 README.md
-rw-rw-r--  1 1000 1000   595 Aug 25 17:41 _getenv.c
-rw-rw-r--  1 1000 1000   492 Aug 24 10:57 _strdup.c
-rwxrwxr-x  1 1000 1000 14408 Aug 24 16:34 a.out
-rw-rw-r--  1 1000 1000   626 Aug 25 18:32 builtins.c
-rw-rw-r--  1 1000 1000   489 Aug 25 18:10 exec_cmd.c
-rw-rw-r--  1 1000 1000  1006 Aug 25 18:20 exec_path.c
-rw-rw-r--  1 1000 1000   345 Aug 25 18:51 helpers.c
-rw-rw-r--  1 1000 1000  1036 Aug 25 18:51 holberton.h
-rwxrwxr-x  1 1000 1000 14496 Aug 26 00:59 hsh
-rw-rw-r--  1 1000 1000   837 Aug 24 16:41 man_1_simple_shell
-rw-rw-r--  1 1000 1000   673 Aug 25 17:10 path_concat.c
-rwxrwxr-x  1 1000 1000 14496 Aug 26 00:56 shell
-rw-rw-r--  1 1000 1000  1400 Aug 26 00:58 simple_shell.c
-rw-rw-r--  1 1000 1000   960 Aug 25 17:34 splitstring.c
-rw-rw-r--  1 1000 1000   646 Aug 24 10:58 str_concat.c
-rw-rw-r--  1 1000 1000    16 Aug 24 17:48 test_ls_2
-rw-rw-r--  1 1000 1000   779 Aug 24 17:27 tok_path.c
#cisfun$ exit
parallels@parallels-vm:~/simple_shell$ 
```

### Notes


Authors
--------
Anne-Sophie Le Bloas [Github](https://github.com/aslebloas) // [Twitter](https://twitter.com/anneso_special)
Dennis Pham [Github](https://github.com/dspham/) // [Twitter](https://twitter.com/grepdennis)
