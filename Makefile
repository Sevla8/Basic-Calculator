OFILES = main.o \
         calcul.o \
         operator.o \
         tools.o

FLAGS = -Wall -ansi -pedantic -g

exe : $(OFILES)
	gcc $(FLAGS) -o exe $(OFILES)

main.o : main.c
	gcc -c main.c

tools.o : tools.c tools.h
	gcc -c tools.c

operator.o : operator.c operator.h
	gcc -c operator.c

calcul.o : calcul.c calcul.h
	gcc -c calcul.c

.PHONY : clean

clean :
	rm -f $(OFILES) exe