odir := .
default: linked_list_interactive
all: linked_list_interactive linked_list


linked_list: ${odir}/linked_list.o ${odir}/list_utils.o 
	gcc -o linked_list ${odir}/linked_list.o ${odir}/list_utils.o 

linked_list_interactive: ${odir}/linked_list_interactive.o ${odir}/list_utils.o 
	gcc -o linked_list_interactive ${odir}/linked_list_interactive.o ${odir}/list_utils.o

linked_list.o: linked_list.c list_utils.h
	gcc -c linked_list.c -o ${odir}/linked_list.o

linked_list_interactive.o: linked_list_interactive.c list_utils.h
	gcc -c linked_list_interactive.c -o ${odir}/linked_list_interactive.o

list_utils.o: list_utils.c list_utils.h
	gcc -c list_utils.c -o ${odir}/list_utils.o

clean: 
	rm -f linked_list linked_list_interactive list_utils *.o ${odir}/*.o

