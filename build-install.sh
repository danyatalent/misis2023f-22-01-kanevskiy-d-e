#!/bin/bash

echo "Введите путь до vcpkg"
read path

if [-f build]; then 
    rmdir -rf build
fi

cmake --toolchain $path/scripts/buildsystems/vcpkg.cmake -S . -B build 
echo "Происходит сборка"

cmake --build build --config Release 

echo "Происходит инсталляция"
cmake --install ./build/ --config release --prefix cmd/ 

echo "Сборка и инсталляция успешно завершена"