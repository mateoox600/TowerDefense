@echo off
cd build
call cmake --build .
call cdg-tower-defense.exe
cd ..