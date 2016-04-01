CC=g++
CCFLAGS=-std=c++11 -O3 -g 
LDFLAGS=-lglog -lgflags
INCLUDES=-I.


convert : convert.o
	$(CC) $(CCFLAGS) -o $@ $< $(LDFLAGS)

convert.o : convert.cc
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

.PHONY:
clean :
	rm -f *.o
