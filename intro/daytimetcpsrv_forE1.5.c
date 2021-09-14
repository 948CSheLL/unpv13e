#include	"unp.h"
#include	<time.h>

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
	servaddr.sin_port        = htons(333);	/* daytime server */

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = Accept(listenfd, (SA *) NULL, NULL);

        ticks = time(NULL);
        // 下面这个snprintf函数，会保证buff的结尾是一个字符串结束符\0
        snprintf(buff, sizeof(buff), "%.24s\r\r\r\r\n", ctime(&ticks));
        int i;
        for (i = 0; buff[i]; i++) {
            // Write的第二个参数是void*类型，这个指针可以指向任何其他类型的变量的地址
            Write(connfd, &buff[i], 1);
        }
		Close(connfd);
	}
}
