# TifCat

This program prints out the cell values of a GeoTIFF file. It is meant to be used for unit testing with small files and requires GDAL.

```bash
$ ./tifcat test/fdr.tif 
  1   1   2   4  16   8   8   8   8   8   8   8
  1   1   2   4  16   8   8   8   8   8   8   8
  1   1   1   4  16   8   8   8   8   8   8   8
  1   1   1   4  16   8   8   8   8   8   8   8
  1   1   1   4  16   4   8   8   8   8   8   8
  1   1   1   4   2   4   8   8   8   8   8   8
  1   1   1   2   1   2   4   4   4   4   4   4
  8   1   1   1   2   4 255 255 255 255 255 255
 16   1   1 128  16 255 255 255 255 255 255 255
$ ./tifcat test/fdr.tif null
   1    1    2    4   16    8    8    8    8    8    8    8
   1    1    2    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    4    8    8    8    8    8    8
   1    1    1    4    2    4    8    8    8    8    8    8
   1    1    1    2    1    2    4    4    4    4    4    4
   8    1    1    1    2    4 null null null null null null
  16    1    1  128   16 null null null null null null null
./tifcat test/fdr.tif "   -" %4d
   1    1    2    4   16    8    8    8    8    8    8    8
   1    1    2    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    8    8    8    8    8    8    8
   1    1    1    4   16    4    8    8    8    8    8    8
   1    1    1    4    2    4    8    8    8    8    8    8
   1    1    1    2    1    2    4    4    4    4    4    4
   8    1    1    1    2    4    -    -    -    -    -    -
  16    1    1  128   16    -    -    -    -    -    -    -
```
