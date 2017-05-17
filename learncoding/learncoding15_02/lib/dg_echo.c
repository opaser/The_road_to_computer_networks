#include "unp.h"

/*include dg_echo*/
void
dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int		n;
	socklen_t	len;
	char	mesg[MAXLINE];

	for(;;){
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
/*dg_echo end*/
