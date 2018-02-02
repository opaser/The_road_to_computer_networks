#include	"unp.h"

int
Mkstemp(char *template)
{
	int i;
	if ((i = mkstemp(template)) < 0)
		err_quit("mkstemp error");
	return i;
}

void
Unlink(const char *pathname)
{
	if (unlink(pathname) == -1)
		err_sys("unlink error for %s", pathname);
}

void *
Calloc(size_t n, size_t size)
{
	void	*ptr;
	if( (ptr = calloc(n, size)) == NULL)
		err_sys("calloc error");
	return ptr;
}
void Close(int fd)
{
	if(close(fd) == -1)
		err_sys("close error");
}

pid_t Fork(void)
{
	pid_t pid;
	if( (pid = fork()) == -1)
		err_sys("fork error");
	return (pid);
}

ssize_t
Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;
	if( ( n = read(fd, ptr, nbytes) ) == -1)
		err_sys("read error");
	return (n);
}

/*include Write*/
void
Write(int fd, void *ptr, size_t nbytes)
{
	if(write(fd, ptr, nbytes) != nbytes)
		err_sys("write error");
}
/*end Write*/

/*include Waitpid*/
pid_t
Waitpid(pid_t pid, int *iptr, int options)
{
	pid_t retpid;
	if( (retpid = waitpid(pid, iptr, options)) == -1)
		err_sys("waitpid error");
	return(retpid);
}
/*end Waitpid*/

/*include Fcntl*/
int Fcntl(int fd, int cmd, int arg)
{
	int n;
	if( (n = fcntl(fd, cmd, arg)) == -1)
		err_sys("fcntl error");
	return(n);
}
/*end Fcntl*/

/*include Ioct*/
int 
Ioctl(int fd, int request, void *arg)
{
	int n;
	if( (n = ioctl(fd, request, arg)) == -1)
		err_sys("ioctl error");
	return (n);
}
/*end Ioct*/

/*include Malloc*/
void *
Malloc(size_t size)
{
	void *ptr;
	if( (ptr = malloc(size)) == NULL)
		err_sys("malloc error");
	return (ptr);
}
/*end Malloc*/

/*include Sigaddset*/
void
Sigaddset(sigset_t *set, int signo)
{
	if(sigaddset(set, signo) == -1)
		err_sys("sigaddset error");
}
/*end Sigaddset*/

/*include Sigemptyset*/
void
Sigemptyset(sigset_t *set)
{
	if(sigemptyset(set) == -1)
		err_sys("sigemptyset error");
}
/*end Sigemptyset*/

/*include sigprocmask*/
void 
Sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
	if(sigprocmask(how, set, oset) == -1)
		err_sys("sigprocmask error");
}
