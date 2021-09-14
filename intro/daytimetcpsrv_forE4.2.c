#include	"unp.h"
#include	<time.h>
void getsockname_info(int sockfd) {
    struct sockaddr_storage ss;
    socklen_t len;
    len = sizeof(ss);
    if (getsockname(sockfd, (SA *) &ss, &len) < 0) {
        err_sys("getsockname function error");
    }
    struct sockaddr_in *IPv4sock = (struct sockaddr_in *)&ss;
    printf("IPv4 family: %d\n", IPv4sock->sin_family);
    printf("IPv4 port: %d\n", ntohs(IPv4sock->sin_port));
    printf("IPv4 addr: %s\n", inet_ntoa(IPv4sock->sin_addr));
    printf("IPv4 socket: %s\n", sock_ntop((struct sockaddr *)&ss, 0));
}
int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr;
	char				buff[MAXLINE];
	time_t				ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(13);	/* daytime server */

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    printf("listenfd: \n");
    getsockname_info(listenfd);
    printf("wait for client connecting\n\n");

	Listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = Accept(listenfd, (SA *) NULL, NULL);
        printf("client is comming\n");
        printf("connfd: \n");
        getsockname_info(connfd);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

		Close(connfd);
	}
}
