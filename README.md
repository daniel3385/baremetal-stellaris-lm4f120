# stellaris-lm4f120
Baremetal Stellaris LM4F120

Get GCC
* wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2
* tar xjfv gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2
* ./gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc -v
* ./toolchain-arm/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc -Iincludes --specs=nosys.specs main.c

Get LM4Tools
* git clone https://github.com/utzig/lm4tools.git
* cd lm4tools/lm4flash/
* make

If you get the error "Package libusb-1.0 was not found in the pkg-config search path." during make,
you can try "sudo apt-get install libmagickwand-dev", worked for me.

Compile the project
* Just type "make" :)

OPENOCD
* Lot of info here: https://processors.wiki.ti.com/index.php/Stellaris_Launchpad_with_OpenOCD_and_Linux
* sudo openocd -f /usr/local/share/openocd/scripts/board/ek-lm4f120xl.cfg
* Open another terminal and run ./gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gdb a.out

If you have some an issue like "error while loading shared libraries: libncurses.so.5...", maybe is because you are using a 32 bits gdb but only have the 64 bits libncurses version. I did "sudo apt-get install libncurses5 libncurses5:i386" to solve it.

* (gdb) target remote localhost:3333

useful commands are:
(gdb) monitor reset init 
(gdb) monitor flash erase_sector 0 0 last