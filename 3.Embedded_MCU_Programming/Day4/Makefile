CC = gcc
TARGET = 2_receiver.out 2_sender.out

all: $(TARGET)

2_receiver.out: 2_receiver.c
	$(CC) -o 2_receiver.out $^

2_sender.out: 2_sender.c
	$(CC) -o 2_sender.out $^

clean:
	rm -f *.out
	rm -f $(TARGET)