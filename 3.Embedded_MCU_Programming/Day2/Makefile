CC = gcc
CFLAGS = -lwiringPi 
OBJS = 1_UltrasonicSensor.o 1_LCD.o 3_Motor_HW_PWM.c 4_LED_mmap.c
# 3_Motor_HW_PWM.c
TARGET = executable

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)