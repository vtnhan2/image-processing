# Image Processing Exercise 1 - Report

## Tổng quan
Dự án thực hiện chuyển đổi ảnh màu sang các định dạng khác nhau: RGB → Grayscale → Binary, sử dụng Python và C.

## Các bước thao tác

### 1. Chuyển đổi ảnh màu sang Raw format
```bash
python convert_dat.py
```
- **Input**: `input.jpg` (2912×2186 pixels)
- **Output**: `raw.dat` (19MB, format RGB)
- **Metadata**: `raw_info.txt` (thông tin chi tiết)

### 2. Chuyển đổi RGB sang Grayscale
```bash
g++ -o convert_gray convert_gray.cpp
./convert_gray
```
- **Input**: `raw.dat`
- **Output**: `gray.dat` (6.3MB)
- **Công thức**: `0.299×R + 0.587×G + 0.114×B`

### 3. Chuyển đổi Grayscale sang Binary
```bash
g++ -o convert_bin convert_bin.cpp
./convert_bin
```
- **Input**: `gray.dat`
- **Output**: `bin.dat` (6.3MB)
- **Ngưỡng**: < 128 = đen (0), ≥ 128 = trắng (255)

### 4. Xem kết quả
```bash
python open_image.py
```
- Tạo các file output: `raw_output.jpg`, `gray_output.jpg`, `bin_output.jpg`
- Hiển thị ảnh để kiểm tra kết quả

## Cấu trúc file

### Python Scripts
- `convert_dat.py` - Chuyển đổi ảnh màu sang raw format
- `open_image.py` - Mở và hiển thị các file .dat

### C Programs
- `convert_gray.cpp` - Chuyển đổi RGB sang grayscale
- `convert_bin.cpp` - Chuyển đổi grayscale sang binary

### Data Files
- `input.jpg` - Ảnh gốc (4.6MB)
- `raw.dat` - Dữ liệu RGB thô (19MB)
- `gray.dat` - Ảnh xám (6.3MB)
- `bin.dat` - Ảnh nhị phân (6.3MB)

## Cách chạy toàn bộ pipeline

```bash
# Bước 1: Chuyển đổi ảnh sang raw (tự động xác định kích thước ảnh)
python convert_dat.py

# Bước 2: Compile và chạy chương trình C (tự động đọc kích thước)
g++ -o convert_gray convert_gray.cpp
g++ -o convert_bin convert_bin.cpp

# Bước 3: Chuyển đổi RGB → Grayscale (auto-detect dimensions)
./convert_gray

# Bước 4: Chuyển đổi Grayscale → Binary
./convert_bin

# Bước 5: Xem kết quả (auto-detect dimensions)
python open_image.py
```

## ✨ **Tính năng mới: Auto-Detection**

- **Không cần điền thủ công** kích thước ảnh
- **Tự động detect** từ file `image_config.txt`
- **Hoạt động với mọi kích thước ảnh**
- **Error handling** đầy đủ khi thiếu config file

## Kết quả
- ✅ Chuyển đổi thành công ảnh 2912×2186 pixels
- ✅ Tạo được 3 định dạng: RGB, Grayscale, Binary
- ✅ Tất cả file output đều có thể xem được
- ✅ Pipeline hoạt động ổn định với ảnh lớn (19MB raw data)

## Lưu ý kỹ thuật
- Sử dụng công thức chuẩn ITU-R BT.709 cho grayscale
- Ngưỡng binary: 128 (có thể điều chỉnh)
- Hỗ trợ ảnh lớn với memory management tốt
- Error handling đầy đủ trong tất cả chương trình
