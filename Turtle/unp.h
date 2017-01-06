#ifndef __unp_h
#define __unp_h
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
/* define var */
#define MAXLINE 4096
#define PORT 9999
#define LISTENQ 1024
#define SA struct sockaddr
#define IPV6 11
/*sock_ntop.c */
char * sock_ntop(const struct sockaddr *sa, socklen_t salen);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);


/*error.c */
#include <errno.h>
void err_sys(const char *, ...);
#endif
