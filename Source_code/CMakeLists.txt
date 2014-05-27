# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

add_executable(Unit_test Unit_test.cpp showSoftwareInfo/showSoftwareInfo.c pauseProgram/pauseProgram.c printSomething/printSomething.c Error_C/Error.c)
add_subdirectory(Swap_algorithm_C)
add_subdirectory(printSomething)
add_subdirectory(Error_C)
add_subdirectory(pauseProgram)
return()