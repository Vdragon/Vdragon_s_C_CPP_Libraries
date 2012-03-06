#Makefile範本版本：0.00(0)
CC = gcc
Object_file = ./Object_file/Debug/Sorting_algorithm.o \
	  ./Object_file/Debug/Test_program.o
	  
Test_program.linux.executable : $(Object_file)
	$(CC) -o ./Binary_executable/Debug/Test_program.linux.executable $(Object_file)

Object_file/Debug/Sorting_algorithm.o : Sorting_algorithm.c Sorting_algorithm.h
	$(CC) -c ./Object_file/Debug/Sorting_algorithm.o 
.PHONY : clean
clean : 
	-rm ./Object_file/Debug/*.o
	-rm ./Object_file/Release/*.o