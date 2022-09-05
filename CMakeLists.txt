cmake_minimum_required (VERSION 3.21)
project (SimpleSAM)
enable_testing()

add_executable(tosam src/tosam.c)
add_test(tosam tosam)

