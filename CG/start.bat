g++ -c -o test.o test.cpp -I"C:\Program Files\Common Files\MinGW\freeglut\include" && g++ -o test.exe test.o -L"C:\Program Files\Common Files\MinGW\freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows
