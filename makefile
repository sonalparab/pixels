all: pixels.c
	gcc pixels.c

run: all
	./a.out

convert:
	convert image.ppm image.png

display: convert
	display image.png

clean:
	rm a.out
	rm image.ppm
	rm image.png
