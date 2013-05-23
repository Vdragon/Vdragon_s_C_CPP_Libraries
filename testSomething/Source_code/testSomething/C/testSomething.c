/*
	請見本檔案的 header 檔案以得到更多關於本檔案的說明

	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
	建議編輯器設定
	Recommended editor settings
		Indentation by tab character
		Tab character width = 2 space characters
*/
/* 程式所 include 之函式庫的標頭檔
 * Included Library Headers */
	/* Vdragons_C_CPP_Libraries_Collection */
		/* for printLine() */
			#include "../../printSomething/printSomething.h"

	/* Standard C Library */
		/* for printf() */
			#include <stdio.h>

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage
       預先告訴編譯器(compiler)子程式的存在 */

/* 全域變數
 * Global Variables */

/* 函式的實作
 * Function implementations */
	/* 測試函式的函式 */
		void testProcedure(
			/* 函式名稱 */
				const char name[],
			/* 函式指標變數 */
				void (*proc_under_test)(void),
			/* 用來分隔測試中函式的輸出的線的組成成份（直接傳至 printLine()） */
				const char line_component[],
			/* 用來分隔測試中函式的輸出的線的長度（直接傳至 printLine()） */
				const unsigned short line_length){
			printf("開始測試 %s：\n", name);
			printLine(line_component, line_length);
			(*proc_under_test)();
			printLine(line_component, line_length);
			return;
		}
