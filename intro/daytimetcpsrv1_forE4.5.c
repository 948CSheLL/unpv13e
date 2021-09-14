#include	"unp.h"
#include	<time.h>

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	socklen_t			len;
	struct sockaddr_in	servaddr, cliaddr;
	char				buff[MAXLINE];
	time_t				ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(13);	/* daytime server */

	//Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    struct sockaddr_storage ss;
    len = sizeof(ss);
    printf("before getsockname ss size: %d\n", len);
    if (getsockname(listenfd, (SA *) &ss, &len) < 0) {
        err_sys("getsockname function error");
    }
    printf("after getsockname ss size: %d\n", len);
    printf("family: %d, AF_INET: %d\n", ss.ss_family, AF_INET);
    struct sockaddr_in *IPv4sock = (struct sockaddr_in *)&ss;
    printf("after convert:\n");
    printf("IPv4 family: %d\n", IPv4sock->sin_family);
    printf("IPv4 port: %d\n", ntohs(IPv4sock->sin_port));
    printf("IPv4 addr: %s\n", inet_ntoa(IPv4sock->sin_addr));
    printf("use sock_ntop output: %s\n", sock_ntop((struct sockaddr *)&ss, 0));

	for ( ; ; ) {
		len = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *) &cliaddr, &len);
		printf("connection from %s, port %d\n",
			   Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
			   ntohs(cliaddr.sin_port));

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

		Close(connfd);
	}
}
