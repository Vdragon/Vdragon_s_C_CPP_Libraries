# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

# 設定專案名稱
project("Ｖ字龍的Ｃ與Ｃ＋＋函式庫蒐集")
set(project_name_abbreviation "VCCL")

# 設定建構類型
## Specifies the build type on single-configuration generators
### Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel.
set (CMAKE_BUILD_TYPE Debug)
## Specifies the available build types on multi-config generators.
### This specifies what build types (configurations) will be available such as Debug, Release, RelWithDebInfo etc.
### set (CMAKE_CONFIGURATION_TYPES Debug)

# 設定專案路徑
## 設定可執行檔的輸出目錄
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/)
## 設定靜態連結函式庫的輸出目錄
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/Libraries/${CMAKE_LIBRARY_ARCHITECTURE}_${CMAKE_BUILD_TYPE}/)
## 設定動態連結函式庫的輸出目錄
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/Libraries/${CMAKE_LIBRARY_ARCHITECTURE}_${CMAKE_BUILD_TYPE}/)
## PDB?
### set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/PDBs)
## Library header output path
set (library_header_output_directory ${CMAKE_BINARY_DIR}/Build/Library_headers/${project_name_abbreviation}/)

# 設定軟體安裝路徑前綴
## Install directory used by install.
### If "make install" is invoked or INSTALL is built, this directory is prepended onto all install directories. This variable defaults to /usr/local on UNIX and c:/Program Files on Windows.
### set(CMAKE_INSTALL_PREFIX )

add_subdirectory(Source_code Built_artifacts)
