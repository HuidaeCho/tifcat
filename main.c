#define _MAIN_C_

#include <gdal.h>
#include "raster.h"

#define GET_ARG (++i < argc ? argv[i] : NULL)

int main(int argc, char *argv[])
{
    const char *path, *null_str, *fmt;
    int i = 0;

    if (argc < 2) {
        printf("Usage: tifcat tif_path [null_str] [printf_format]\n");
        exit(EXIT_FAILURE);
    }

    path = GET_ARG;
    null_str = GET_ARG;
    fmt = GET_ARG;

    GDALAllRegister();
    print_raster(path, null_str, fmt);
    exit(EXIT_SUCCESS);
}
