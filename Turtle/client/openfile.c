#include "../lib/unp.h"
int 
main(int argc, char **argv)
{
	int fd;
	if (argc != 4)
		err_quit("openfile <sockfd#> <filename> <mode>");
	if( (fd = open(argv[2], atoi(argv[3]))) < 0)
		exit( (errno > 0) ? errno : 255);
	char str_null[10] = "";
	if(Write_fd(atoi(argv[1]), str_null, 1, fd) < 0)
		exit( (errno > 0) ? errno : 255);
	return 0;
}
