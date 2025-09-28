#include <stdio.h>
#include <stdlib.h>

void convert_gray(const char *raw_file, const char *gray_file, int width, int height)
{
    int size = width * height;
    FILE *fin = fopen(raw_file, "rb");
    if (!fin)
    {
        printf("Cannot open %s\n", raw_file);
        return;
    }

    unsigned char *rgb = (unsigned char *)malloc(size * 3);
    unsigned char *gray = (unsigned char *)malloc(size);

    fread(rgb, 1, size * 3, fin);
    fclose(fin);

    // Chuyển đổi RGB -> Gray
    for (int i = 0; i < size; i++)
    {
        unsigned char r = rgb[3 * i];
        unsigned char g = rgb[3 * i + 1];
        unsigned char b = rgb[3 * i + 2];
        gray[i] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
    }

    FILE *fout = fopen(gray_file, "wb");
    fwrite(gray, 1, size, fout);
    fclose(fout);

    free(rgb);
    free(gray);

    printf("Created file %s from %s\n", gray_file, raw_file);
}

int main()
{
    int width = 256; // set theo ảnh của bạn
    int height = 256;

    convert_gray("raw.dat", "gray.dat", width, height);

    return 0;
}
