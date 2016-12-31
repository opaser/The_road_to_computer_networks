#include "unp.h"

int main()	{
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = inet_addr("0.0.0.1");
	printf("%s\n", Sock_ntop((struct sockaddr *)&servaddr, sizeof(servaddr) )); 
	printf("%d\n", servaddr.sin_addr.s_addr);
	struct sockaddr_in6 servaddr6;
	bzero(&servaddr6, sizeof(servaddr6));
	servaddr6.sin6_family = AF_INET6;
	servaddr6.sin6_port = htons(13);
	inet_pton(AF_INET6, "2000:0:0:0:1:0:0:0", &servaddr6.sin6_addr);
	printf("%s\n", Sock_ntop((struct sockaddr *)&servaddr6, sizeof(servaddr6)));
	return 0;
}
