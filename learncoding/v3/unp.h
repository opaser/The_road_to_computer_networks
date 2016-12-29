#ifndef __unp_h
#define __unp_h
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
char * sock_ntop(const sturct sockaddr *sa, socklen_t salen);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);
#endif
