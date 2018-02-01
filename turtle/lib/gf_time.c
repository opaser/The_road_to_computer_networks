#include "unp.h"
#include <time.h>

char *
gf_time(void)
{
	struct timeval tv;
	time_t t;
	static char str[30];
	char   *ptr;
	if(gettimeofday(&tv, NULL) < 0)
		err_sys("gettimeofday error");
	t = tv.tv_sec;
	ptr = ctime(&t);
	strcpy(str, &ptr[11]);
	snprintf(str+8, sizeof(str)-8, ".%06ld", tv.tv_usec);
	return (str);
}
