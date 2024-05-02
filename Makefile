ifeq ($(OS),Windows_NT)
	CFLAGS=-Wall -Werror -O3 -fopenmp -I/c/OSGeo4W/include
	GDALLIBS=/c/OSGeo4W/lib/gdal_i.lib
	EXT=.exe
else
	CFLAGS=-Wall -Werror -O3 -fopenmp
	GDALLIBS=`gdal-config --libs`
	EXT=
endif
LDFLAGS=-O3 -fopenmp -lm

all: tifcat$(EXT)

clean:
	$(RM) *.o

tifcat$(EXT): main.o raster.o
	$(CC) $(LDFLAGS) -o $@ $^ $(GDALLIBS)

*.o: raster.h
