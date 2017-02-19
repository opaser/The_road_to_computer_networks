#include "../lib/unp.h"
#include <netinet/tcp.h>
union val{
	int			i_val;
	long		l_val;
	struct linger linger_val;
	struct timeval timeval_val;
}val;
static char *sock_str_int(union val *,int);
char *(*opt_val_str)(union val*, int);
int main(int argc, char *argv[])
{
	int fd;
	socklen_t	len;
	struct sockaddr_in servaddr;
	fd = Socket(AF_INET, SOCK_STREAM, 0);
  len = sizeof(val);
	if(getsockopt(fd, SOL_SOCKET, SO_SNDBUF, &val, &len) == -1)
		printf("getsockopt, error");
	else
		printf("default	SO_SNDBUF SIZE = %s\n",sock_str_int(&val, len));
	
	if(getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) == -1)
		printf("getsockopt, error");
	else
		printf("default SO_RCVBUF SIZE = %s\n",sock_str_int(&val, len));
	exit(0);
}
static char strres[128];
static char *
sock_str_int(union val *ptr, int len)
{
	if(len!=sizeof(int))
		snprintf(strres, sizeof(strres), "size (%d) not sizeof(int)",len);
	else
		snprintf(strres, sizeof(strres), "%d", ptr->i_val);
	return (strres);
}
