include ../Make.defines

PROGS =	daytimetcpcli daytimetcpcli1 daytimetcpcli2 daytimetcpcli3 \
		daytimetcpsrv daytimetcpsrv1 daytimetcpsrv2 daytimetcpsrv3 \
		daytimetcpcliv6 daytimetcpsrvv6 daytimetcpcli_forE1.3 \
		daytimetcpcli_forE1.4 daytimetcpcli_forE1.5 daytimetcpsrv_forE1.5 \
		daytimetcpcli_forS2.9 daytimetcpsrv_forS2.9 \
		daytimetcpcli_fortest daytimetcpsrv_fortest \
		daytimetcpcli_forE4.2 daytimetcpsrv_forE4.2 \
		daytimetcpcli1_forE4.4 daytimetcpsrv1_forE4.4 \
		daytimetcpcli1_forE4.5 daytimetcpsrv1_forE4.5 \
		daytimetcpcli_forE7.2 \
		byteorder byteorder_fortest

all:	${PROGS}

daytimetcpcli:	daytimetcpcli.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli.o ${LIBS}

daytimetcpcli1:	daytimetcpcli1.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli1.o ${LIBS}

daytimetcpcli2:	daytimetcpcli2.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli2.o ${LIBS}

daytimetcpcli3:	daytimetcpcli3.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli3.o ${LIBS}

daytimetcpsrv:	daytimetcpsrv.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv.o ${LIBS}

daytimetcpsrv1:	daytimetcpsrv1.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv1.o ${LIBS}

daytimetcpsrv2:	daytimetcpsrv2.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv2.o ${LIBS}

daytimetcpsrv3:	daytimetcpsrv3.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv3.o ${LIBS}

daytimetcpcliv6:	daytimetcpcliv6.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcliv6.o ${LIBS}

daytimetcpsrvv6:	daytimetcpsrvv6.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrvv6.o ${LIBS}

daytimetcpcli_forE1.3:	daytimetcpcli_forE1.3.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forE1.3.o ${LIBS}

daytimetcpcli_forE1.4:	daytimetcpcli_forE1.4.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forE1.4.o ${LIBS}

daytimetcpcli_forE1.5:	daytimetcpcli_forE1.5.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forE1.5.o ${LIBS}

daytimetcpsrv_forE1.5:	daytimetcpsrv_forE1.5.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv_forE1.5.o ${LIBS}

daytimetcpcli_forE7.2:	daytimetcpcli_forE7.2.o 
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forE7.2.o ${LIBS}

daytimetcpcli_forS2.9:	daytimetcpcli_forS2.9.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forS2.9.o ${LIBS}

daytimetcpsrv_forS2.9:	daytimetcpsrv_forS2.9.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv_forS2.9.o ${LIBS}

daytimetcpcli_fortest:	daytimetcpcli_fortest.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_fortest.o ${LIBS}

daytimetcpsrv_fortest:	daytimetcpsrv_fortest.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv_fortest.o ${LIBS}

daytimetcpcli_forE4.2:	daytimetcpcli_forE4.2.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli_forE4.2.o ${LIBS}

daytimetcpsrv_forE4.2:	daytimetcpsrv_forE4.2.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv_forE4.2.o ${LIBS}

daytimetcpcli1_forE4.4:	daytimetcpcli1_forE4.4.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli1_forE4.4.o ${LIBS}

daytimetcpsrv1_forE4.4:	daytimetcpsrv1_forE4.4.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv1_forE4.4.o ${LIBS}

daytimetcpcli1_forE4.5:	daytimetcpcli1_forE4.5.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpcli1_forE4.5.o ${LIBS}

daytimetcpsrv1_forE4.5:	daytimetcpsrv1_forE4.5.o
		${CC} ${CFLAGS} -g -o $@ daytimetcpsrv1_forE4.5.o ${LIBS}

byteorder:	byteorder.o
		${CC} ${CFLAGS} -g -o $@ byteorder.o ${LIBS}

byteorder_fortest:	byteorder_fortest.o
		${CC} ${CFLAGS} -g -o $@ byteorder_fortest.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
