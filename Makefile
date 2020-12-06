cc=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS= -Wall 

all: libmyBank.a mains maind

mybanks:libmyBank.a

mains: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a

maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.a

libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)

myBank.o: myBank.c myBank.h  
	$(CC) $(FLAGS) -c myBank.c 

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c 

clean:
	rm -f *.o *.a *.so progmains progmaind

.PHONY: clean all