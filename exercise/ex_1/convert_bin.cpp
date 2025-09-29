/**
 * @file       convert_bin.cpp
 * @version    1.0.0
 * @date       2025-09-28
 * @author     Nhan Vo
 *             
 * @brief      Convert grayscale image to binary using threshold
 *             
 * @note          
 * @example    convert_bin.cpp
 *             Example usage
 */

/* Includes ----------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

/* Private defines ---------------------------------------------------- */
#define GRAY_INPUT_FILE   "gray.dat" /*!< Input grayscale file name */
#define BIN_OUTPUT_FILE   "bin.dat"  /*!< Output binary file name */
#define BINARY_THRESHOLD  (128)      /*!< Threshold for binary conversion */
#define BLACK_VALUE       (0)        /*!< Black pixel value */
#define WHITE_VALUE       (255)      /*!< White pixel value */

/* Private function prototypes ---------------------------------------- */
/**
 * @brief  Convert grayscale to binary
 *
 * @param[in]     input_file   Path to input grayscale file
 * @param[in]     output_file  Path to output binary file
 *
 * @attention  Input file must be grayscale format
 *
 * @return  
 *  - 0: Success
 *  - 1: Error
 */
static int convert_grayscale_to_binary(const char *input_file, const char *output_file);

/* Function definitions ----------------------------------------------- */
static int convert_grayscale_to_binary(const char *input_file, const char *output_file)
{
  FILE *fgray, *fbin;
  unsigned char pixel;
  int pixel_count = 0;

  fgray = fopen(input_file, "rb");
  if (!fgray)
  {
    printf("Cannot open file %s\n", input_file);
    return 1;
  }

  fbin = fopen(output_file, "wb");
  if (!fbin)
  {
    printf("Cannot create file %s\n", output_file);
    fclose(fgray);
    return 1;
  }

  // Đọc từng pixel từ gray.dat và chuyển thành nhị phân
  while (fread(&pixel, 1, 1, fgray) == 1)
  {
    unsigned char bin_pixel;
    if (pixel < BINARY_THRESHOLD)
      bin_pixel = BLACK_VALUE; // black
    else
      bin_pixel = WHITE_VALUE; // white

    fwrite(&bin_pixel, 1, 1, fbin);
    pixel_count++;
  }

  fclose(fgray);
  fclose(fbin);

  printf("Conversion completed -> %s\n", output_file);
  printf("Processed %d pixels (threshold=%d)\n", pixel_count, BINARY_THRESHOLD);
  return 0;
}

int main()
{
  printf("Converting Grayscale to Binary...\n");
  
  if (convert_grayscale_to_binary(GRAY_INPUT_FILE, BIN_OUTPUT_FILE))
  {
    printf("Binary conversion failed\n");
    return 1;
  }
  
  return 0;
}

/* End of file -------------------------------------------------------- */
