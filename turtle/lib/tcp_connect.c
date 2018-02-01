/*************************************************************************
    > File Name: tcp_connect.c
    > Author: opas
    > Mail: 1017370773@qq.com 
    > Created Time: 2017年09月19日 星期二 15时37分52秒
 ************************************************************************/
/*include tcp_connect*/
#include "unp.h"
int
tcp_connect(const char *host, const char *serv)
{
	int		sockfd,n;
	struct addrinfo hints, *res, *ressave;
	
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		err_quit("tcp_connect error for %s, %s %s", 
				host, serv, gai_strerror(n));
	ressave = res;

	do {
		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if(sockfd < 0)
			continue;
		if(connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
			break;
		Close(sockfd);
	} while( (res = res->ai_next) != NULL);

	if (res == NULL)
		err_sys("tcp_connect error for %s, %s", host, serv);
	freeaddrinfo(ressave);

	return (sockfd);

}
/* end tcp_connect */
int 
Tcp_connect(const char *host, const char *serv)
{
	return tcp_connect(host, serv);
}
