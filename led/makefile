
FWDIR=D:/progs/stm32f4discovery/STM32F4-Discovery_FW_V1.1.0

PREF := arm-none-eabi-
CC := $(PREF)gcc.exe
AS := $(PREF)as.exe
LD := $(PREF)gcc.exe

HWFLAGS := -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
INCLUDES := -I$(FWDIR)/Libraries/CMSIS/Include -I$(FWDIR)/Libraries/CMSIS/ST/STM32F4xx/Include \
       -I$(FWDIR)/Libraries/STM32F4xx_StdPeriph_Driver/inc -I.
DEFINES := -DUSE_STDPERIPH_DRIVER

COPT  := -c -O0 $(HWFLAGS) $(INCLUDES) $(DEFINES)
LDOPT := -Tstm32_flash.ld

PERIPH := $(FWDIR)/Libraries/STM32F4xx_StdPeriph_Driver/src

VPATH = $(PERIPH)

PFILES := $(patsubst %,stm32f4xx_%.o,rcc exti gpio syscfg)

OBJDIR := obj

all: $(OBJDIR) a.out

OBJS := main.o stm32f4_discovery.o $(PFILES) misc.o startup_stm32f4xx.o system_stm32f4xx.o

a.out: $(patsubst %,$(OBJDIR)/%,$(OBJS))
	$(LD) $(LDOPT) $^ -o $@ -mfloat-abi=hard

$(OBJDIR)/%.o: %.c makefile
	$(CC) $(COPT) $< -o $@

$(OBJDIR)/%.o: %.s makefile
	$(AS) $< -o $@

$(OBJDIR): ; mkdir $@

clean:
	@del /q $(OBJDIR)/*.o
	@del /q a.out

print-%: ; @echo $* = $($*)
