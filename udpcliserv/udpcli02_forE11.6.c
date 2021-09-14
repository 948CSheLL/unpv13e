#include	"unp.h"

void
dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    char *sock_pre1 = sock_ntop(pservaddr, servlen);
    printf("sock_ntop1: %s\n", sock_pre1);
	int				n;
	char			sendline[MAXLINE], recvline[MAXLINE + 1];
	socklen_t		len;
	struct sockaddr	*preply_addr;
    struct hostent *aptr, *nptr;
    char **ptr;
    char str[INET_ADDRSTRLEN];

	preply_addr = Malloc(servlen);

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

        printf("********\n");
		len = servlen;
		n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
        char *sock_pre2 = sock_ntop(preply_addr, len);
        printf("sock_ntop2: %s\n", sock_pre2);
        struct sockaddr_in *tmp_sockaddr = (struct sockaddr_in *) preply_addr;
        const char *presentation = inet_ntop(AF_INET, &tmp_sockaddr->sin_addr, str, sizeof(str));
        printf("pres: %s, size: %ld\n", presentation, sizeof(presentation));
        if((aptr = gethostbyaddr(&tmp_sockaddr->sin_addr, sizeof(tmp_sockaddr->sin_addr), AF_INET)) == NULL) {
            err_quit("gethostbyaddr error");
        }
        if((nptr = gethostbyname(aptr->h_name)) == NULL) {
            err_quit("gethostbyname error");
        }
        printf("offical name: %s\n", nptr->h_name);
        ptr = nptr->h_addr_list;
        for(; *ptr != NULL; ptr++) {
            printf("address: %s\n", inet_ntop(nptr->h_addrtype, *ptr, str, sizeof(str)));
            // printf("str: %s\n", str);
        }
		if (len != servlen || memcmp(pservaddr, preply_addr, len) != 0) {
			printf("reply from %s (ignored)\n",
					Sock_ntop(preply_addr, len));
			continue;
		}

		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
	}
}

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: udpcli <IPaddress>");
    printf("argv: %s\n", argv[1]);

	bzero(&servaddr, sizeof(servaddr));
#ifdef	HAVE_SOCKADDR_SA_LEN
	servaddr.sin_len = sizeof(servaddr);
#endif
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    char *sock_pre0 = sock_ntop((SA *) &servaddr, sizeof(servaddr));
    printf("sock_ntop0: %s\n", sock_pre0);

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

	exit(0);
}
