# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME_ABBREVIATION VCCL)
set(LIBRARY_OUTPUT_NAME library_name)

# 建構函式庫
aux_source_directory(. SOURCE_CODE_FILE_LIST)
message(STATUS "找到函式庫的來源程式碼檔案：${SOURCE_CODE_FILE_LIST}")
add_library(${PROJECT_NAME_ABBREVIATION}_${LIBRARY_OUTPUT_NAME} ${SOURCE_CODE_FILE_LIST})
# file(COPY .h Build/${CMAKE_BUILD_TYPE}/Libraries)
return()