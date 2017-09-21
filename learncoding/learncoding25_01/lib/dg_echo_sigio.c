/*include dgechosigio*/
#include "unp.h"
static int 	sockfd;
#define QSIZE 	8
#define MAXDG 	4096
typedef struct {
	void 	*dg_data;
	size_t  dg_len;
	struct sockaddr *dg_sa;
	socklen_t  dg_salen;

}DG;
static DG  dg[QSIZE];
static long cntread[QSIZE+1];
static int  iget;
static int iput;
static int nqueue;
static socklen_t clilen;
static void sig_io(int);
static void sig_hup(int);
void
dg_echo_sigio(int sockfd_arg, SA *pcliaddr, socklen_t clilen_arg)
{
	int 	i;
	int on = 1;
	sigset_t zeromask, newmask, oldmask;
	sockfd = sockfd_arg;
	clilen = clilen_arg;

	for( i = 0; i < QSIZE; ++i)
	{
		dg[i].dg_data = Malloc(MAXDG);
		dg[i].dg_sa = Malloc(clilen);
		dg[i].dg_salen = clilen;
	}
	iget = iput = nqueue = 0;
	Signal(SIGHUP, sig_hup);
	Signal(SIGIO, sig_io);
	Fcntl(sockfd, F_SETOWN, getpid());
	Ioctl(sockfd, FIOASYNC, &on);
	Ioctl(sockfd, FIONBIO, &on);

	Sigemptyset(&zeromask);
	Sigemptyset(&oldmask);
	Sigemptyset(&newmask);
	Sigaddset(&newmask, SIGIO);

	Sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	for(; ;)
	{
		while(nqueue == 0)
			sigsuspend(&zeromask);
		Sigprocmask(SIG_SETMASK, &oldmask, NULL);
		Sendto(sockfd, dg[iget].dg_data, dg[iget].dg_len, 
			0, dg[iget].dg_sa, dg[iget].dg_salen);
		if(++iget >= QSIZE)
			iget = 0;
		Sigprocmask(SIG_BLOCK, &newmask, &oldmask);
		nqueue --;
	}
}

static void
sig_io(int signo)
{
	ssize_t len;
	int nread;
	DG *ptr;
	printf("aa\n");
	for(nread = 0; ;)
	{
		if(nqueue >= QSIZE)
			err_quit("receive overflow");

		ptr = &dg[iput];
		ptr->dg_salen = clilen;
		len = recvfrom(sockfd, ptr->dg_data, MAXDG, 0,
				ptr->dg_sa, &ptr->dg_salen);
		if(len < 0)
		{
			if(errno == EWOULDBLOCK)
				break;
			else
				err_sys("recvfrom error");
		}
		ptr->dg_len = len;

		nread ++;
		nqueue ++;
		if(++iput >= QSIZE)
			iput = 0;
	}
	cntread[nread] ++;
}

static void 
sig_hup(int signo)
{
	int i;
	for(i = 0; i <= QSIZE; ++i)
		printf("cntread[%d] = %ld\n", i, cntread[i]);
}
