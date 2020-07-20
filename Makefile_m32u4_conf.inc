
MCU_TARGET     = atmega32u4
F_CPU          = 16000000
OPTIMIZE       = -Os # -Os
EXTRALINK      = 
DEFS           = -D$(call uc, $(MCU_TARGET)) -DF_CPU=$(F_CPU)
BOARD_NAME     = mega

override CFLAGS_A	= -MMD -MF$(DEP_DIR)$(patsubst %.o,%.d,$(notdir $(1))) $(DEBUG) $(WARNING) -std=$(CSTD) $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override CFLAGS 	= -MMD -MF$(DEP_DIR)$(patsubst %.o,%.d,$(notdir $@))   $(DEBUG) $(WARNING) -std=$(CSTD) $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)

override LDFLAGS        = -gdwarf-2 -Wl,-Map,
override ASFLAGS	= -mmcu=$(MCU_TARGET) -Wa,--gdwarf-2

PROGRAMMER     = wiring
PROG_PORT      = /dev/ttyUSB0
DEFS           = -D$(call uc, $(MCU_TARGET)) -DF_CPU=$(F_CPU)
FLASHCMD       = avrdude -C./bin/avrdude/etc/avrdude.conf -v -p$(MCU_TARGET) -P$(PROG_PORT) -c$(PROGRAMMER) -D -Uflash:w:\$(PRG).hex:1
RESETCMD       = avrdude -C./bin/avrdude/etc/avrdude.conf -v -p$(MCU_TARGET) -P$(PROG_PORT) -c$(PROGRAMMER)
