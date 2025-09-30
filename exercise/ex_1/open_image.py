# Complete open_image.py with all file types and error handling
import numpy as np
from PIL import Image
import os

def read_image_config():
    """Read image dimensions from config file"""
    try:
        with open("image_config.txt", "r") as f:
            width = int(f.readline().strip())
            height = int(f.readline().strip())
        return width, height
    except FileNotFoundError:
        print("Error: image_config.txt not found. Please run convert_dat.py first.")
        return None, None
    except Exception as e:
        print(f"Error reading config file: {e}")
        return None, None

def open_rgb_image(filename, width, height):
    """Open RGB .dat file"""
    try:
        print(f"Reading RGB image: {filename}")
        data = np.fromfile(filename, dtype=np.uint8)
        expected_size = width * height * 3
        
        if len(data) != expected_size:
            print(f"Warning: Expected {expected_size} elements, got {len(data)}")
            if len(data) < expected_size:
                return None
        
        img_array = data[:expected_size].reshape((height, width, 3))
        img = Image.fromarray(img_array, 'RGB')
        print(f"Successfully loaded RGB image: {width}x{height}")
        return img
        
    except Exception as e:
        print(f"Error loading RGB image: {e}")
        return None

def open_grayscale_image(filename, width, height):
    """Open grayscale .dat file"""
    try:
        print(f"Reading grayscale image: {filename}")
        data = np.fromfile(filename, dtype=np.uint8)
        expected_size = width * height
        
        if len(data) != expected_size:
            print(f"Warning: Expected {expected_size} elements, got {len(data)}")
            if len(data) < expected_size:
                return None
        
        img_array = data[:expected_size].reshape((height, width))
        img = Image.fromarray(img_array, 'L')
        print(f"Successfully loaded grayscale image: {width}x{height}")
        return img
        
    except Exception as e:
        print(f"Error loading grayscale image: {e}")
        return None

# MAIN PROGRAM
if __name__ == "__main__":
    print("=== Image .DAT File Opener ===\n")
    
    # Auto-detect image dimensions from config file
    WIDTH, HEIGHT = read_image_config()
    if WIDTH is None or HEIGHT is None:
        print("Failed to read image dimensions. Exiting.")
        exit(1)
    
    print(f"Auto-detected dimensions: {WIDTH} x {HEIGHT}")
    
    # Try to open different .dat files
    files_to_try = [
        ('raw.dat', 'RGB', open_rgb_image),
        ('gray.dat', 'Grayscale', open_grayscale_image),
        ('bin.dat', 'Binary', open_grayscale_image)
    ]
    
    for filename, file_type, open_func in files_to_try:
        if os.path.exists(filename):
            print(f"\n--- Opening {file_type} file: {filename} ---")
            img = open_func(filename, WIDTH, HEIGHT)
            
            if img:
                img.show()
                output_name = filename.replace('.dat', '_output.jpg')
                img.save(output_name, 'JPEG', quality=95)
                print(f"Saved as: {output_name}")
        else:
            print(f"File not found: {filename}")
    
    print("\nDone!")
