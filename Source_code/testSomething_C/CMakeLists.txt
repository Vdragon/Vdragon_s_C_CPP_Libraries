# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

set(library_name "testSomething_C")

# 處理沒有在最上層 CMakelist.txt 下執行 CMake 的專案名稱設定
if("${project_name_abbreviation}" STREQUAL "")
	set (project_name_abbreviation "VCCL")
endif()

# 建構函式庫
aux_source_directory(. SOURCE_CODE_FILE_LIST)
if("${SOURCE_CODE_FILE_LIST}" STREQUAL "")
	message(WARNING 
	"沒有找到 ${library_name} 函式庫的來源程式碼檔案！
	\n跳過 ${library_name} 函式庫的建構。")
	return()
else()
	message(STATUS "找到 ${library_name} 函式庫的來源程式碼：${SOURCE_CODE_FILE_LIST}")
endif()
add_library(${project_name_abbreviation}_${library_name} ${SOURCE_CODE_FILE_LIST})

# 將函式庫 header 檔案複製一份到 Build/ 中
# file(COPY .h Build/${CMAKE_BUILD_TYPE}/Libraries)
return()