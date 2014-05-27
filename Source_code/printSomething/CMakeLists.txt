# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

set(library_name "printSomething")

# 建構函式庫
aux_source_directory(. SOURCE_CODE_FILE_LIST)
message(STATUS "找到 ${library_name} 函式庫的來源程式碼：${SOURCE_CODE_FILE_LIST}")
add_library(${project_name_abbreviation}_${library_name} ${SOURCE_CODE_FILE_LIST})
# file(COPY .h Build/${CMAKE_BUILD_TYPE}/Libraries)
return()