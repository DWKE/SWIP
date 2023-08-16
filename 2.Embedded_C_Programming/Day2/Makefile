CC = gcc
TARGET = executable
OBJS = 1_IMBACK.o 2_BitwiseManipulation.o 3_IEEE754.o


$(TARGET): $(OBJS)
	$(CC) -o $(@) $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)