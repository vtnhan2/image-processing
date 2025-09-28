#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fgray, *fbin;
    unsigned char pixel;

    fgray = fopen("gray.dat", "rb");
    if (!fgray)
    {
        printf("cannot open file gray.dat\n");
        return 1;
    }

    fbin = fopen("bin.dat", "wb");
    if (!fbin)
    {
        printf("Cannot create file bin.dat\n");
        fclose(fgray);
        return 1;
    }

    // Đọc từng pixel từ gray.dat và chuyển thành nhị phân
    while (fread(&pixel, 1, 1, fgray) == 1)
    {
        unsigned char bin_pixel;
        if (pixel < 128)
            bin_pixel = 0; // black
        else
            bin_pixel = 255; // white

        fwrite(&bin_pixel, 1, 1, fbin);
    }

    fclose(fgray);
    fclose(fbin);

    printf("Chuyển đổi hoàn tất -> bin.dat\n");
    return 0;
}
