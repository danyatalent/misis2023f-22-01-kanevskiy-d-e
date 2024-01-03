Каневский Даниил 29.12.23  

### CMake Toolchain
CMake Toolchain File — это текстовый файл, который предоставляет информацию CMake осреде сборки, используемой для компиляции кода. 

Этот файл указывает 
* компилятор 
* параметры компиляции 
* настройки линковки 
* другие параметры, необходимые для успешного построения проекта


### Когда нужен CMake Toolchain File?

1. **Кросс-компиляция:**
   - Сборка приложения для целевой платформы, отличной от платформы разработки. Например, компиляция кода под ARM на компьютере с x86_64.

2. **Специфичные настройки:**
   - Проект требует специфических настроек среды сборки, которые необходимы для интеграции с внешними инструментами или библиотеками.

3. **Автоматизация сборки:**
   - Необходимо автоматизировать процесс сборки и обеспечить согласованность среды сборки на различных системах.

Минимальный пример toolchain файла
```cmake
set(CMAKE_C_COMPILER gcc-11)
set(CMAKE_CXX_COMPILER g++11)
```

Такой пример может быть заменен с помощью аргументов командной строки
```bash
cmake -DCMAKE_C_COMPILER=/usr/bin/gcc-11 -DCMAKE_CXX_COMPILER=/usr/bin/g++-11 -Ssource -Bbuild
```

### Структура CMake Toolchain File:

Простой пример CMake Toolchain File для кросс-компиляции на ARM:

```cmake
# Пример CMake Toolchain File для ARM

# Указание компилятора
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

# Дополнительные параметры компиляции
set(CMAKE_C_FLAGS   "-mcpu=cortex-m4 -mthumb")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m4 -mthumb")

# Дополнительные параметры линковки
set(CMAKE_EXE_LINKER_FLAGS "-T path/to/linker/script.ld")

# Другие настройки
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
```

#### Ключевые моменты:

- `CMAKE_C_COMPILER` и `CMAKE_CXX_COMPILER`: Указывают на компиляторы для языков C и C++ соответственно.
- `CMAKE_C_FLAGS` и `CMAKE_CXX_FLAGS`: Задают дополнительные параметры компиляции.
- `CMAKE_EXE_LINKER_FLAGS`: Задает дополнительные параметры линковки.
- `CMAKE_SYSTEM_NAME` и `CMAKE_SYSTEM_PROCESSOR`: Определяют системное имя и процессор, соответственно.

### Применение CMake Toolchain File:

Для использования CMake Toolchain File при генерации проекта используется опция `-DCMAKE_TOOLCHAIN_FILE`:

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=path/to/toolchain/file.cmake path/to/source
```

Или указывается в настройках CMake, например в CMakePresets

### Одним из распространенных тулчейн файлов является vcpkg тулчейн