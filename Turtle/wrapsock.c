#include "unp.h"

void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if(getsockname(fd, sa, salenptr) < 0 )
		err_sys("getsockname error");
}
