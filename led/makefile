
FWDIR=D:/progs/stm32f4discovery/STM32F4-Discovery_FW_V1.1.0

PREF := arm-none-eabi-
CC := $(PREF)gcc.exe
AS := $(PREF)as.exe
LD := $(PREF)ld.exe

HWFLAGS := -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
INCLUDES = -I$(FWDIR)/Libraries/CMSIS/Include -I$(FWDIR)/Libraries/CMSIS/ST/STM32F4xx/Include

COPT  := -c -O0 $(HWFLAGS) $(INCLUDES)
LDOPT := -Tstm32-flash.ld $(HWFLAGS)


all: a.out

a.out: main.o
	$(LD) $(LDOPT) $^ -o $@

%.o: %.c
	$(CC) $(COPT) $< -o $@

%.o: %.s
	$(AS) $< -o $@


clean:
	@del /q *.o
	@del /q a.out
