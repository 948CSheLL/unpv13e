#include	"unp.h"

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	void				sig_chld(int);
    int i_val;
    int len;
    int result;


	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    printf("Listen socket:\n");
    printf("default: \n");
    result = getsockopt(listenfd, SOL_SOCKET, SO_KEEPALIVE, &i_val, &len);
    printf("running getsockopt result: %d, %s\n", result, result == 0 ? "success" : "fail");
    if(result == 0) {
        printf("SO_KEEPALIVE: %s\n\n", i_val == 0 ? "off" : "on");
    }
    i_val = 1;
    len = sizeof(i_val);
    result = setsockopt(listenfd, SOL_SOCKET, SO_KEEPALIVE, &i_val, len);
    printf("running setsockopt result: %d, %s\n", result, result == 0 ? "success" : "fail");
    if(result == 0) {
        printf("after run setsockopt: \n");
        result = getsockopt(listenfd, SOL_SOCKET, SO_KEEPALIVE, &i_val, &len);
        printf("running getsockopt result: %d, %s\n", result, result == 0 ? "success" : "fail");
        if(result == 0) {
            printf("SO_KEEPALIVE: %s\n\n", i_val == 0 ? "off" : "on");
        }
    }
    

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	Signal(SIGCHLD, sig_chld);	/* must call waitpid() */

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		if ( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
			if (errno == EINTR)
				continue;		/* back to for() */
			else
				err_sys("accept error");
		}

		if ( (childpid = Fork()) == 0) {	/* child process */
		    Close(listenfd);	/* close listening socket */
            printf("print connfd:\n");
            result = getsockopt(connfd, SOL_SOCKET, SO_KEEPALIVE, &i_val, &len);
            printf("running getsockopt result: %d, %s\n", result, result == 0 ? "success" : "fail");
            if(result == 0) {
                printf("SO_KEEPALIVE: %s\n\n", i_val == 0 ? "off" : "on");
            }
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		Close(connfd);			/* parent closes connected socket */
	}
}
