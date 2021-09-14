
#include	"unp.h"

void
dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	for ( ; ; ) {
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
        struct sockaddr_un *cliaddr = (struct sockaddr_un *) pcliaddr;
        printf("client unix address: %s\n", cliaddr->sun_path);

		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
