#include "unp.h"

int main(int argc, char *argv[])
{	
	int listenfd,connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE+1];
	time_t t;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);
	while(1){
		connfd = accept(listenfd, (SA *)NULL, NULL);
		strcpy(buff, "this is a messsage\n");

		write(connfd, buff, strlen(buff));
		close(connfd);
	}
	exit(0);
	return 0;
}
