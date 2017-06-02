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

/*include Recvfrom */
ssize_t
Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t	n;
	if((n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr))<0)
		err_sys("recvfrom error");
	return (n);
}
/* end Recvfrom*/

/*include Sento*/
void
Sendto(int fd, const void *ptr, size_t nbytes, int flags,
		const struct sockaddr *sa, socklen_t salen)
{
	if(sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
		err_sys("sendto error");
}
/*end Sento*/

/*include Setsockopt*/
void
Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	if(setsockopt(fd, level, optname, optval, optlen) < 0)
		err_sys("Setsockopt error");
}
/*end Setsockopt*/

/*include Recvmsg*/
ssize_t
Recvmsg(int fd, struct msghdr *msg, int flags)
{
	ssize_t n;
	if( (n = recvmsg(fd, msg, flags)) < 0)
		err_sys("recvmsg error");
	return(n);
}
/*end Recvmsg */

/*include Sendmsg*/
void 
Sendmsg(int fd, const struct msghdr *msg, int flags)
{
	unsigned int i;
	ssize_t nbytes;
	nbytes = 0;
	for(i = 0; i < msg->msg_iovlen; i++)
		nbytes += msg->msg_iov[i].iov_len;
	if(sendmsg(fd, msg, flags) != nbytes)
		err_sys("sendmsg error");
}
/*end Sendmsg*/

/*include Socketpair*/
void Socketpair(int family, int type, int protocol, int *fd)
{
	int n;
	if( (n = socketpair(family, type, protocol, fd)) < 0)
		err_sys("socketpair error");
}
/*end Socketpair*/

