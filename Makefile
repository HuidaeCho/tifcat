CFLAGS=-Wall -Werror -O3
LDFLAGS=-O3 -fopenmp -lm

all: tifcat

clean:
	$(RM) *.o

tifcat: main.o raster.o
	$(CC) $(LDFLAGS) -o $@ $^ `gdal-config --libs`

*.o: raster.h
