PROGNAME = blinky

CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
CP = arm-none-eabi-objcopy
RM = rm -rf

OBJDIR = build
DEPDIR = .deps

SRCS  = $(wildcard app/src/*.c)
SRCS += $(wildcard bsp/src/*.c)
SRCS += $(wildcard hal/src/*.c)
SRCS += $(wildcard stm32/src/*.c)
SRCS += $(wildcard *.c)

OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
$(shell mkdir -p $(dir $(OBJS)) &> /dev/null)

DEPS = $(patsubst %.c, $(DEPDIR)/%.d, $(SRCS))
$(shell mkdir -p $(dir $(DEPS)) &> /dev/null)

CFLAGS = -g -mcpu=cortex-m4 -mthumb -Wall -O0 -Istm32/inc -Ihal/inc -Ibsp/inc -Iapp/inc
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d
LFLAGS = -nostdlib -T stm32f411-rom.ld

all: $(PROGNAME).elf

$(PROGNAME).elf: $(OBJS)
	$(LD) $(LFLAGS) $^ -o $@
	$(CP) -O binary $(PROGNAME).elf $(PROGNAME).bin

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(CC) -c $(CFLAGS) $(DEPFLAGS) $< -o $@

$(DEPS):

include $(DEPS)

clean:
	$(RM) $(OBJDIR) $(DEPDIR) $(PROGNAME).elf $(PROGNAME).bin

