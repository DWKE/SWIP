CC = gcc
CFLAGS = -lwiringPi 
OBJS = 2_SwitchPolling.o
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)