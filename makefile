CC = gcc
CFLAGS = -g -Wall
ALL = recursived loopd loops recursives mains maindloop maindrec

all: $(ALL)

loops: basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives : basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived : basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH

loopd: basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH

mains : main.o libclassrec.a
	$(CC) $(CFLAGS) main.o ./libclassrec.a -L. -o mains

maindloop : main.o libclassloops.so
	$(CC) $(CFLAGS) main.o -L. ./libclassloops.so -o maindloop

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) main.o -L. ./libclassrec.so -o maindrec

clean:
	rm mains maindrec maindloop *.so *.o *.a


