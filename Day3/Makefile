CC = gcc
CFLAGS = -lrt
TARGETS = producer consumer
OBJS = 4_shared_memory_producer.o 4_shared_memory_consumer.o

all: $(TARGETS)

producer: 4_shared_memory_producer.c
	$(CC) -o producer 4_shared_memory_producer.c $(CFLAGS)

consumer: 4_shared_memory_consumer.c
	$(CC) -o consumer 4_shared_memory_consumer.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGETS)

# CC = gcc
# CFLAGS = -pthread
# TARGET = executable
# OBJS = 1_RandomNumberGeneration.o 2_MonteCarloSimulation.o 3_SharedBuffer.o


# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(@) $(OBJS)

# clean:
# 	rm -f *.o
# 	rm -f $(TARGET)