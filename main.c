#define _MAIN_C_

#include <gdal.h>
#include "raster.h"

int main(int argc, char *argv[])
{
    int print_usage = 1, use_dir = 0;
    const char *path = NULL, *null_str = NULL, *fmt = NULL;
    int i;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            int j, n = strlen(argv[i]);
            int unknown = 0;

            for (j = 1; j < n && !unknown; j++) {
                switch (argv[i][j]) {
                case 'd':
                    use_dir = 1;
                    break;
                default:
                    unknown = 1;
                    break;
                }
            }
            if (unknown) {
                fprintf(stderr, "%c: Unknown flag\n", argv[i][j]);
                print_usage = 2;
                break;
            }
        }
        else if (!path) {
            path = argv[i];
            print_usage = 0;
        }
        else if (!null_str)
            null_str = argv[i];
        else if (!fmt)
            fmt = argv[i];
        else {
            fprintf(stderr, "%s: Unable to process extra arguments\n",
                    argv[i]);
            print_usage = 2;
            break;
        }
    }

    if (print_usage) {
        if (print_usage == 2)
            printf("\n");
        printf("Usage: tifcat [-d] tif_path [null_str] [printf_format]\n");
        printf("\n");
        printf("  -d\t\tUse directions in binary encoding\n");
        exit(EXIT_SUCCESS);
    }

    GDALAllRegister();
    print_raster(path, null_str, fmt, use_dir);
    exit(EXIT_SUCCESS);
}
