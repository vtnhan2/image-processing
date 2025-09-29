#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// Function to read image dimensions from config file
int read_image_dimensions(int *width, int *height) {
    FILE *config = fopen("image_config.txt", "r");
    if (!config) {
        printf("Error: Cannot open image_config.txt\n");
        printf("Please run convert_dat.py first to generate the config file.\n");
        return 0;
    }
    
    if (fscanf(config, "%d", width) != 1) {
        printf("Error: Cannot read width from config file\n");
        fclose(config);
        return 0;
    }
    
    if (fscanf(config, "%d", height) != 1) {
        printf("Error: Cannot read height from config file\n");
        fclose(config);
        return 0;
    }
    
    fclose(config);
    printf("Auto-detected image dimensions: %dx%d\n", *width, *height);
    return 1;
}

#endif
