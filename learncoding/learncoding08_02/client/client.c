#include "../lib/unp.h"
int 
main(int argc, char *argv[])
{
	int		udp_sockfd;
	struct sockaddr_in	udp_servaddr;
	if(argc != 2)
		err_quit("usage: udpcli <IPaddress>");
	bzero(&udp_servaddr, sizeof(udp_servaddr));
	udp_servaddr.sin_family = AF_INET;
	udp_servaddr.sin_port = htons(SERV_PORT);	
	Inet_pton(AF_INET, argv[1], &udp_servaddr.sin_addr);
	
	udp_sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(stdin, udp_sockfd, (SA*) &udp_servaddr, sizeof(udp_servaddr));
	
	int tcp_sockfd;
	struct sockaddr_in	tcp_servaddr;
	tcp_sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&tcp_servaddr, sizeof(tcp_servaddr));
	tcp_servaddr.sin_family = AF_INET;
	tcp_servaddr.sin_port	= htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &tcp_servaddr.sin_addr);
	Connect(tcp_sockfd, (SA *)&tcp_servaddr, sizeof(tcp_servaddr));
	str_cli(stdin, tcp_sockfd);
	exit(0);
}
