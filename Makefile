SRC=./src
INC=./include

ARGS=-I$(INC) -g
CC=gcc $(ARGS)
ALL=main.o brainfuck.o

brainfuck: $(ALL)
	$(CC) -o $@ $(ALL)

main.o: $(SRC)/main.c
	$(CC) -o $@ -c $<

brainfuck.o: $(SRC)/brainfuck.c $(INC)/brainfuck.h
	$(CC) -o $@ -c $<

clean:
	make post-clean
	rm -r brainfuck.exe brainfuck

post-clean:
	rm -r $(ALL)