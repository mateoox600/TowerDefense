@echo off
cd build
call emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3 --shell-file F:/shell.html"
call emmake make
cd ..