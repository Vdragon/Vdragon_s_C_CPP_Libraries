# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

# 設定專案名稱
project("Vdragons_C_CPP_Libraries_Collection")
set(PROJECT_NAME_ABBREVIATION "VCCL")

# 使用相對路徑
set (CMAKE_USE_RELATIVE_PATHS TRUE)

# 設定建構類型
## Specifies the build type on single-configuration generators
### Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel.
set (CMAKE_BUILD_TYPE Release)
## Specifies the available build types on multi-config generators.
### This specifies what build types (configurations) will be available such as Debug, Release, RelWithDebInfo etc.
### set (CMAKE_CONFIGURATION_TYPES Debug)

# 設定專案路徑
## 設定可執行檔的輸出目錄
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY Build/)
## 設定靜態連結函式庫的輸出目錄
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY Build/Libraries/${CMAKE_LIBRARY_ARCHITECTURE}_${CMAKE_BUILD_TYPE}/)
## 設定動態連結函式庫的輸出目錄
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY Build/Libraries/${CMAKE_LIBRARY_ARCHITECTURE}_${CMAKE_BUILD_TYPE}/)
## PDB?
### set (CMAKE_RUNTIME_OUTPUT_DIRECTORY Buildsystem_CMake/Build/PDBs)

# 設定軟體安裝路徑前綴
## Install directory used by install.
### If "make install" is invoked or INSTALL is built, this directory is prepended onto all install directories. This variable defaults to /usr/local on UNIX and c:/Program Files on Windows.
### set(CMAKE_INSTALL_PREFIX )

# 
aux_source_directory(../Source_code/Swap_algorithm_C SOURCE_CODE_FILE_LIST)
message(STATUS "找到來源程式碼檔案：${SOURCE_CODE_FILE_LIST}")
add_library(${PROJECT_NAME_ABBREVIATION}_Swap_algorithm_C ${SOURCE_CODE_FILE_LIST})
# file(COPY 

# message(STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

# add_subdirectory(../Source_code/Swap_algorithm_C .)