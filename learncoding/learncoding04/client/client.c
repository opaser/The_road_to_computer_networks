#include "../unp.h"

int main(int argc, char *argv[])
{
	int sockfd,n,count = 0;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	if(argc != 2) {
		fprintf(stderr, "usage: client <IP>\n");
		exit(1);
	}
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr , "socker error\n");
		exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		fprintf(stderr, "inet_pton error for %s\n", argv[1]);
		exit(1);
	}
	if(connect(sockfd,(SA *) &servaddr, sizeof(servaddr)) < 0) {
		fprintf(stderr, "connect error\n");
		exit(1);
	}
	struct sockaddr_in cliaddr;
	socklen_t len;
	len = sizeof(cliaddr);
	Getsockname(sockfd, (SA *)&cliaddr, &len);
	printf("local addr : %s\n", Sock_ntop((SA * )&cliaddr, len )); 
	while((n = read(sockfd, recvline, MAXLINE)) > 0) {
		++ count;
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF) {
			fprintf(stderr, "fputs error\n");
			exit(1);
		}
	}
	printf("recvline %d times\n", count);
	if(n < 0) {
		fprintf(stderr, "read error\n");
		exit(1);
	}
	
	return 0;
}
