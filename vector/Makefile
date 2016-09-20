CC = g++ 
DFLAGS = -std=c++14

all: main

clean:
	rm -f * .o

My_vec.o: My_vec.cpp
	$(CC) $(DFLAGS) -c -o $@ $<

main: My_vec.o
	$(CC) $(DFLAGS) Main.cpp My_vec.o
