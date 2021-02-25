CC=gcc
CFLAGS = -I. -Wall -lm 
DEPS   = DECIDE.h
OBJ    = DECIDE.o main.o
SRC    = main.c DECIDE.c
                  
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 
	
clean : 
	$(RM) *.bin *.o  main