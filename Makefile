BASENAME  = dkr
REGION  := us
VERSION  := v77
NON_MATCHING ?= 0

LIBULTRA_VERSION_DEFINE := -DBUILD_VERSION=4 -DBUILD_VERSION_STRING=\"2.0G\"

# Whether to hide commands or not
VERBOSE ?= 0
ifeq ($(VERBOSE),0)
  V := @
endif

PRINT = printf
GREP  = grep -rl

# Colors

# Whether to colorize build messages
COLOR ?= 1
GCC_COLOR := -fno-diagnostics-color

ifeq ($(COLOR),1)
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
PINK    := \033[0;35m
CYAN    := \033[0;36m
COLORIZE := -c
GCC_COLOR :=
endif

# Common build print status function
define print
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

# Directories
BIN_DIRS  = assets
BUILD_DIR = build
SRC_DIR   = src
LIBULTRA_DIR = libultra
ASM_DIRS  = asm asm/data asm/nonmatchings
HASM_DIRS = $(SRC_DIR)/hasm $(LIBULTRA_DIR)/src/os $(LIBULTRA_DIR)/src/gu $(LIBULTRA_DIR)/src/libc
LIBULTRA_SRC_DIRS  = $(LIBULTRA_DIR) $(LIBULTRA_DIR)/src $(LIBULTRA_DIR)/src/audio $(LIBULTRA_DIR)/src/audio/mips1 
LIBULTRA_SRC_DIRS += $(LIBULTRA_DIR)/src/debug $(LIBULTRA_DIR)/src/gu $(LIBULTRA_DIR)/src/io
LIBULTRA_SRC_DIRS += $(LIBULTRA_DIR)/src/libc $(LIBULTRA_DIR)/src/os $(LIBULTRA_DIR)/src/sc

# Files requiring pre/post-processing
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null 2>/dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file).o)

SRC_DIRS = $(SRC_DIR) $(LIBULTRA_SRC_DIRS)
SYMBOLS_DIR = ver/symbols

TOOLS_DIR = tools

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	$(error Native Windows is currently unsupported for building this repository, use WSL instead c:)
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
endif

RECOMP_DIR := $(TOOLS_DIR)/ido-recomp/$(DETECTED_OS)

# Files

S_FILES         = $(foreach dir,$(ASM_DIRS) $(HASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES         = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
BIN_FILES       = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file).o)


find-command = $(shell which $(1) 2>/dev/null)

# Tools

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips64-linux-gnu-
else
  CROSS := mips64-elf-
endif

AS       = $(CROSS)as
CPP      = cpp
LD       = $(CROSS)ld
OBJCOPY  = $(CROSS)objcopy
VENV     = .venv
PYTHON   = $(VENV)/bin/python3
GCC      = gcc

XGCC     = mips64-elf-gcc

#Options
CC       = $(RECOMP_DIR)/cc
SPLAT    ?= $(PYTHON) -m splat split
CRC      = $(TOOLS_DIR)/n64crc $(BUILD_DIR)/$(BASENAME).$(REGION).$(VERSION).z64 $(COLORIZE)
FIXCHECKSUMS = $(PYTHON) $(TOOLS_DIR)/calc_func_checksums.py $(REGION) $(VERSION)

OPT_FLAGS      = -O2

MIPSISET       = -mips1

DEFINES := _FINALROM NDEBUG TARGET_N64 F3DDKR_GBI
DEFINES += VERSION_$(REGION)_$(VERSION)

VERIFY = verify

ifeq ($(NON_MATCHING),1)
	DEFINES += NON_MATCHING
	DEFINES += AVOID_UB
	VERIFY = no_verify
else
	DEFINES += ANTI_TAMPER
endif

C_DEFINES := $(foreach d,$(DEFINES),-D$(d)) $(LIBULTRA_VERSION_DEFINE) -D_MIPS_SZLONG=32
ASM_DEFINES = --defsym _MIPS_SIM=1 --defsym mips=1

INCLUDE_CFLAGS  = -I . -I include -I include/libc  -I include/PR -I include/sys -I $(BIN_DIRS) -I $(SRC_DIR) -I $(LIBULTRA_DIR)
INCLUDE_CFLAGS += -I $(LIBULTRA_DIR)/src/gu -I $(LIBULTRA_DIR)/src/libc -I $(LIBULTRA_DIR)/src/io  -I $(LIBULTRA_DIR)/src/sc 
INCLUDE_CFLAGS += -I $(LIBULTRA_DIR)/src/audio -I $(LIBULTRA_DIR)/src/os

ASFLAGS        = -march=vr4300 -32 -G0 $(ASM_DEFINES) $(INCLUDE_CFLAGS)
OBJCOPYFLAGS   = -O binary

#IDO Warnings to Ignore. These are coding style warnings we don't follow
CC_WARNINGS := -fullwarn -Xfullwarn -woff 838,649,624

CFLAGS := -G 0 -non_shared -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul
CFLAGS += $(C_DEFINES)
CFLAGS += $(INCLUDE_CFLAGS)

CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unknown-pragmas -Wunused-function -Wno-unused-parameter -Werror-implicit-function-declaration
CHECK_WARNINGS += -Werror-implicit-function-declaration -Wno-unused-variable -Wno-missing-braces -Wno-int-conversion -Wno-main
CHECK_WARNINGS += -Wno-builtin-declaration-mismatch -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-switch
# Disable GCC complaining about fakematches necessary to match if building a matching ROM. Example: "var2 = (0, var1)"
ifeq ($(NON_MATCHING),0)
	CHECK_WARNINGS += -Wno-unused-value
endif
CC_CHECK := $(GCC) -fsyntax-only -fno-builtin -funsigned-char -std=gnu90 -m32 -D_LANGUAGE_C -DNON_MATCHING -DNON_EQUIVALENT $(CHECK_WARNINGS) $(INCLUDE_CFLAGS) $(C_DEFINES) $(GCC_COLOR)

TARGET     = $(BUILD_DIR)/$(BASENAME).$(REGION).$(VERSION)
LD_SCRIPT  = ver/$(BASENAME).$(REGION).$(VERSION).ld

LD_FLAGS   = -T $(LD_SCRIPT) -T $(SYMBOLS_DIR)/undefined_syms.txt -Map $(TARGET).map

ASM_PROCESSOR_DIR := $(TOOLS_DIR)/asm-processor
ASM_PROCESSOR      = $(PYTHON) $(ASM_PROCESSOR_DIR)/build.py

### Optimisation Overrides
####################### LIBULTRA #########################

$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: OPT_FLAGS := -O2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/%.c.o: OPT_FLAGS := -O3
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/mips1/%.c.o: OPT_FLAGS := -O2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/os/%.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/%.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/vimgr.c.o: OPT_FLAGS := -O2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/pimgr.c.o: OPT_FLAGS := -O2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/motor.c.o: OPT_FLAGS := -O2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xprintf.c.o : OPT_FLAGS := -O3
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/env.c.o: OPT_FLAGS := -g
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: MIPSISET := -mips3 -32
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: MIPSISET := -mips3 -32
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ldiv.c.o: OPT_FLAGS := -O3
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ldiv.c.o: MIPSISET := -mips2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xldtob.c.o: OPT_FLAGS := -O3
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xldtob.c.o: MIPSISET := -mips2

$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: MIPSISET := -mips2
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/mips1/%.c.o: MIPSISET := -mips1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/pimgr.c.o: MIPSISET := -mips1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/sc/sched.c.o: MIPSISET := -mips1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/motor.c.o: MIPSISET := -mips1
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/env.c.o: MIPSISET := -mips1

#Ignore warnings for libultra files
$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: CC_WARNINGS := -w
$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: CC_CHECK := :

### Targets

default: all

all: $(VERIFY)

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(HASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

verify: $(TARGET).z64
	$(V)$(FIXCHECKSUMS)
	$(V)$(CRC)
ifeq ($(NON_MATCHING),0)
	@(sha1sum -c --quiet ver/verification/$(BASENAME).$(REGION).$(VERSION).sha1 \
	&& $(PRINT) "$(GREEN)Verify:$(NO_COL)\
	 $(YELLOW)OK$(NO_COL)\n")
	$(V)$(PRINT) "$(YELLOW)    __\n .\`_  _\`.\n| | \`| | |\n| |_|._| |\n \`. __ .\'$(NO_COL)\n\n"
else
	$(V)$(PRINT) "$(GREEN)Build Complete!$(NO_COL)\n"
endif

no_verify: $(TARGET).z64
	$(V)$(PRINT) "$(GREEN)Build Complete!$(NO_COL)\n"

extract:
	$(SPLAT) ver/splat/$(BASENAME).$(REGION).$(VERSION).yaml
#These are the only 3 jpn region functions that match elsewhere, but not for this region. As a temp hack for progrss script reasons, just delete these for other regions.
ifneq ($(REGION),jpn)
	@$(RM) asm/nonmatchings/menu/savemenu_render_element.s asm/nonmatchings/menu/pakmenu_render.s asm/nonmatchings/menu/results_render.s
endif	

extractall:
	$(SPLAT) ver/splat/$(BASENAME).us.v77.yaml
	$(SPLAT) ver/splat/$(BASENAME).pal.v77.yaml
	$(SPLAT) ver/splat/$(BASENAME).jpn.v79.yaml
	$(SPLAT) ver/splat/$(BASENAME).us.v80.yaml
	$(SPLAT) ver/splat/$(BASENAME).pal.v80.yaml

dependencies:
#Set up a python venv so we don't get warnings about breaking system packages.
	$(V)python3 -m venv $(VENV)
#Installing the splat dependencies
	$(V)$(PYTHON) -m pip install -r requirements.txt
	$(V)$(PYTHON) ver/splat/update_baserom_names.py
	$(V)make -C $(TOOLS_DIR)

clean:
	rm -rf $(BUILD_DIR)
	
cleanall:
	rm -rf $(BUILD_DIR)

distclean: clean
	rm -rf $(ASM_DIRS)
	rm -rf $(BIN_DIRS)
	rm -f $(SYMBOLS_DIR)/*auto.$(REGION).$(VERSION).txt
	rm -f $(LD_SCRIPT)

distcleanall: cleanall
	rm -rf asm
	rm -rf assets
	rm -f $(SYMBOLS_DIR)/*auto.*.txt
	rm -f ver/dkr.us.v77.ld
	rm -f ver/dkr.us.v80.ld
	rm -f ver/dkr.pal.v77.ld
	rm -f ver/dkr.pal.v80.ld
	rm -f ver/dkr.jpn.v79.ld
	rm -f $(SYMBOLS_DIR)/*auto.us.v77.txt
	rm -f $(SYMBOLS_DIR)/*auto.pal.v77.txt
	rm -f $(SYMBOLS_DIR)/*auto.jpn.v79.txt
	rm -f $(SYMBOLS_DIR)/*auto.us.v80.txt
	rm -f $(SYMBOLS_DIR)/*auto.pal.v80.txt

#When you just need to wipe old symbol names and re-extract
cleanextract: distclean extract

#Put the build folder into expected for use with asm-differ. Only run this with a matching build.
expected: verify
	mkdir -p expected
	rm -rf expected/$(BUILD_DIR)
	cp -r $(BUILD_DIR)/ expected/

### Recipes

$(GLOBAL_ASM_O_FILES): CC := $(ASM_PROCESSOR) $(CC) -- $(AS) $(ASFLAGS) --

$(TARGET).elf: dirs $(LD_SCRIPT) $(O_FILES)
	@$(PRINT) "$(GREEN)Linking: $(BLUE)$@$(NO_COL)\n"
	$(V)$(LD) $(LD_FLAGS) -o $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.c.o: %.c
	$(call print,Compiling:,$<,$@)
	$(V)$(CC_CHECK) $<
	$(V)$(CC) -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
endif

# non asm-processor recipe
$(BUILD_DIR)/%.c.o: %.c
	$(call print,Compiling:,$<,$@)
	$(V)$(CC_CHECK) $<
	$(V)$(CC) -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<

$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: $(LIBULTRA_DIR)/src/libc/llcvt.c
	$(call print,Compiling mips3:,$<,$@)
	@$(CC)  -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
	$(V)$(PYTHON) tools/patchmips3.py $@ || rm $@

$(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: $(LIBULTRA_DIR)/src/libc/ll.c
	$(call print,Compiling mips3:,$<,$@)
	@$(CC)  -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
	$(V)$(PYTHON) tools/patchmips3.py $@ || rm $@

$(BUILD_DIR)/%.s.o: %.s
	$(call print,Assembling:,$<,$@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(call print,Linking Binary:,$<,$@)
	$(V)$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(call print,Objcopy:,$<,$@)
	$(V)$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	$(call print,CopyRom:,$<,$@)
	$(V)$(TOOLS_DIR)/CopyRom.py $< $@

### Settings
.PHONY: all clean cleanextract default
SHELL = /bin/bash -e -o pipefail
