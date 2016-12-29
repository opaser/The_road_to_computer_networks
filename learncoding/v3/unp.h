#ifndef __unp_h
#define __unp_h
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
/* define var */
#define MAXLINE		4096

/*sock_ntop.c */
char * sock_ntop(const sturct sockaddr *sa, socklen_t salen);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);


/*error.c */
void err_sys(const char *, ...);
#endif
