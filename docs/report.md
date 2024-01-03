��������� ������ 29.12.23  

### CMake Toolchain
CMake Toolchain File � ��� ��������� ����, ������� ������������� ���������� CMake ������ ������, ������������ ��� ���������� ����. 

���� ���� ��������� 
* ���������� 
* ��������� ���������� 
* ��������� �������� 
* ������ ���������, ����������� ��� ��������� ���������� �������


### ����� ����� CMake Toolchain File?

1. **�����-����������:**
   - ������ ���������� ��� ������� ���������, �������� �� ��������� ����������. ��������, ���������� ���� ��� ARM �� ���������� � x86_64.

2. **����������� ���������:**
   - ������ ������� ������������� �������� ����� ������, ������� ���������� ��� ���������� � �������� ������������� ��� ������������.

3. **������������� ������:**
   - ���������� ���������������� ������� ������ � ���������� ��������������� ����� ������ �� ��������� ��������.

����������� ������ toolchain �����
```cmake
set(CMAKE_C_COMPILER gcc-11)
set(CMAKE_CXX_COMPILER g++11)
```

����� ������ ����� ���� ������� � ������� ���������� ��������� ������
```bash
cmake -DCMAKE_C_COMPILER=/usr/bin/gcc-11 -DCMAKE_CXX_COMPILER=/usr/bin/g++-11 -Ssource -Bbuild
```

### ��������� CMake Toolchain File:

������� ������ CMake Toolchain File ��� �����-���������� �� ARM:

```cmake
# ������ CMake Toolchain File ��� ARM

# �������� �����������
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

# �������������� ��������� ����������
set(CMAKE_C_FLAGS   "-mcpu=cortex-m4 -mthumb")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m4 -mthumb")

# �������������� ��������� ��������
set(CMAKE_EXE_LINKER_FLAGS "-T path/to/linker/script.ld")

# ������ ���������
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
```

#### �������� �������:

- `CMAKE_C_COMPILER` � `CMAKE_CXX_COMPILER`: ��������� �� ����������� ��� ������ C � C++ ��������������.
- `CMAKE_C_FLAGS` � `CMAKE_CXX_FLAGS`: ������ �������������� ��������� ����������.
- `CMAKE_EXE_LINKER_FLAGS`: ������ �������������� ��������� ��������.
- `CMAKE_SYSTEM_NAME` � `CMAKE_SYSTEM_PROCESSOR`: ���������� ��������� ��� � ���������, ��������������.

### ���������� CMake Toolchain File:

��� ������������� CMake Toolchain File ��� ��������� ������� ������������ ����� `-DCMAKE_TOOLCHAIN_FILE`:

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=path/to/toolchain/file.cmake path/to/source
```

��� ����������� � ���������� CMake, �������� � CMakePresets

### ����� �� ���������������� ������� ������ �������� vcpkg �������