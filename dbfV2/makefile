objects = 	dbf.o functions.o 	

dbf:		$(objects)
		gcc -o dbf $(objects) -lm -lpthread

dbf.o:		dbf.c functions.h structure.h
		gcc -c dbf.c

functions.o:	functions.c functions.h
		gcc -c functions.c

clean :		rm dbf $(objects)
