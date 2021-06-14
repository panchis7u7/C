CC=g++
CPPFLAGS=-Wall -Wextra -lcurl -lcurlpp -pedantic-errors -std=c++2a
PROG=main

OBJS=main.o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(CPPFLAGS)

main.o: main.cpp

clean:
	rm main.o