mkdir -p build_release
cd build_release
cmake -DCMAKE_INSTALL_PREFIX=/home/mykola/Repos/Test_Driven_Dev_CPP_Jeff_Langr/currency_ex_rate_cpp/build_release/install -DCMAKE_BUILD_TYPE=Release .. 
cmake  --build . --config Debug --target install
./bin/test_currency_exchange
ctest
#All build generators 
cpack --config CPackSourceConfig.cmake
