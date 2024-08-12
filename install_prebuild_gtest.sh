git clone https://github.com/google/googletest.git

cd googletest

cmake -B build -DCMAKE_INSTALL_PREFIX=~/googletest_prebuild

cmake --build build --target install

cd ..

cmake -B build -DGTEST_ROOT=~/googletest_prebuild

cmake --build build