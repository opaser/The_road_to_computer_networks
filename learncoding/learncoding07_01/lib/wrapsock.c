#include "unp.h"

void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if(getsockname(fd, sa, salenptr) < 0 )
		err_sys("getsockname error");
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(bind(fd,sa,salen) < 0)
		err_sys("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0 )
		err_sys("connect error");
}

/*include Listen*/
void Listen(int fd, int backlog)
{
	char *ptr;
	if((ptr = getenv("LISTENQ")) != NULL )
		backlog = atoi(ptr);
	if(listen(fd, backlog) < 0)
		err_sys("listen error");
}
/* end Listen */

/*include Socket */
int
Socket(int family, int type, int protocol)
{
	int		n;
	if(( n = socket(family, type, protocol)) < 0)
		err_sys("socket error");
	return (n);
}
/*end Socket */

/*include Select */
int 
Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
					struct timeval *timeout)
{
	int		n;

	if( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
		err_sys("select error");
	return (n);
}
/*end Select*/

/*include Shutdown */
void
Shutdown(int fd, int how)
{
	if(shutdown(fd, how) < 0)
		err_sys("shutdown error");
}
/*end Shutdown*/

/*include accept*/
int
Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;
again:
	if((n = accept(fd, sa, salenptr)) < 0 ) {
#ifdef	EPROTO
		if(errno == EPROTO || errno == ECONNABORTED)
#else
		if(errno == ECONNABORTED)
#endif
				goto again;
		else
			err_sys("accept error");
	}
	return (n);
}
/*end accept*/

/*include Poll*/
int
Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
{
	int n;
	if(( n = poll(fdarray, nfds, timeout)) < 0)
		err_sys("poll error");
	return (n);
}
/*end	Poll*/
