#include "../lib/unp.h"
void work(char * str) {
	char str_addr[20] = "220.181.57.217";
	char *host_name = str;
  char **pptr;
	struct in_addr addr;
	struct hostent *host;
	char s_str[INET_ADDRSTRLEN];
	if(inet_pton(AF_INET, host_name, (void *)&addr) == -1)
	{
		perror("phost");
		exit(1);
	}
	if((host = gethostbyaddr((char *)&addr, sizeof(addr), AF_INET)) == NULL) {
		perror("gethostbyaddr");
		exit(1);
	}
	printf("hahaha\n");
	printf("official hostname: %s\n",host->h_name);
	for (pptr = host->h_aliases; *pptr != NULL; ++ pptr)
		printf("\talias: %s\n", *pptr);
	switch (host->h_addrtype) {
		case AF_INET:
			pptr = host->h_addr_list;
			for( ; *pptr != NULL; pptr++)
				printf("\taddress: %s\n",
								Inet_ntop(host->h_addrtype, *pptr, s_str, sizeof(s_str)));
	}
}
int 
main(int argc, char *argv[])
{
	char *ptr, **pptr;
	char str[INET_ADDRSTRLEN];
	struct hostent *hptr;

	ptr = argv[1];
	if ( (hptr = gethostbyname(ptr)) == NULL) {
				err_msg("gethostbyname error for host: %s: %s",
								ptr, hstrerror(h_errno));
			 return 0;
			}
	printf("official hostname: %s\n", hptr->h_name);
	for(pptr = hptr->h_aliases; *pptr != NULL; pptr++)
		printf("\talias: %s\n", *pptr);
  	
	switch (hptr->h_addrtype) {
		case AF_INET:
			pptr = hptr->h_addr_list;
			for ( ; *pptr != NULL; pptr ++){
				printf("\taddress: %s\n",
						Inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)) );
						printf("\tstr = change_addr = %s\n", str);
				work(str);
			}
			break;
		default:
			err_ret("unknow address type");
			break;
	}
	exit(0);
}
