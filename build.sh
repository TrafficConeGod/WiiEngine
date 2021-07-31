mkdir build
cd build
g++ -I ../src -I /opt/devkitpro/libogc/include/ -c $(find ../src -name '*.cpp') -std=c++17 -fpermissive $1
g++ -I ../src $(find . -name '*.o') -o app $1
cd ..