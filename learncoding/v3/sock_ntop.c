#include "unp.h"
#ifdef HAVE_SOCKADDR_DL_STRUCT
#include <net/if_dl.h>
#endif
char *sock_ntop(const struct sockaddr *sa, socklen_t salen)
{
	char		portstr[8];
	static char str[128];
	switch(sa->sa_family) {
		case AF_INET: {
										struct sockaddr_in *sin = (struct sockaddr_in *)sa;
										if(inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL)
											return (NULL);
										if(ntohs(sin->sin_port) != 0) {
											snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
											strcat(str, portstr);
										}
										return (str);
									}
#ifdef IPV6
		case AF_INET6: {
										 struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) sa;
										 str[0] = '[';
										 if(inet_ntop(AF_INET6, &sin6->sin6_addr, str + 1, sizeof(str) - 1) == NULL )
											 return (NULL);
										 if(ntohs(sin6->sin6_port) != 0) {
											 snprintf(portstr, sizeof(portstr), "]:%d", ntohs(sin6->sin6_port));
											 strcat(str, portstr);
											 return (str);
										 }
										 return (str + 1);
									 }
#endif
#ifdef AF_UNIX
		case AF_UINX: {
										if(unp->sun_path[0] == 0)
											strcpy(str, "(no pathname bound)");
										else
											snprintf(str, sizeof(str), "%s", unp->sun_path);
										return (str);
	 								}
#endif	
	}
}
