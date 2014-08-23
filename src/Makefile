#
# Makefile
#
# Copyright (C) 2013 Alexander Boldyrev
#

BLUE:=\e[0;34m
MAGENTA:=\e[0;35m
GREEN:=\e[0;32m
CYAN:=\e[0;36m
RED:=\e[0;31m
ENDCOLOR:=\e[0m

ECHO=/bin/echo -e
CC=@$(ECHO) "[COMPILE] $(MAGENTA)$?$(ENDCOLOR) -> $(CYAN)$@$(ENDCOLOR)" && gcc
CPP=@$(ECHO) "[COMPILE] $(MAGENTA)$?$(ENDCOLOR) -> $(CYAN)$@$(ENDCOLOR)" && g++
LD=@$(ECHO) "[LINK] $(MAGENTA)$?$(ENDCOLOR) -> $(CYAN)$@$(ENDCOLOR)" && gcc
RM=rm


SDL2_INCDIR=-I/opt/SDL2/include
SDL2_LIBDIR=-L/opt/SDL2/lib


CFLAGS=--std=c++11 $(SDL2_INCDIR)
LDFLAGS=-lSDL2 -lGL -lGLEW $(SDL2_LIBDIR)


BUILDDIR=build
BINDIR=bin


SRCDIR_RES=res
SRCDIR_VIDEO=video


OBJECTS=$(BUILDDIR)/resource-manager.o\
		$(BUILDDIR)/native-fs.o\
		$(BUILDDIR)/tga-decoder.o\
		$(BUILDDIR)/gl-video-context.o\
		$(BUILDDIR)/entry.o

GENESIS_OUT=$(BINDIR)/genesis



all: start $(GENESIS_OUT)
	@$(ECHO)
	@$(ECHO) "$(GREEN)THE END$(ENDCOLOR)"
	@$(ECHO)

start:
	@$(ECHO)
	@$(ECHO) "$(GREEN)Genesis...$(ENDCOLOR)"
	@$(ECHO)


clean: 
	$(RM) -f $(OBJECTS)
	$(RM) -f $(GENESIS_OUT)

run: $(GENESIS_OUT)
	./run.sh


$(GENESIS_OUT): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(GENESIS_OUT)



$(BUILDDIR)/resource-manager.o: $(SRCDIR_RES)/resource-manager.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/tga-decoder.o: $(SRCDIR_RES)/tga-decoder.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/native-fs.o: $(SRCDIR_RES)/native-fs.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/gl-video-context.o: $(SRCDIR_VIDEO)/gl-video-context.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/entry.o: entry.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

