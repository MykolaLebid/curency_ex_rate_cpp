mkdir -p build
cd build
cmake ..
cmake --build .
./bin/test_currency_exchange
ctest
