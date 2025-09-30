/**
 * @file       convert_gray.cpp
 * @version    1.0.0
 * @date       2025-09-28
 * @author     Nhan Vo
 *             
 * @brief      Convert RGB image to grayscale using ITU-R BT.709 coefficients
 *             
 * @note          
 * @example    convert_gray.cpp
 *             Example usage
 */

/* Includes ----------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "image_utils.h"

/* Private defines ---------------------------------------------------- */
#define RGB_CHANNELS  (3) /*!< Number of RGB channels */
#define GRAY_COEFF_R  (0.299) /*!< Red coefficient for grayscale conversion */
#define GRAY_COEFF_G  (0.587) /*!< Green coefficient for grayscale conversion */
#define GRAY_COEFF_B  (0.114) /*!< Blue coefficient for grayscale conversion */

/* Private function prototypes ---------------------------------------- */
/**
 * @brief  Convert RGB image to grayscale
 *
 * @param[in]     raw_file   Path to input RGB file
 * @param[in]     gray_file  Path to output grayscale file
 * @param[in]     width      Image width in pixels
 * @param[in]     height     Image height in pixels
 *
 * @attention  Input file must be RGB format with 3 channels per pixel
 *
 * @return  
 *  - 0: Success
 *  - 1: Error
 */
static void convert_gray(const char *raw_file, const char *gray_file, int width, int height);

/* Function definitions ----------------------------------------------- */
static void convert_gray(const char *raw_file, const char *gray_file, int width, int height)
{
  int size = width * height;
  FILE *fin = fopen(raw_file, "rb");
  if (!fin)
  {
    printf("Cannot open %s\n", raw_file);
    return;
  }

  unsigned char *rgb = (unsigned char *)malloc(size * RGB_CHANNELS);
  unsigned char *gray = (unsigned char *)malloc(size);
  if (!rgb || !gray)
  {
    printf("Memory allocation failed\n");
    if (rgb) free(rgb);
    if (gray) free(gray);
    fclose(fin);
    return;
  }

  fread(rgb, 1, size * RGB_CHANNELS, fin);
  fclose(fin);

  // Chuyển đổi RGB -> Gray using ITU-R BT.709 coefficients
  for (int i = 0; i < size; i++)
  {
    unsigned char r = rgb[RGB_CHANNELS * i];
    unsigned char g = rgb[RGB_CHANNELS * i + 1];
    unsigned char b = rgb[RGB_CHANNELS * i + 2];
    gray[i] = (unsigned char)(GRAY_COEFF_R * r + GRAY_COEFF_G * g + GRAY_COEFF_B * b);
  }

  FILE *fout = fopen(gray_file, "wb");
  if (!fout)
  {
    printf("Cannot create %s\n", gray_file);
    free(rgb);
    free(gray);
    return;
  }
  
  fwrite(gray, 1, size, fout);
  fclose(fout);

  free(rgb);
  free(gray);

  printf("Created file %s from %s\n", gray_file, raw_file);
}

int main()
{
  int width, height;
  
  printf("Converting RGB to Grayscale...\n");
  
  // Auto-detect image dimensions
  if (read_image_dimensions(&width, &height))
  {
    printf("Failed to read image dimensions. Exiting.\n");
    return 1;
  }
  
  convert_gray("raw.dat", "gray.dat", width, height);

  return 0;
}

/* End of file -------------------------------------------------------- */
