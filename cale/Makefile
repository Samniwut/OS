CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = main.o mathx.o

calc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c mathx.h
	$(CC) $(CFLAGS) -c main.c

mathx.o: mathx.c mathx.h
	$(CC) $(CFLAGS) -c mathx.c

clean:
	rm -f calc $(OBJS)

.PHONY: clean
