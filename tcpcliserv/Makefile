include ../Make.defines

PROGS =	tcpcli01 tcpcli04 tcpcli05 tcpcli06 \
		tcpcli07 tcpcli08 tcpcli09 tcpcli10 tcpcli11 \
		tcpcli11_fortest \
		tcpserv01 tcpserv02 tcpserv03 tcpserv04 \
		tcpserv02_fortest \
		tcpcli01_fortest \
		tcpserv01_fortest \
		tcpcli01_forE6.5 \
		tcpserv04_fortest \
		tcpserv04_forE7.8_without_nodelay \
		tcpserv04_forE7.8_with_nodelay \
		tcpcli01_forE7.3 \
		tcpcli01_forE7.8_without_nodelay \
		tcpcli01_forE7.8_with_nodelay \
		tcpcli01_forE7.4_servport7000 \
		tcpcli01_forE7.4_servport8000 \
		tcpserv01_forE7.4_port7000 \
		tcpserv01_forE7.4_port8000 \
		tcpserv04_forE7.12 \
		tcpcli01_forE7.12 \
		tcpserv08 tcpserv09 tcpservselect01 tcpservselect01_forE6.4 tcpservpoll01 tsigpipe

all:	${PROGS}

tcpserv04_forE7.8_with_nodelay:	tcpserv04_forE7.8_with_nodelay.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv04_forE7.8_with_nodelay.o sigchldwaitpid.o ${LIBS}

tcpserv04_forE7.8_without_nodelay:	tcpserv04_forE7.8_without_nodelay.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv04_forE7.8_without_nodelay.o sigchldwaitpid.o ${LIBS}

tcpcli01_forE7.8_without_nodelay:	tcpcli01_forE7.8_without_nodelay.o str_cli_forE7.8.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.8_without_nodelay.o str_cli_forE7.8.o ${LIBS}

tcpcli01_forE7.8_with_nodelay:	tcpcli01_forE7.8_with_nodelay.o str_cli_forE7.8.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.8_with_nodelay.o str_cli_forE7.8.o ${LIBS}

tcpcli01_forE6.5:	tcpcli01_forE6.5.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE6.5.o ${LIBS}

tcpcli01_forE7.3:	tcpcli01_forE7.3.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.3.o ${LIBS}

tcpcli01_forE7.12:	tcpcli01_forE7.12.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.12.o ${LIBS}

tcpcli01_forE7.4_servport7000:	tcpcli01_forE7.4_servport7000.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.4_servport7000.o ${LIBS}

tcpcli01_forE7.4_servport8000:	tcpcli01_forE7.4_servport8000.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE7.4_servport8000.o ${LIBS}

tcpserv01_forE7.4_port7000:	tcpserv01_forE7.4_port7000.o
		${CC} ${CFLAGS} -o $@ tcpserv01_forE7.4_port7000.o ${LIBS}

tcpserv01_forE7.4_port8000:	tcpserv01_forE7.4_port8000.o
		${CC} ${CFLAGS} -o $@ tcpserv01_forE7.4_port8000.o ${LIBS}

tcpcli01_fortest:	tcpcli01_fortest.o
		${CC} ${CFLAGS} -o $@ tcpcli01_fortest.o ${LIBS}

tcpcli01:	tcpcli01.o
		${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBS}

tcpcli04:	tcpcli04.o
		${CC} ${CFLAGS} -o $@ tcpcli04.o ${LIBS}

tcpcli05:	tcpcli05.o
		${CC} ${CFLAGS} -o $@ tcpcli05.o ${LIBS}

tcpcli06:	tcpcli06.o
		${CC} ${CFLAGS} -o $@ tcpcli06.o ${LIBS}

tcpcli07:	tcpcli07.o
		${CC} ${CFLAGS} -o $@ tcpcli07.o ${LIBS}

tcpcli08:	tcpcli08.o str_cli08.o
		${CC} ${CFLAGS} -o $@ tcpcli08.o str_cli08.o ${LIBS}

tcpcli09:	tcpcli09.o str_cli09.o
		${CC} ${CFLAGS} -o $@ tcpcli09.o str_cli09.o ${LIBS}

tcpcli10:	tcpcli10.o
		${CC} ${CFLAGS} -o $@ tcpcli10.o ${LIBS}

tcpcli11:	tcpcli11.o str_cli11.o
		${CC} ${CFLAGS} -o $@ tcpcli11.o str_cli11.o ${LIBS}

tcpcli11_fortest:	tcpcli11_fortest.o str_cli11_fortest.o
		${CC} ${CFLAGS} -o $@ tcpcli11_fortest.o str_cli11_fortest.o ${LIBS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}

tcpserv01_fortest:	tcpserv01_fortest.o str_echo_fortest.o
		${CC} ${CFLAGS} -o $@ tcpserv01_fortest.o str_echo_fortest.o ${LIBS}

tcpserv02:	tcpserv02.o sigchldwait.o
		${CC} ${CFLAGS} -o $@ tcpserv02.o sigchldwait.o ${LIBS}

tcpserv02_fortest:	tcpserv02_fortest.o sigchldwait.o
		${CC} ${CFLAGS} -o $@ tcpserv02_fortest.o sigchldwait.o ${LIBS}

tcpserv03:	tcpserv03.o sigchldwait.o
		${CC} ${CFLAGS} -o $@ tcpserv03.o sigchldwait.o ${LIBS}

tcpserv04:	tcpserv04.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv04.o sigchldwaitpid.o ${LIBS}

tcpserv04_forE7.12:	tcpserv04_forE7.12.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv04_forE7.12.o sigchldwaitpid.o ${LIBS}

tcpserv04_fortest:	tcpserv04_fortest.o sigchldwaitpid.o str_echo_fortest.o
		${CC} ${CFLAGS} -o $@ tcpserv04_fortest.o sigchldwaitpid.o str_echo_fortest.o ${LIBS}

tcpserv08:	tcpserv08.o str_echo08.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv08.o str_echo08.o sigchldwaitpid.o \
			${LIBS}

tcpserv09:	tcpserv09.o str_echo09.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ tcpserv09.o str_echo09.o sigchldwaitpid.o \
			${LIBS}

tcpservselect01:	tcpservselect01.o
		${CC} ${CFLAGS} -o $@ tcpservselect01.o ${LIBS}

tcpservselect01_forE6.4:	tcpservselect01_forE6.4.o
		${CC} ${CFLAGS} -o $@ tcpservselect01_forE6.4.o ${LIBS}

tcpservpoll01:	tcpservpoll01.o
		${CC} ${CFLAGS} -o $@ tcpservpoll01.o ${LIBS}

tsigpipe:	tsigpipe.o
		${CC} ${CFLAGS} -o $@ tsigpipe.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
