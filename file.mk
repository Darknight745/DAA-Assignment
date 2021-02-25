a.out: client.o server.o
	gcc client.o server.o

client.o: client.c head.h
	gcc -c client.c head.h	

server.o: server.c head.h
	gcc -c server.c
