CC=gcc
COPTS=-Wall

all: out
	$(CC) src/main.c -o out/brainf2c $(COPTS)

out:
	mkdir -p out

clean:
	rm -rf out
