CC=gcc
CFLAGS = -I. -Wall -lm 
DEPS   = DECIDE.h
OBJ    = DECIDE.o main.o
SRC    = main.c DECIDE.c
                  
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

test:
	$(CC) -o test DECIDE.c test_requierments.c $(CFLAGS)
	
clean : 
	$(RM) *.bin *.o  main test