from PIL import Image
import numpy as np

img = Image.open("input.jpg").convert("RGB")
arr = np.array(img, dtype=np.uint8)

arr.tofile("raw.dat")   
