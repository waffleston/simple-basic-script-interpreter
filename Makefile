# Very basic makefile.

interpreter: interpreter.c
	gcc interpreter.c -o interpreter

clean:
	rm interpreter

