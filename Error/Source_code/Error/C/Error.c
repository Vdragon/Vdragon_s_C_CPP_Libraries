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
	/* 標準 C 函式庫 */
		#include <stdio.h>
		#include <string.h>

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
	void printError(int error_id){
		printf(
      "偵測到錯誤！\n"
      "系統回報的錯誤原因為：%d - %s\n", error_id, strerror(error_id));
		return;
	}
