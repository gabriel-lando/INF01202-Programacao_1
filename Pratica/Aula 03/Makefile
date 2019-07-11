CSOURCE   = $(wildcard *.c)

all: $(addsuffix , $(basename $(CSOURCE)))

% :	%.c
	gcc -o $@ $< -lm

clean:
	-$(RM) *.dll *.o *.elf a.out core*
