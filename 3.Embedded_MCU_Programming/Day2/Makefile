CC = gcc
CFLAGS = -lwiringPi 
OBJS = 1_UltrasonicSensor.o 1_LCD.o 2_Motor_SW_PWM.c
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)