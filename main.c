#define _MAIN_C_

#include <gdal.h>
#include "raster.h"

#define GET_ARG (++i < argc ? argv[i] : NULL)

int main(int argc, char *argv[])
{
    const char *path, *fmt, *null_str;
    int i = 0;

    if (argc < 2) {
        printf("Usage: tifcat tif_path [printf_format] [null_str]\n");
        exit(EXIT_FAILURE);
    }

    path = GET_ARG;
    fmt = GET_ARG;
    null_str = GET_ARG;

    GDALAllRegister();
    print_raster(path, fmt, null_str);
    exit(EXIT_SUCCESS);
}
