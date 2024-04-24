@echo off
REM Проверяем количество переданных аргументов
if "%~1"=="" (
    echo Пожалуйста, укажите путь до vcpkg и путь установки проекта.
    exit /b 1
)


REM Выполняем cmake с указанными аргументами
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="%~1\scripts\buildsystems\vcpkg.cmake"

REM Проверяем успешность выполнения предыдущей команды
if %errorlevel% neq 0 (
    echo Ошибка: cmake завершил работу с ошибкой.
    exit /b 1
)

REM Выполняем сборку проекта
cmake --build build --config Release

REM Проверяем успешность выполнения предыдущей команды
if %errorlevel% neq 0 (
    echo Ошибка: сборка проекта завершилась с ошибкой.
    exit /b 1
)

REM Устанавливаем проект в указанное место
cmake --install ./build --config release --prefix cmd/ 

REM Проверяем успешность выполнения предыдущей команды
if %errorlevel% neq 0 (
    echo Ошибка: установка проекта завершилась с ошибкой.
    exit /b 1
)

echo Успешно завершено: проект установлен по пути cmd/ 
exit /b 0
