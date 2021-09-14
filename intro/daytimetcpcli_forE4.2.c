#include	"unp.h"

void getsockname_info(int sockfd) {
    struct sockaddr_storage ss;
    socklen_t len;
    len = sizeof(ss);
    // printf("before getsockname ss size: %d\n", len);
    if (getsockname(sockfd, (SA *) &ss, &len) < 0) {
        err_sys("getsockname function error");
    }
    // printf("after getsockname ss size: %d\n", len);
    // printf("family: %d, AF_INET: %d\n", ss.ss_family, AF_INET);
    struct sockaddr_in *IPv4sock = (struct sockaddr_in *)&ss;
    // printf("after convert:\n");
    printf("IPv4 family: %d\n", IPv4sock->sin_family);
    printf("IPv4 port: %d\n", ntohs(IPv4sock->sin_port));
    printf("IPv4 addr: %s\n", inet_ntoa(IPv4sock->sin_addr));
    printf("IPv4 socket: %s\n", sock_ntop((struct sockaddr *)&ss, 0));
}

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

    // getsockname_info(sockfd);

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	exit(0);
}
