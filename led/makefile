
PREF := arm-none-eabi-
CC := $(PREF)gcc.exe
AS := $(PREF)as.exe
LD := $(PREF)ld.exe

HWFLAGS := -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16

COPT  := -c -O0 $(HWFLAGS)
LDOPT := -Tstm32-flash.ld $(HWFLAGS)

INCLUDES = -I.

all: a.out

a.out: main.o
	$(LD) $(LDOPT) $^ -o $@

%.o: %.c
	$(CC) $(COPT) $< -o $@

%.o: %.s
	$(AS) $< -o $@

