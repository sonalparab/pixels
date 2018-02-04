all: pixels.c
	gcc pixels.c

run: all
	./a.out

clean:
	rm a.out
	rm image.ppm
