# brainf2c

This is a simple little transpiler, that converts brainf\*ck code to c.
I made this project because i wanted to compile brainf\*ck and also
write some kind of interpreter/parser for this esoteric language. I also
had the idea to convert it into assembly instead of C, but then it would
be more platform dependant and I also don't know any assembly, so C is
the best option. The program is also written in C because any other language
would be blasphemy here.

## installation

Just run `make install` as root (with sudo or doas).

## usage

The program gets the brainf\*ck code from stdin
and outputs the C code to stdout. No need for any arguments!

```
$ brainf2c < brainfck_code > transpiled.c
```
