CWD         := $(CURDIR)
ARCH_DIR    := $(CWD)
BOOT_DIR    := $(CWD)/boot

CFLAGS      += -mno-sse #-mno-mmx

include $(BOOT_DIR)/makefile.mk
OBJECTS += \
	$(addprefix $(BOOT_DIR)/, $(BOOT_ASM_SOURCES:.S=.o)) \
	$(addprefix $(BOOT_DIR)/, $(BOOT_C_SOURCES:.c=.o))

include $(ARCH_DIR)/makefile.mk
OBJECTS += \
	$(addprefix $(ARCH_DIR)/, $(ARCH_ASM_SOURCES:.S=.o)) \
	$(addprefix $(ARCH_DIR)/, $(ARCH_C_SOURCES:.c=.o))

include ../../common.mk

image: $(OBJECTS) $(LINK_SCRIPT)
	$(LD) $(LFLAGS) $(OBJECTS) -T $(LINK_SCRIPT) -o $@
	$(OBJCOPY) --only-keep-debug $@ image.sym
	$(OBJCOPY) --strip-debug $@

.PHONY: clean
clean:
	rm -f *.o *.d $(BOOT_DIR)/*.o $(BOOT_DIR)/*.d image image.sym
