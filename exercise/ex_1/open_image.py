import numpy as np
import cv2
import sys

# ---- Thông số ảnh (sửa theo file của bạn) ----
width = 256
height = 256
input_file = "gray.dat"
output_file = "output.jpg"

# ---- Đọc file .dat ----
data = np.fromfile(input_file, dtype=np.uint8)

# Check kích thước
if data.size != width * height:
    print(f"Lỗi: file size = {data.size}, không khớp {width}x{height}")
    sys.exit(1)

# Reshape thành ma trận ảnh
img = data.reshape((height, width))

# ---- Lưu thành JPG ----
cv2.imwrite(output_file, img)
print(f"Đã lưu ảnh -> {output_file}")
