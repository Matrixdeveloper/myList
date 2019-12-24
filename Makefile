# FakeCode, YueWeng, Dec23, 2019
# makefile for list 

# ENV
OS := $(shell uname)
HOME := $(shell pwd)
OBJDIR:= $(HOME)/build/obj

# Compile settings
CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu99 -Wall -pedantic


ifeq ($(OS), Darwin)
testfile: $(OBJDIR)/mytestlist.o
	$(CC) $(CFLAGS) -o $@ $<

else
	$(shell echo "This is " $(OS))

endif

$(OBJDIR)/mytestlist.o: mytestlist.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $? -o $@

.PHONY: all clean

clean:
	rm -rf build testfile