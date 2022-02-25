all: geometry
geometry: geometry.c
	gcc -Wall -Werror -o geometry geometry.c -lm
clean:
	rm geometry
run:
	./geometry