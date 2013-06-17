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
	/* 自己 export 出去的定義 */
		#include "Error.h"

	/* 標準 C 函式庫 */
		#include <stdio.h>
		#include <string.h>
		/* for abort() */
			#include <stdlib.h>

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
	void printError(const char operation_name[], Error_reason why, const char self_defined_why[]){
		fprintf(stderr,
      "%s 操作發生錯誤！\n"
      "原因為：%s\n",
      operation_name,
      (why == ERROR_SELF_DEFINED) ?
      		self_defined_why :
      		error_reason_readable[why]);
		return;
	}

	void printErrorErrno(const char operation_name[], const int error_id){
		fprintf(stderr,
      "%s 操作偵測到錯誤！\n"
      "系統回報的錯誤原因為：%d - %s\n",
      operation_name, error_id, strerror(error_id));
		return;
	}

	void abortError(Error_reason why){
		fprintf(stderr,
				"因為「%s」程式必須異常中止。敬請見諒。\n"
				"請連繫開發者以解決此問題。\n"
				, error_reason_readable[why]);
		abort();
		return;
	}

#ifdef UNIMPLEMENTED
#endif
