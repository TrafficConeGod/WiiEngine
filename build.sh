mkdir build
cd build
g++ -I ../src -c $(find ../src -name '*.cc') -std=c++17 $1
g++ -I ../src $(find . -name '*.o') -o app $1
cd ..