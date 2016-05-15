SHELL=/bin/zsh
CC=gcc
CFLAGS=-g -fdiagnostics-color=always -std=gnu11 -Wall -Wpedantic -Wextra -MMD -MP
ELF = brickfuck

.PHONY: clean all rebuild

all : $(ELF)

$(ELF): $(ELF).c
	$(CC) $(CFLAGS) $< -o $@

clean: clean_specific
	rm -f **/*.o(N) **/*.d(N) $(ELF)

clean_specific:

rebuild: clean all

-include *.d
