CC = gcc
CFLAGS = -lpthread
TARGET = executable
OBJS = monte_carlo.o rand_between.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

monte_carlo.o: monte_carlo.c
	$(CC) -c monte_carlo.c

rand_between.o: rand_between.c
	$(CC) -c rand_between.c

clean:
	rm -f *.o
	rm -f $(TARGET)
