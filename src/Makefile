# linuxaldl Makefile

CC = gcc
CFLAGS = -g -Wall -Wno-unused `pkg-config --cflags gtk+-2.0`

V = @

HEADERS = linuxaldl_definitions.h linuxaldl_gui.h linuxaldl.h sts_serial.h

all: linuxaldl

%.o: %.c $(HEADERS)
	@echo + cc $@
	$(V)$(CC) $(CFLAGS) -c $<

linuxaldl: linuxaldl.o linuxaldl_gui.o sts_serial.o
	@echo + link main
	$(V)$(CC) $(CFLAGS) -lpopt `pkg-config --libs gtk+-2.0` -o ../bin/$@ linuxaldl.o linuxaldl_gui.o sts_serial.o

clean:
	@echo + clean
	$(V)rm -rf *.o ../bin/linuxaldl
