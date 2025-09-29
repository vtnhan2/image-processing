/**
 * @file       image_utils.h
 * @version    1.0.0
 * @date       2025-09-28
 * @author     Nhan Vo
 *             
 * @brief      Image processing utilities for reading configuration
 *             
 * @note          
 * @example    convert_gray.cpp
 *             Example usage in grayscale conversion
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __IMAGE_UTILS_H
#define __IMAGE_UTILS_H

/* Includes ----------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

/* Public defines ----------------------------------------------------- */
#define CONFIG_FILE_NAME  "image_config.txt" /*!< Configuration file name */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief  Read image dimensions from config file
 *
 * @param[out]    width   Pointer to store width value
 * @param[out]    height  Pointer to store height value
 *
 * @attention  Config file must exist and contain two integers
 *
 * @return  
 *  - 0: Success
 *  - 1: Error
 */
int read_image_dimensions(int *width, int *height);

#endif // __IMAGE_UTILS_H

/* End of file -------------------------------------------------------- */
