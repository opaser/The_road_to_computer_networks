#include "unp.h"
void
str_cli(FILE *fp, int sockfd)
{
	int		maxfdp1, stdineof;
	fd_set rset;
	char	buf[MAXLINE];
	int		n;
	char    my_detail[MAXLINE];
	stdineof = 0;
	FD_ZERO(&rset);
	for(; ;)	{
		if(stdineof == 0)
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1	= max(fileno(fp), sockfd) + 1;
		Select(maxfdp1, &rset, NULL, NULL, NULL);
		if(FD_ISSET(sockfd, &rset) ) {
			if (( n = Read(sockfd, buf,		MAXLINE)) == 0){
				if(stdineof == 1)
					return ;
				else
					err_quit("str_cli: server terminated prematurely");
			}
			Write(fileno(stdout),buf, n);
		}
		if(FD_ISSET(fileno(fp), &rset))	{
			if ( (n = Read(fileno(fp), buf, MAXLINE)) == 0 )	{
				stdineof = 1;
				Shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			if(strlen(buf) == 5 && buf[0] == 'q' && buf[1] == 'u' && buf[2] == 'i' && buf[3] == 't') {
				sprintf(my_detail, "%d\n", buf[4]);
				Write(fileno(stdout), my_detail, strlen(my_detail)) ;
				stdineof = 1;
				Shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			Writen(sockfd, buf, n);
		}
	}
	Close(sockfd);
}
