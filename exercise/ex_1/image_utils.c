/**
 * @file       image_utils.c
 * @version    1.0.0
 * @date       2025-09-28
 * @author     Nhan Vo
 *             
 * @brief      Image processing utilities implementation
 *             
 * @note          
 * @example    convert_gray.cpp
 *             Example usage in grayscale conversion
 */

/* Includes ----------------------------------------------------------- */
#include "image_utils.h"

/* Private defines ---------------------------------------------------- */
#define MAX_LINE_LENGTH  (256) /*!< Maximum line length for config file */

/* Function definitions ----------------------------------------------- */
int read_image_dimensions(int *width, int *height)
{
  FILE *config = fopen(CONFIG_FILE_NAME, "r");
  if (!config)
  {
    printf("Error: Cannot open %s\n", CONFIG_FILE_NAME);
    printf("Please run convert_dat.py first to generate the config file.\n");
    return 1;
  }
  
  if (fscanf(config, "%d", width) != 1)
  {
    printf("Error: Cannot read width from config file\n");
    fclose(config);
    return 1;
  }
  
  if (fscanf(config, "%d", height) != 1)
  {
    printf("Error: Cannot read height from config file\n");
    fclose(config);
    return 1;
  }
  
  fclose(config);
  printf("Auto-detected image dimensions: %dx%d\n", *width, *height);
  return 0;
}

/* End of file -------------------------------------------------------- */
