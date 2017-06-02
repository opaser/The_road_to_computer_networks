#!/bin/bash
product=$1
g++ ../lib/unp.h ../lib/dg_cli.c ../lib/error.c ../lib/sigchldwaitpid.c ../lib/sock_ntop.c ../lib/str_echo.c ../lib/wraplib.c ../lib/wrapstdio.c ../lib/writen.c ../lib/dg_echo.c ../lib/readline.c ../lib/signal.c ../lib/str_cli.c ../lib/wrapsock.c ../lib/wrapunix.c ../lib/read_fd.c ../lib/write_fd.c ../lib/myopen.c ../client/client.c -o ${product}
