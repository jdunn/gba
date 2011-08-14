# --- Project Settings
PRODUCT_NAME       = template
SOURCES            = main.c lib.c

# --- System Settings
DKPATH             = ~/Desktop/devkitARM/bin
MGPATH             = /usr/bin
VBASIM             = VisualBoyAdvance

ifndef DEBUG
# ============ RELEASE MODE
# --- File Names
ELF_NAME           = $(PRODUCT_NAME).elf
ROM_NAME           = $(PRODUCT_NAME).gba

# --- GBA Settings
MODEL              = -mthumb-interwork -mthumb
SPECS              = -specs=gba_mb.specs

# --- Archiver
AS                 = $(DKPATH)/arm-eabi-as
ASFLAGS            = -mthumb-interwork

# --- Compiler
CC                 = $(DKPATH)/arm-eabi-gcc
CFLAGS             = $(MODEL) -O2 -Wall

# --- Linker
LD                 = $(DKPATH)/arm-eabi-gcc
LDFLAGS            = $(SPECS) $(MODEL)

# --- Object/Executable Packager
OBJCOPY            = $(DKPATH)/arm-eabi-objcopy
OBJCOPYFLAGS       = -O binary

# --- ROM Fixer
GBAFIX             = $(DKPATH)/gbafix

# --- Delete
RM                 = rm

OBJECTS = $(SOURCES:.c=.o)

# --- Main build target
all : build

run : build
	$(VBASIM) $(ROM_NAME)

build : $(ROM_NAME)

# --- Build .elf file into .gba ROM file
$(ROM_NAME) : $(ELF_NAME)
	$(OBJCOPY) $(OBJCOPYFLAGS) $(ELF_NAME) $(ROM_NAME)
	$(GBAFIX) $(ROM_NAME)
	
# --- Build .o files into .elf file
$(ELF_NAME) : $(OBJECTS)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $@

# -- Build .c files into .o files
$(OBJECTS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(ROM_NAME)
	$(RM) $(ELF_NAME)
	$(RM) *.o


# ============ RELEASE MODE
else
# ============ DEBUG MODE
# --- File Names
BIN_NAME           = $(PRODUCT_NAME)

# --- Compiler
CC                 = $(MGPATH)/gcc
CFLAGS             = -D_DEBUG -Wall -ggdb

all : build

run : build
	./$(BIN_NAME)

build : $(BIN_NAME)

$(BIN_NAME) : $(SOURCES)
	$(CC) -o $(BIN_NAME) $(CFLAGS) $(SOURCES)

clean :
	$(RM) $(BIN_NAME)

# ============ DEBUG MODE
endif
