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
