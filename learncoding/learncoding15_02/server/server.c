#include "../lib/unp.h"
#include <time.h>

int main(int argc, char **argv)
{	
	int listenfd, connfd;
	pid_t	childpid;
	socklen_t clilen;
	struct sockaddr_un	cliaddr, servaddr;
	void	sig_chld(int);
	listenfd = Socket(AF_LOCAL, SOCK_STREAM, 0);

	unlink(UNIXSTR_PATH);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sun_family = AF_LOCAL;
	strcpy(servaddr.sun_path, UNIXSTR_PATH);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	Signal(SIGCHLD, sig_chld);

	for( ; ; ) {
		clilen = sizeof(cliaddr);
		if( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen) ) < 0) {
			if(errno == EINTR)
				continue;
			else
				err_sys("accept error");
		}

		if( ( childpid = Fork() ) == 0) {
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
	return 0;
}
