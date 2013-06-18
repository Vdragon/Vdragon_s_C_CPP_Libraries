/*
	printSomething 測試程式

	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
*/
/* 程式所 include 之函式庫的標頭檔
 * Included Library Headers */
	/* Standard C/C++ library */
    /* for EXIT_* return code definition */
		  #include <stdlib.h>
		#include <stdio.h>


  /* Vdragons_C_CPP_Libraries_Collection
   * https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    /* for pausing program definition */
		  #include "pauseProgram/Pause_program.h"
    /* for showing software info */
		  #include "Show_software_info/Show_software_info.h"

	/* Library under test */
		#include "printSomething/printSomething.h"

/* 常數與巨集
 * Constants & Macros */
/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */

/* 主要程式碼
 * Main Code */
  int main(int argc, char *argv[]){
  	/* unit test functions */
  		void test_printCstring(void);
  		void test_printLine(void);
  		void test_fprintLine(void);
#if defined(__unix) || defined(__unix__)
			void test_printCurrentWorkingDirectory(void);
#endif
  /*用來重新運行程式的label*/
  restart_program:
    show_software_info("printSomething 測試程式");

		test_printCstring();
		printLine("#", 20);
		test_printLine();
		test_printCurrentWorkingDirectory();
		test_fprintLine();

    /*暫停程式運行（於main函式中）*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return EXIT_SUCCESS;
  }

	void test_printCstring(void){
		printCstring("");
		printCstring("\n");
		printCstring("Longer");
		putchar('\n');
		return;
	}

	void test_printLine(void){
		printLine("-", 20);
		printLine("##", 10);
		printLine("喵", 10);
		return;
	}

	void test_fprintLine(void){
		fprintLine(stderr, "=", 20);
		return;
	}
#if defined(__unix) || defined(__unix__)
	void test_printCurrentWorkingDirectory(void){
		printf("目前的工作目錄為：");
		printCurrentWorkingDirectory();
		printf("。\n");
		return;
	}
#endif
