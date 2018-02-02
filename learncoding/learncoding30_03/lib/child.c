#include "unp.h"

pid_t
child_make(int i, int listenfd, int addrlen)
{
    pid_t       pid;
    void        child_main(int, int, int);
    if( (pid = Fork()) > 0 )
        return (pid);
    child_main(i, listenfd, addrlen);
    return 0;
}

void
child_main(int i, int listenfd, int addrlen)
{
    int             connfd;
    void            web_child(int);
    socklen_t       clilen;
    struct sockaddr *cliaddr;
    cliaddr = Malloc(addrlen);

    printf("child %ld starting\n", (long)getpid());
    for( ; ; )
    {
        clilen = addrlen;
        my_lock_wait();
        connfd = Accept(listenfd, cliaddr, &clilen);
        my_lock_release();
        web_child(connfd);
        Close(connfd);
    }
}