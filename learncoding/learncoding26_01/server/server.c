#include "../lib/unpthread.h"

#define NLOOP 5000

int counter;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t ndone_cond = PTHREAD_COND_INITIALIZER; 
void *doit(void *); 
void *sleepdo(void *); 
int main(int argc, char **argv) 
{	
	pthread_t tidA, tidB; 
	Pthread_create(&tidA, NULL, &doit, NULL); 
	Pthread_create(&tidB, NULL, &sleepdo, NULL); 
	Pthread_join(tidA, NULL); 
	Pthread_join(tidB, NULL); 
	return 0; 
} 
void *
doit(void *vptr)
{
	Pthread_mutex_lock(&counter_mutex);
	printf("doit start\n");
	Pthread_cond_wait(&ndone_cond, &counter_mutex);

	printf("doit end\n");
	Pthread_mutex_unlock(&counter_mutex);
	return (NULL);
}

void *
sleepdo(void *vptr)
{
	sleep(10);
	Pthread_mutex_lock(&counter_mutex);

	printf("sleepdo start\n");
	Pthread_cond_signal(&ndone_cond);
	sleep(5);
	printf("sleepdo end\n");
	Pthread_mutex_unlock(&counter_mutex);
	return (NULL);
}
