/*
	主程式

	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
*/
/* 程式所 include 之函式庫的標頭檔
 * Included Library Headers */
	/* Standard C/C++ library */
    /* for EXIT_* return code definition */
		  #include <cstdlib>
		/* for errno */
			#include <cerrno>
		/* io function */
			#include <cstdio>

  /* Vdragons_C_CPP_Libraries_Collection
   * https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    /* for pausing program definition */
		  #include "pauseProgram/Pause_program.h"
    /* for showing software info */
		  #include "Show_software_info/Show_software_info.h"
		/* test target */
			#include "Error/C/Error.h"
		/* for testProcedure() */
			#include "testSomething/C/testSomething.h"

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */
	/* global errno */
		extern int errno;

/* 主要程式碼
 * Main Code */
  int main(int argc, char *argv[]){
  	void test_printErrorErrno(void);
  	void test_abortError(void);

  /*用來重新運行程式的label*/
  restart_program:
    show_software_info("Error 測試程式");

#ifdef DISABLED
    testProcedure(
			"printErrorErrno()",
			test_printErrorErrno,
			"-",
			20);
#endif
		testProcedure("void abortError(void)", test_abortError, "-", 20);

    /*暫停程式運行（於main函式中）*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return EXIT_SUCCESS;
  }

  void test_printErrorErrno(void){
  	FILE *not_exist = NULL;

		not_exist = fopen("nonexist", "r");
		if(not_exist == NULL){
		  printErrorErrno("fopen()", errno);
		}

		/* Shouldn't use this code according to the following question:
		 * c - Why glibc's fclose(NULL) cause segmentation fault instead of returning error? - Stack Overflow
		 * http://stackoverflow.com/questions/16922871/why-glibcs-fclosenull-cause-segmentation-fault-instead-of-returning-error
		if(fclose(not_exist) == EOF){
			printError(errno);
		}
		 */
  	return;
  }

  void test_abortError(void){
  	abortError(ERROR_UNEXPECTED_CONDITION);
  	return;
  }
