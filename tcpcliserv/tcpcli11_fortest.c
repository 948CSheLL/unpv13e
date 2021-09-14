#include	"unp.h"

void sig_pipe(int signo) {
    printf("broken pipe\n");
}

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Signal(SIGPIPE, sig_pipe);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
    sleep(2);
	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
