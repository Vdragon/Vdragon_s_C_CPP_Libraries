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

  /* Vdragons_C_CPP_Libraries_Collection
   * https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    /* for pausing program definition */
		  #include "pauseProgram/Pause_program.h"
    /* for showing software info */
		  #include "Show_software_info/Show_software_info.h"

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
  /*用來重新運行程式的label*/
  restart_program:
    show_software_info("printSomething 測試程式");

    /*暫停程式運行（於main函式中）*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return EXIT_SUCCESS;
  }
