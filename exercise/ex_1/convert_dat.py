from PIL import Image
import numpy as np
import os

def convert_image_to_raw(input_path, output_path="raw.dat", save_metadata=True):
    """Enhanced version with error handling and metadata"""
    try:
        # Check if input file exists
        if not os.path.exists(input_path):
            raise FileNotFoundError(f"Input image file not found: {input_path}")
        
        # Load and convert image (your original approach)
        img = Image.open(input_path).convert("RGB")
        arr = np.array(img, dtype=np.uint8)
        
        # Get image information
        height, width, channels = arr.shape
        file_size = arr.nbytes
        
        print(f"Image loaded: {input_path}")
        print(f"Dimensions: {width}×{height} pixels")
        print(f"Channels: {channels} (RGB)")
        print(f"Data type: {arr.dtype}")
        print(f"Raw file size: {file_size:,} bytes ({file_size/1024/1024:.2f} MB)")
        
        # Save raw data (your original method)
        arr.tofile(output_path)
        print(f"Raw data saved: {output_path}")
        
        # Save metadata for embedded systems use
        if save_metadata:
            metadata_path = output_path.replace('.dat', '_info.txt')
            with open(metadata_path, 'w') as f:
                f.write(f"Original file: {input_path}\n")
                f.write(f"Width: {width}\n")
                f.write(f"Height: {height}\n")
                f.write(f"Channels: {channels}\n")
                f.write(f"Data type: {arr.dtype}\n")
                f.write(f"File size: {file_size} bytes\n")
                f.write(f"Pixel order: RGB (row-major)\n")
            print(f"Metadata saved: {metadata_path}")
            
            # Save dimensions to config file for C programs
            config_path = "image_config.txt"
            with open(config_path, 'w') as f:
                f.write(f"{width}\n")
                f.write(f"{height}\n")
            print(f"Config file saved: {config_path}")
        
        return arr.shape, arr.dtype
        
    except Exception as e:
        print(f"Error: {e}")
        return None, None

# Usage
if __name__ == "__main__":
    shape, dtype = convert_image_to_raw("input.jpg", "raw.dat")
    if shape:
        print(f"Image dimensions: {shape[1]}x{shape[0]} (width x height)")
        print(f"Channels: {shape[2]}")
