CC = g++
CFLAGS = -Wall -O2 -fsanitize=address -DLOCAL
LDFLAGS = -lm

all: A B C D E

A: 
	${CC} ${CFLAGS} A.cpp -o A
B:
	${CC} ${CFLAGS} B.cpp -o B
C:	
	${CC} ${CFLAGS} C.cpp -o C
D:	
	${CC} ${CFLAGS} D.cpp -o D
E:
	${CC} ${CFLAGS} E.cpp -o E

clean:
	rm A
	rm B
	rm C
	rm D
	rm E