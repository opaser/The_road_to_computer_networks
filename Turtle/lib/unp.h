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
#include <sys/wait.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>
#include <netinet/sctp.h>
/* define var */
#define MAXLINE 4096
#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define SA struct sockaddr
#define IPV6 11
#define LISTENQ 1024
#define BUFFSIZE	8192
#define SERV_MAX_SCTP_STRM 10

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE  (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)


typedef void  Sigfunc(int);
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#ifndef INFTIM
#define	INFTIM	(-1)
#endif

/*sock_ntop.c */
char * sock_ntop(const struct sockaddr *sa, socklen_t salen);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);

/* wrapsock.c  */
void Getsockname(int, SA *, socklen_t *);
void Bind(int, const SA *, socklen_t);
void Listen(int, int);
void Connect(int, const SA*, socklen_t);
int	 Socket(int, int, int);
int  Select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
void Shutdown(int, int);
int  Accept(int, SA *, socklen_t *);
int	 Poll(struct pollfd*, unsigned long, int);
ssize_t Recvfrom(int, void *, size_t, int, SA *, socklen_t *);
void Sendto(int, const void*, size_t, int, const SA *, socklen_t);
void Setsockopt(int, int, int, const void *, socklen_t);
void Getsockopt(int, int, int, void*, socklen_t*);

/* signal.c */
Sigfunc *Signal(int, Sigfunc *);

/* wrapunix.c */
void Close(int);
pid_t Fork(void);
ssize_t Read(int, void *, size_t);
void	Write(int, void *, size_t);

/* writen.c */
ssize_t writen(int, const void *, size_t);
void Writen(int, void *, size_t);

/*error.c */
#include <errno.h>
void err_sys(const char *, ...);
void err_quit(const char *, ...);

/* wraplib.c */
const char	*Inet_ntop(int, const void *, char *, size_t);
void	Inet_pton(int, const char *, void *);

/* wrapstdio.c */
char *Fgets(char *, int, FILE *);
void  Fputs(const char*, FILE *);

/*str_echo.c is testing */
void str_echo(int);

/*str_cli.c is testing */
void str_cli(FILE *, int);

/* readline.c */
ssize_t readline(int, void *, size_t);
ssize_t Readline(int, void *, size_t);

/* dg_echo.c */
void dg_echo(int, SA *, socklen_t);

/*dg_cli.c*/
void dg_cli(FILE *, int, const SA *, socklen_t);

/*sctp_wrapper.c*/
int Sctp_recvmsg(int, void*, size_t, struct sockaddr*, socklen_t*, 
									struct sctp_sndrcvinfo*, int*);
int Sctp_sendmsg(int, void*, size_t, struct sockaddr*, socklen_t,
									uint32_t, uint32_t, uint16_t, uint32_t, uint32_t);
int Sctp_bindx(int, struct sockaddr_storage*, int, int);

/*sctp_getnostrm.c*/
int sctp_get_no_strms(int, struct sockaddr*, socklen_t);

/*sctp_addr_to_associd.c*/
sctp_assoc_t sctp_address_to_associd(int, struct sockaddr*, socklen_t);

/*sctp_strcli.c*/
void sctpstr_cli(FILE*, int, struct sockaddr*, socklen_t);

/*sctp_strcliecho.c*/
void sctpstr_cli_echoall(FILE*, int, struct sockaddr*, socklen_t);
#endif
