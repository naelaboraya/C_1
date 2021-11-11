CC=gcc
AR=ar
FLAGS= -Wall -g


all: mains maindrec maindloop  recursives recursived loopd loops # loops isn't used by main thus we compile it seperatly.

recursives: libclassrec.a
recursived: libclassrec.so
loops: libclassloops.a
loopd: libclassloops.so

mains: main.o libclassrec.a # Main with static library with recursive lib linked (default).
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm
maindrec: main.o libclassrec.so # Main with dynamic library with recursive lib linked.
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so -lm
maindloop: main.o libclassloops.so # Main with dynamic library with loop lib linked.
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so -lm


libclassrec.a: basicClassification.o advancedClassificationRecursion.o # Static
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
libclassrec.so: basicClassification.o advancedClassificationRecursion.o # Dynamic
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o


libclassloops.a: basicClassification.o advancedClassificationLoop.o # Static
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassloops.so: basicClassification.o advancedClassificationLoop.o # Dynamic
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o


main.o: main.c numClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c numClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so *.gch maindrec maindloop mains
