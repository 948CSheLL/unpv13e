#include	"unp.h"
#include <stdio.h>
#include <sys/timeb.h>

// long long getSystemTime(){
    // struct timeb t;
    // ftime(&t);
    // return 1000 *t.time +t.millitm;
// }

void
str_cli_fortest(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

        // long long start=getSystemTime();
        struct timeval start, end;
        gettimeofday( &start,NULL );
		Writen(sockfd, sendline, 4);
		Writen(sockfd, sendline + 4, strlen(sendline + 4));
        // long long end=getSystemTime();

		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
        gettimeofday( &end,NULL );
        int timeuse =1000000 * ( end.tv_sec -start.tv_sec) + end.tv_usec -start.tv_usec;
        printf("time: %d us\n",timeuse);
        // printf("time: %lld ms\n",end-start);
	}
}
