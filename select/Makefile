include ../Make.defines

PROGS =	tcpcli01 tcpcli02 tcpcli03 tcpcli01_fortest tcpcli02_fortest \
		tcpcli01_forE6.4

all:	${PROGS}

tcpcli01:	tcpcli01.o strcliselect01.o
		${CC} ${CFLAGS} -o $@ tcpcli01.o strcliselect01.o ${LIBS}

tcpcli01_fortest:	tcpcli01_fortest.o strcliselect01_fortest.o
		${CC} ${CFLAGS} -o $@ tcpcli01_fortest.o strcliselect01_fortest.o ${LIBS}

tcpcli01_forE6.4:	tcpcli01_forE6.4.o strcliselect01_forE6.4.o
		${CC} ${CFLAGS} -o $@ tcpcli01_forE6.4.o strcliselect01_forE6.4.o ${LIBS}

tcpcli02:	tcpcli02.o strcliselect02.o
		${CC} ${CFLAGS} -o $@ tcpcli02.o strcliselect02.o ${LIBS}

tcpcli02_fortest:	tcpcli02_fortest.o strcliselect02_fortest.o
		${CC} ${CFLAGS} -o $@ tcpcli02_fortest.o strcliselect02_fortest.o ${LIBS}

tcpcli03:	tcpcli03.o
		${CC} ${CFLAGS} -o $@ tcpcli03.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
