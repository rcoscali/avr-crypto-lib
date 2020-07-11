MAKE_DEBUG     = 1

DEBUG          = -gdwarf-2
WALMOSTALL 	= -Waddress -Warray-bounds=1 -Wbool-compare -Wbool-operation \
		  -Wchar-subscripts -Wcomment -Wenum-compare -Wformat -Wint-in-bool-context -Wimplicit -Wimplicit-int \
		  -Wimplicit-function-declaration -Winit-self -Wlogical-not-parentheses -Wmain -Wmaybe-uninitialized \
		  -Wmemset-elt-size -Wmemset-transposed-args -Wmisleading-indentation -Wmissing-braces -Wno-attributes \
		  -Wnarrowing -Wnonnull -Wnonnull-compare -Wopenmp-simd -Wparentheses -Wno-pointer-sign \
		  -Wpointer-sign -Wrestrict -Wreturn-type -Wsequence-point -Wsign-compare \
		  -Wsizeof-pointer-memaccess -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch -Wtautological-compare -Wtrigraphs \
		  -Wuninitialized -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-value -Wunused-variable \
		  -Wvolatile-register-var
WARNING        = -pedantic $(WALMOSTALL) -Werror -Wunused-macros -Wduplicate-decl-specifier -Wno-error -Wstrict-prototypes
PROGRAMMER     = wiring
PROG_PORT      = usb
FLASHCMD       = avrdude -p $(MCU_TARGET) -P $(PROG_PORT) -c $(PROGRAMMER) -U flash:w:# no space at the end
#FLASHCMD       = avrdude -p $(MCU_TARGET) -c usbasp -U flash:w:# no space at the end
#RESETCMD       = avrdude -p $(MCU_TARGET) -P $(PROG_PORT) -c $(PROGRAMMER) 
RESETCMD       = avarice -2 -R -j usb
DEP_DIR        = deps/$(BOARD_NAME)/#
TEST_DIR       = test/#
BIN_DIR        = bin/$(BOARD_NAME)/#
TESTSRC_DIR    = test_src/
#uisp -dprog=bsd -dlpt=/dev/parport1 --upload if=$(PRG).hex
ERASECMD       =
TESTPORT       = /dev/ttyUSB0
TESTPORTBAUDR  = 115200
TESTLOG_DIR    = testlog/#
TESTPREFIX     = nessie-
SPEEDTOOL      = host/get_performance.rb
SPEEDLOG_DIR   = speed_log/$(BOARD_NAME)/#
SPEEDPREFIX    =
SPEEDCMD       = performance
SIZE_DIR       = size_log/$(BOARD_NAME)/#
LIST_DIR       = listings/$(BOARD_NAME)/#
LIST_OPT       = -Wa,-adghlms -g
STAT_DIR       = stats/$(BOARD_NAME)/#
CC	       = avr-gcc
CSTD           = gnu99

SIZESTAT_FILE = sizestats.txt

OBJCOPY         = avr-objcopy
OBJDUMP         = avr-objdump
SIZE            = avr-size
READELF         = readelf
HASH_TOOL       = sha256sum
RUBY            = ruby
GET_TEST        = host/get_test.rb
MAKE            = make
MAKE2GRAPH      = ~/bin/make2graph.rb
TWOPI           = twopi
