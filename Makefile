CC=./gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc
LINKER=./gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ld
CPU_FLAGS=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb

all:main.o startup_gcc.o
	$(LINKER) startup_gcc.o main.o -T lm4f120.ld

main.o:main.c
	$(CC) $(CPU_FLAGS) -Iinc -g -c main.c -o main.o 

startup_gcc.o:startup_gcc.c
	$(CC) $(CPU_FLAGS) -Iinc -g -c startup_gcc.c -o startup_gcc.o 

clean:
	rm -rf *.o a.out
