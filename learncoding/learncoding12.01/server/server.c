#include "../lib/unp.h"
#include <time.h>

int main(int argc, char **argv)
{	
	int listenfd, connfd, one;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	struct sockaddr_in6 cliaddr6, servaddr6;
	void	sig_chld(int);
	if(atoi(argv[1]) == 4) {
		if( (listenfd = Socket(AF_INET, SOCK_STREAM, 0) ) == -1 ) {
			printf("socket ipv4 error");
			return 0;
		}
		if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
			close(listenfd);
			return -1;
		}
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT);
		Bind( listenfd, (SA *) &servaddr, sizeof(servaddr) );
	} else {
		if( (listenfd = Socket(AF_INET6, SOCK_STREAM, 0)) == -1 ) {
			printf("socket ipv6 error");
			return 0;
		}
		bzero(&servaddr6, sizeof(servaddr6));
		servaddr6.sin6_family = AF_INET6;
		servaddr6.sin6_port = htons(SERV_PORT);
		servaddr6.sin6_addr = in6addr_any;	
		Bind(listenfd, (SA *) &servaddr6, sizeof(servaddr6) ); 
	}
	Listen(listenfd, LISTENQ);
	Signal(SIGCHLD, sig_chld);
	for(;;) {
		SA * D;
		if( atoi(argv[1]) == 4 ) {
			D = (SA*) &cliaddr;
			clilen = sizeof(cliaddr);
		} else {
			D = (SA*) &cliaddr6;
			clilen = sizeof(cliaddr6);
		}
		if( ( connfd = accept(listenfd, D, &clilen) ) < 0 ) {
			if (errno == EINTR)
				continue;
			else
				err_sys("accept error");
		}
		if( ( childpid = Fork() ) == 0 ) {
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
	return 0;
}
