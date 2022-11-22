CC = gcc
CFLAGS = -g -Wall
ALL = recursived loopd loops recursives mains maindloop maindrec

all: $(ALL)

.PHONY: all recursived loopd loops recursives clean

loops: libclassloops.a

recursives: libclassrec.a

recursived:libclassrec.so

loopd: libclassloops.so


libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

libclassloops.so: basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

mains : main.o libclassrec.a NumClass.h
	$(CC) $(CFLAGS) main.o ./libclassrec.a -L. -o mains

maindloop : main.o libclassloops.so NumClass.h
	$(CC) $(CFLAGS) main.o -L. ./libclassloops.so -o maindloop

maindrec: main.o libclassrec.so NumClass.h
	$(CC) $(CFLAGS) main.o -L. ./libclassrec.so -o maindrec

clean:
	rm mains maindrec maindloop *.so *.o *.a



