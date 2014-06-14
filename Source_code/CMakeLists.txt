# 設定最低可拿來解析此文件的 CMake 版本
cmake_minimum_required(VERSION 2.8)

add_executable(
	Unit_test 

	Unit_test.cpp 
	showSoftwareInfo/showSoftwareInfo.c 
	pauseProgram/pauseProgram.c 
	printSomething/printSomething.c 
	Error_C/Error.c
)

# add all sub directory
# taken from http://stackoverflow.com/questions/7787823/cmake-how-to-get-the-name-of-all-subdirectories-of-a-directory
macro(subdirlist result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
        list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()
subdirlist(subdir_list ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "Found following subdirs:\n${subdir_list}")
foreach(subdir ${subdir_list})
	if(${subdir} STREQUAL "CMakeFiles"
		OR ${subdir} STREQUAL "00_Library_template")
		# 跳過
	else()
		add_subdirectory(${subdir})
	endif()
endforeach()

# copy library headers
if(library_header_output_directory)
	file(GLOB_RECURSE library_headers *.h *.hpp)
	message(STATUS "found library headers: ${library_headers}")
	file(COPY ${library_headers} DESTINATION ${library_header_output_directory})
endif()
return()