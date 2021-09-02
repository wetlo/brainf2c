CC=gcc
COPTS=-Wall
DEST=/usr/local/bin/

all: out
	$(CC) src/main.c -o out/brainf2c $(COPTS)

out:
	mkdir -p out

install: out
	cp out/brainf2c $(DEST)

uninstall:
	rm $(DEST)/brainf2c

clean:
	rm -rf out
