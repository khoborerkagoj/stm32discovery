
FWDIR=D:/progs/stm32f4discovery/STM32F4-Discovery_FW_V1.1.0

PREF	:= arm-none-eabi-
CC	:= $(PREF)gcc.exe
AS	:= $(PREF)as.exe
LD	:= $(PREF)gcc.exe
OCOPY	:= $(PREF)objcopy.exe

HWFLAGS := -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16

INCLUDES := -I$(FWDIR)/Libraries/CMSIS/Include                  \
            -I$(FWDIR)/Libraries/CMSIS/ST/STM32F4xx/Include     \
            -I$(FWDIR)/Libraries/STM32F4xx_StdPeriph_Driver/inc \
            -I.

DEFINES := -DUSE_STDPERIPH_DRIVER

COPT  := -c -O0 -fdata-sections -ffunction-sections \
         $(HWFLAGS) $(INCLUDES) $(DEFINES)

# Don't use := below!
C := ,
LDOPT = -Tstm32_flash.ld $(HWFLAGS) \
       $(patsubst %,-Wl$(C)%,-Map=$@.map --gc-sections)

PERIPH := $(FWDIR)/Libraries/STM32F4xx_StdPeriph_Driver/src

VPATH = $(PERIPH)

PFILES := $(patsubst %,stm32f4xx_%.o,rcc exti gpio syscfg)

OBJDIR := obj

all: $(OBJDIR) a.bin

OBJS := main.o stm32f4_discovery.o misc.o \
       startup_stm32f4xx.o system_stm32f4xx.o $(PFILES) 

a.bin: a.out
	$(OCOPY) -O binary $< $@

a.out: $(patsubst %,$(OBJDIR)/%,$(OBJS))
	$(LD) $(LDOPT) $^ -o $@

$(OBJDIR)/%.o: %.c makefile
	$(CC) $(COPT) $< -o $@

$(OBJDIR)/%.o: %.s makefile
	$(AS) $< -o $@

$(OBJDIR): ; mkdir $@

clean:
	@del /q $(OBJDIR)\*.o
	@del /q a.out

print-%: ; @echo $* = $($*)
