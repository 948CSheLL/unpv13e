#include	"unp.h"

int
main(int argc, char **argv)
{
	char			*ptr, **pptr;
	char			str[INET_ADDRSTRLEN];
	struct hostent	*hptr;

	while (--argc > 0) {
		ptr = *++argv;
		if ( (hptr = gethostbyname(ptr)) == NULL) {
			err_msg("gethostbyname error for host: %s: %s",
					ptr, hstrerror(h_errno));
			continue;
		}
		printf("official hostname: %s\n", hptr->h_name);

		for (pptr = hptr->h_aliases; *pptr != NULL; pptr++)
			printf("\talias: %s\n", *pptr);

		switch (hptr->h_addrtype) {
		case AF_INET:
			pptr = hptr->h_addr_list;
            printf("%ld\n", hptr);
            for ( ; *pptr != NULL; pptr++) {
				printf("\taddress: %s\n", Inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                struct hostent *hptr_1;
		        if ( (hptr_1 = gethostbyaddr(*pptr, hptr->h_length, hptr->h_addrtype)) == NULL) {
		        	err_msg("gethostbyaddr error for host: %s: %s", ptr, hstrerror(h_errno));
		        	continue;
                }
                printf("%ld\n", hptr_1);
		        printf("official hostname: %s\n", hptr_1->h_name);
            }
			break;

		default:
			err_ret("unknown address type");
			break;
		}
	}
	exit(0);
}
