# The format of this file is based on GNU_Make_Makefile_templates
# https://github.com/Vdragon/GNU_Make_Makefile_templates
# Macros
PROJECT_NAME = "C_CPP_project_template"
C_COMPILER = "gcc"
CPP_COMPILER = "g++"

# 變數
# objects = 

#recipies
build :
g++ -c Source_code/main.cpp -o Source_code/main.o
g++ -c Source_code/Show_software_info/Show_software_info.c -o Source_code/Show_software_info/Show_software_info.o
g++ -c Source_code/pauseProgram/Pause_program.c -o Source_code/pauseProgram/Pause_program.o
g++ -o Build/Debug/${PROJECT_NAME}.linux.x86_32bit.exe Source_code/pauseProgram/Pause_program.o Source_code/Show_software_info/Show_software_info.o Source_code/main.o

.PHONY : clean
clean :
  -rm Object_code/*.o

