#!/bin/bash

echo "Введите путь до vcpkg"
read path

if [-f build]; then 
    rmdir -rf build
fi

cmake --toolchain $path/scripts/buildsystems/vcpkg.cmake -S . -B build -q
echo "Происходит сборка"

cmake --build build --config Release -q

echo "Происходит инсталляция"
cmake --install ./build/ --config release --prefix cmd/ -q

echo "Сборка и инсталляция успешно завершена"