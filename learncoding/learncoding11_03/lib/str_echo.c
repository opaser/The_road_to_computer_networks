#include "unp.h"

void str_echo(int sockfd)
{
	ssize_t		n;
	char			buf[MAXLINE];
again:
	while(( n = read(sockfd, buf, MAXLINE)) > 0 ) {
		printf("tcp receive length => %d, detail => %s", n, buf);
		buf[n-1] = '.';
		buf[n] = 0;
		strcat(buf,"chen xin I love you too! use tcp");
		n = strlen(buf);
		buf[n] = '\n';
		n = n + 1;
		printf("tcp send length => %d, detail => %s", n, buf);
		Writen(sockfd, buf, n);
	}
	if(n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
}
