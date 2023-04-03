odir := .

linke_list: ${odir}/linked_list.o 
	gcc -o linked_list ${odir}/linked_list.o 

linked_list.o: linked_list.c
	gcc -c linked_list.c -o ${odir}/linked_list.o

clean: 
	rm -f linked_list *.o ${odir}/*.o
