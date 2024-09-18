#   (c) Copyright 2023 NXP
#
#   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
#   in accordance with the applicable license terms.  By expressly accepting
#   such terms or by downloading, installing, activating and/or otherwise using
#   the software, you are agreeing that you have read, and that you agree to
#   comply with and are bound by, such license terms.  If you do not agree to
#   be bound by the applicable license terms, then you may not retain,
#   install, activate or otherwise use the software.
#
#   This file contains sample code only. It is not part of the production code deliverables.
#

##################################################################################################################
#
#                   Makefile to build the elf file   
#
##################################################################################################################
include project_parameters.mk
-include check_build_params.mk

PLATFORM   := S32K3XX
DERIVATIVE := $(EXAMPLE_DERIVATIVE)
DERIVATIVE_LOWER := $(shell echo $(DERIVATIVE) | tr A-Z a-z)
SIM_TYPE := VDK

VDK_INTERFACE :=MCD \$${SNPS_EXTERNAL_DEBUGGERS_HOME}/plugins/MCD/\$${SNPS_EXTERNAL_DEBUGGERS_RUNTIME_64}/snpsMCDplugin.dll
USB_INTERFACE :=USB
FM_INTERFACE :=FM

CONNECTION_INTERFACE := USB_INTERFACE
T32_APP := t32marm.exe


# Get only needed Rte files
find_files = $(wildcard $(PLUGINS_DIR)/Rte_$(AR_PKG_NAME)/src/SchM_$(mod).c)
# Get RTE source files
RTE_FILES_WITH_PATH := $(foreach mod,$(MCAL_MODULE_LIST),$(find_files))
# Get only the file names, path will be added later
RTE_FILES := $(foreach file,$(RTE_FILES_WITH_PATH),$(file:$(PLUGINS_DIR)/Rte_$(AR_PKG_NAME)/src/%=%))

# Compiler for C files, linker, S files
CC             := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe
LD             := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe
AS             := $(GCC_DIR)/bin/arm-none-eabi-gcc.exe

ODIR=out
GDIR=generate
# Path to folders
SRC_DIRS      = src \
                generate/src

INCLUDE_DIRS  = include \
                generate/include


INCLUDE_DIRS+=  $(foreach mod,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/include) \
                $(foreach mod,$(MCAL_MODULE_LIST_ADDON),$(PLUGINS_DIR_ADDON)/$(mod)_$(AR_PKG_NAME_ADDON)/include) \
                $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/startup/include \
                $(PLUGINS_DIR)/Base$(AR_MODULE_ORIGIN)_$(AR_PKG_NAME)/header \
                $(PLUGINS_DIR)/Rte_$(AR_PKG_NAME)/include

INCLUDE_DIRS+=  $(ADDITIONAL_INCLUDE_DIRS)

SRC_DIRS    +=  $(foreach mod,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/src) \
                $(foreach mod,$(MCAL_MODULE_LIST_ADDON),$(PLUGINS_DIR_ADDON)/$(mod)_$(AR_PKG_NAME_ADDON)/src) \
                $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/startup/src \
                $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/startup/src/m7 \
                $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/startup/src/m7/gcc

ifeq ($(LOAD_TO),)
LOAD_TO:=flash
endif

ifeq ($(LOAD_TO),flash)
    LINKER_DEF:= $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/build_files/gcc/linker_flash_$(DERIVATIVE_LOWER).ld
else
    LINKER_DEF:= $(PLUGINS_DIR)/Platform_$(AR_PKG_NAME)/build_files/gcc/linker_ram_$(DERIVATIVE_LOWER).ld
endif

#if compiling/linking into ram
CCOPT += -DSINTRAM
ASOPT += -DSINTRAM
CCOPT += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK \
         -DVV_RESULT_ADDRESS=$(TEST_BASE_ADDR)

MAPFILE = $(ODIR)/$(ELFNAME).map

clib        := $(GCC_DIR)/arm-none-eabi/lib
specs       := nano.specs \
               nosys.specs

# -MT $@ Set the name of the target in the generated dependency file.
# -MMD Generate dependency information as a side-effect of compilation, not instead of compilation.
# -MP Adds a target for each prerequisite in the list, to avoid errors when deleting files.
# -MF Write the generated dependency file to out folder as .d extension
DEP_FLAG =-MT"$(@)" -MMD -MP -MF"$(ODIR)/$(*).d"
################################################################################
# Compiler options
################################################################################
CCOPT 			:=  $(CCOPT) \
                    $(MISRA) \
                    -D$(PLATFORM) \
                    -D$(DERIVATIVE) \
                    -DGCC \
                    $(SUBDERIVATIVE_NAME) \
                    -DEU_DISABLE_ANSILIB_CALLS \
                    -DUSE_SW_VECTOR_MODE \
                    -c \
                    -mcpu=cortex-m7 \
                    -mthumb \
                    -std=c99 \
                    -Os \
                    -mfpu=fpv5-sp-d16 \
                    -mfloat-abi=hard  \
                    -ggdb3 \
                    -mlittle-endian \
                    -Wall \
                    -Wextra \
                    -Wstrict-prototypes \
                    -Wundef \
                    -Wunused \
                    -Werror=implicit-function-declaration \
                    -Wsign-compare \
                    -Wdouble-promotion \
                    -fno-short-enums \
                    -funsigned-char \
                    -funsigned-bitfields \
                    -fomit-frame-pointer \
                    -fno-common \
                    -pedantic \
                    --sysroot="$(clib)" \
                    $(foreach spec, $(specs), -specs=$(spec))


CCOPT           := $(CCOPT) \
                    -DD_CACHE_ENABLE \
                    -DI_CACHE_ENABLE \
                    -DBTB_ENABLE \
                    -DENABLE_FPU \
                    -DMPU_ENABLE

LDOPT           := --entry=Reset_Handler \
                   --sysroot="$(clib)" \
				   $(foreach spec, $(specs), -specs=$(spec)) \
                   -nostartfiles \
				   -mcpu=cortex-m7 \
				   -mthumb \
                   -mfpu=fpv5-sp-d16 \
				   -mfloat-abi=hard  \
				   -ggdb3 \
				   -mlittle-endian \
                   -lc \
                   -lm \
                   -lgcc

ASOPT           :=  $(ASOPT_CORE) \
                    -c \
                    -mthumb \
                    -mcpu=cortex-m7 \
                    -mfpu=fpv5-sp-d16 \
				    -mfloat-abi=hard  \
                    -x assembler-with-cpp
                    
ifneq ($(findstring S32K388, $(DERIVATIVE)),)
    CCOPT += -DCONNECTION_DEVICE_SIM \
             -DSIM_TYPE_$(SIM_TYPE)
	     
    ASOPT += -DCONNECTION_DEVICE_SIM \
             -DSIM_TYPE_$(SIM_TYPE)
    CONNECTION_INTERFACE :=VDK_INTERFACE
endif
# $(addsuffix suffix,names…)  : $(addsuffix .c,foo bar) ->  produces the result ‘foo.c bar.c’
#                             : $(addprefix src/,foo bar) -> produces the result ‘src/foo src/bar’
# Output: -Iinclude -I../include
CFLAGS=$(addprefix -I, $(INCLUDE_DIRS))
# Output: List all path .h files (include/Fls_TestSetup.h include/Platform_Types.h ....)
INCLUDE_FILES := $(foreach DIR, $(INCLUDE_DIRS),$(wildcard $(DIR)/*.h))
# Output: List all .c and .s files (Fls_TestSetup.c exceptions.c Startup.s Vector_core.s)
SOURCE_FILES := $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.c))) $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.s))) $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.S)))
SOURCE_FILES += $(RTE_FILES)
# Add RTE to SRC dirs
SRC_DIRS += $(PLUGINS_DIR)/Rte_$(AR_PKG_NAME)/src/
# Object files
OUT_FILES := $(SOURCE_FILES:.c=.o)
OUT_FILES += $(SOURCE_FILES:.s=.o)
OUT_FILES += $(SOURCE_FILES:.S=.o)

winpath = $(foreach WINPATH_ITEM,$(1),$(patsubst /cygdrive/$(word 2,$(subst /, , $(WINPATH_ITEM)))%,$(word 2,$(subst /, ,$(WINPATH_ITEM))):%,$(WINPATH_ITEM)))
ifeq ($(realpath /),)
my_realpath = $1
my_abspath = $1
else
my_realpath = $(realpath $1)
my_abspath = $(abspath $1)
endif

## Testing to check whether it is a Windows environment or an Unix like
## one. This test is based on 'uname' command call. If the shell is a Windows one
## with no GNU binutils or similar tools, the command will raise a CreateProcess
## error but the makefile will detect the correct environment and work as expected.

SEPARATOR=======================================================================
UNAME_CMD:=uname
OS_DETECTED:=$(shell $(UNAME_CMD))
mkdir_message:=Creating directory for object files
clean_message:=Removing files and directories from the compliation output
clean_all_message:=Removing files and directories from the compliation output and for the generation output

ifeq ($(OS_DETECTED), )
mkdir=mkdir_windows
clean_target=clean_windows
clean_all_target=clean_all_windows
env_predetection_msg=Checked for '$(UNAME_CMD)', not found
env_detected_msg=Assuming Windows environment
else
mkdir=mkdir_linux
clean_target=clean_linux
clean_all_target=clean_all_linux
env_predetection_msg=Checked for '$(UNAME_CMD)', found: $(OS_DETECTED)
env_detected_msg=Assuming Unix like environment
endif
SAMPLE_APP_DBG_DIR:=$(call winpath,$(CURDIR))/debug
## Targets ##

.PHONY: mkdir_windows
mkdir_windows:
	@echo $(SEPARATOR)
	@echo $(mkdir_message)
	@mkdir $(ODIR) || @echo Directory already exists

.PHONY: mkdir_linux
mkdir_linux:
	@echo $(SEPARATOR)
	@echo $(mkdir_message)
	@mkdir -p $(ODIR)

.PHONY: clean_windows
clean_windows:
	@echo $(SEPARATOR)
	@echo $(clean_message)
	@rmdir /s /q $(ODIR) || @echo Directory already cleaned

.PHONY: clean_linux
clean_linux:
	@echo $(SEPARATOR)
	@echo $(clean_message)
	@rm -fr $(ODIR)

.PHONY: clean_all_windows
clean_all_windows:
	@echo $(SEPARATOR)
	@echo $(clean_all_message)
	@rmdir /s /q $(ODIR) || @echo Directory already cleaned
	@rmdir /s /q $(GDIR) || @echo Directory already cleaned

.PHONY: clean_all_linux
clean_all_linux:
	@echo $(SEPARATOR)
	@echo $(clean_all_message)
	@rm -fr $(ODIR)
	@rm -fr $(GDIR)

.PHONY: generate
generate:
	$(TRESOS_DIR)/bin/tresos_cmd.bat  deleteProject $(TRESOS_PROJECT_NAME) || exit 0 2>&1
	$(TRESOS_DIR)/bin/tresos_cmd.bat  importProject $(call winpath, $(call my_abspath, ./TresosProject/$(TRESOS_PROJECT_NAME))) 2>&1
ifeq ($(VARIANT_NO),0) 
	$(TRESOS_DIR)/bin/tresos_cmd.bat generate $(TRESOS_PROJECT_NAME) 2>&1
else
	$(TRESOS_DIR)/bin/tresos_cmd.bat  autoconfigure $(TRESOS_PROJECT_NAME) GenerateAllVariants 2>&1
endif

.PHONY: build
build: $(ELFNAME).elf

$(ELFNAME).elf : $(OUT_FILES)
#add path for .o and .c filer to easy to automatically look up in sub folder
vpath %.c $(SRC_DIRS)
vpath %.o $(ODIR)
#add the rule to check if ODIR has been already created before start but we do want to rebuild .o so ODIR is added as order-only-prerequisites
%.o: %.c | $(ODIR)
	@echo "Compiling $<"
    # The -c flag says to generate the object file, the -o $@ says to put the output of the compilation in the
    # file named on the left side of the :, the $< is the first item in the dependencies list and the CFLAGS macro is defined as above.
	@$(CC) $(CCOPT) -c -o $(ODIR)/$@ $< $(CFLAGS) $(DEP_FLAG)
$(ODIR): $(mkdir)
vpath %.s $(addsuffix :, $(SRC_DIRS))
vpath %.S $(addsuffix :, $(SRC_DIRS))
%.o : %.s
	@echo "Compiling $<"
	@$(AS) $(ASOPT) $< -o $(ODIR)/$@ $(DEP_FLAG)
%.o : %.S
	@echo "Compiling $<"
	@$(AS) $(ASOPT) $< -o $(ODIR)/$@ $(DEP_FLAG)
# Link all the object files to become one elf file
%.elf: %.o $(LINKER_DEF)
	@echo "Linking $@"
	@$(LD) -Wl,-Map,"$(MAPFILE)" $(LDOPT) -T $(LINKER_DEF) $(ODIR)/*.o -o $(ODIR)/$@
#include new .d files which contain new rule created from gcc auto-depend generation
-include $(wildcard $(ODIR)/*.d)
.PHONY: clean_all
clean_all: $(clean_all_target)

.PHONY: clean
clean: $(clean_target)
    
.PHONY: run
run:
	@echo "For running from command line sed is needed for replacing strings in config.t32 and run.cmm, otherwise the run.cmm ca be ran directly from T32"
	@sed -i 's/replace_t32_dir/$(subst /,\/,$(T32_DIR))/g' debug/config.t32
	@if [ ! -f $(T32_DIR)/target_device.t32 ]; then sed -i 's/\$$INCLUDE target_device.t32/ /g' debug/config.t32; fi;
	@sed -i 's/DO device.cmm/DO debug\/device.cmm/g' debug/run.cmm
	@sed -i 's/\.\.\/out/.\/out/g' debug/run.cmm
	@sed -i 's/replace_loadto/$(LOAD_TO)/g' debug/run.cmm
	@echo "CONNECTION_INTERFACE is " $(CONNECTION_INTERFACE)
	@sed -i.bak 's|replace_pbilinea||g' debug/config.t32
	@sed -i 's|replace_pbilineb|USB|g' debug/config.t32
	@sed -i 's|replace_pbilinec|CONNECTIONMODE\=AUTOCONNECT|g' debug/config.t32
	$(T32_DIR)/bin/windows64/t32marm.exe -c debug/config.t32 -s debug/run.cmm || true
	@cat debug/config.t32.bak > debug/config.t32
	@sed -i 's/$(LOAD_TO)/replace_loadto/g' debug/run.cmm
	@sed -i 's/debug\/device.cmm/device.cmm/g' debug/run.cmm
	@sed -i 's/\.\/out/..\/out/g' debug/run.cmm

.PHONY: test
test:
	@sed -i 's/replace_t32_dir/$(subst /,\/,$(T32_DIR))/g' debug/config.t32
	@sed -i 's/replace_loadto/$(LOAD_TO)/g' debug/test.cmm
	if [ ! -f $(T32_DIR)/target_device.t32 ]; then sed -i 's/\$$INCLUDE target_device.t32/ /g' debug/config.t32; fi;
	@echo "CONNECTION_INTERFACE is " $(CONNECTION_INTERFACE)
	@sed -i.bak 's|replace_pbilinea||g' debug/config.t32
	@sed -i 's|replace_pbilineb|USB|g' debug/config.t32
	@sed -i 's|replace_pbilinec|CONNECTIONMODE\=AUTOCONNECT|g' debug/config.t32
	$(T32_DIR)/bin/windows64/t32marm.exe -c debug/config.t32 -s debug/test.cmm || true
	@cat debug/config.t32.bak > debug/config.t32

.PHONY: run_sim
run_sim: | $(ODIR)
	@echo "For running from command line sed is needed for replacing strings in config.t32 and run.cmm, otherwise the run.cmm ca be ran directly from T32"
	@echo "SAMPLE_APP_DBG_DIR is " $(SAMPLE_APP_DBG_DIR)
	@sed -i 's/replace_t32_dir/$(subst /,\/,$(T32_DIR))/g' debug/config.t32
	@echo "CONNECTION_INTERFACE is " $(CONNECTION_INTERFACE)
	@sed -i.bak 's|replace_pbilinea|$(subst /,\/,$(VDK_INTERFACE))|g' debug/config.t32
	@sed -i 's|replace_pbilineb||g' debug/config.t32
	@sed -i 's|replace_pbilinec||g' debug/config.t32
	@if [ ! -f $(T32_DIR)/target_device.t32 ]; then sed -i 's/\$$INCLUDE target_device.t32/ /g' debug/config.t32; fi;
	@sed -i 's/DO device.cmm/DO $(subst /,\/,$(call winpath,$(CURDIR)))\/debug\/device.cmm/g' debug/run.cmm
	@sed -i 's/\.\.\/out/$(subst /,\/,$(call winpath,$(CURDIR)))\/out/g' debug/run.cmm
	debug/start.bat run $(T32_APP) $(T32_DIR) $(VDK_DIR) $(VDK_TEMPLATE_NAME) $(VDK_TEMPLATE_VERSION) $(VDK_VPCONFIG_NAME) $(SAMPLE_APP_DBG_DIR) || true
	@cat debug/config.t32.bak > debug/config.t32
	@sed -i 's/DO $(subst /,\/,$(call winpath,$(CURDIR)))\/debug\/device.cmm/DO device.cmm/g' debug/run.cmm
	@sed -i 's/$(subst /,\/,$(call winpath,$(CURDIR)))\/out/\.\.\/out/g' debug/run.cmm

.PHONY: test_sim
test_sim:
	@sed -i 's/replace_t32_dir/$(subst /,\/,$(T32_DIR))/g' debug/config.t32

	@sed -i 's/TEST_BASE_ADDR/$(TEST_BASE_ADDR)/g' debug/test.cmm
	@sed -i 's/TEST_BLOCK_SIZE/$(TEST_BLOCK_SIZE)/g' debug/test.cmm
	if [ ! -f $(T32_DIR)/target_device.t32 ]; then sed -i 's/\$$INCLUDE target_device.t32/ /g' debug/config.t32; fi;
	@echo "CONNECTION_INTERFACE is " $(CONNECTION_INTERFACE)
	@sed -i.bak 's|replace_pbilinea|$(subst /,\/,$(VDK_INTERFACE))|g' debug/config.t32
	@sed -i 's|replace_pbilineb||g' debug/config.t32
	@sed -i 's|replace_pbilinec||g' debug/config.t32
	debug/start.bat test $(T32_APP) $(T32_DIR) $(VDK_DIR) $(VDK_TEMPLATE_NAME) $(VDK_TEMPLATE_VERSION) $(VDK_VPCONFIG_NAME) $(SAMPLE_APP_DBG_DIR) || true
	@cat debug/config.t32.bak > debug/config.t32