@echo off
cd build
call cmake --build .
call raylib-cmake-test.exe
cd ..