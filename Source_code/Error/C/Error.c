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

	/* VCCL */
		#include "../../printSomething/printSomething.h"

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
			"\n"
      "%s 子程式發生錯誤！\n"
      "原因為：",
      operation_name);
		if(why == ERROR_SELF_DEFINED){
			fputs(self_defined_why, stderr);
		}else{
			printErrorReason(why, stderr);
		}
		fputc('\n', stderr);
		return;
	}

	void printErrorErrno(const char operation_name[], const int error_id){
		fprintf(stderr,
			"\n"
      "%s 子程式偵測到錯誤！\n"
      "系統回報的錯誤原因為：%d - %s\n",
      operation_name, error_id, strerror(error_id));
		return;
	}

	void printErrorReason(const Error_reason reason, FILE *target){
		switch(reason){
		case ERROR_UNEXPECTED_CONDITION:
			fputs("發生開發者未預期的狀況！請將導致此錯誤的使用程序通知開發者", target);
			break;
		case ERROR_SELF_DEFINED:
			fputs("發生開發者自行定義的問題", target);
			break;
		case ERROR_UNKNOWN:
			fputs("發生未知問題", target);
			break;
		case ERROR_NOT_IMPLEMENTED:
			fputs("功能尚未實作", target);
			break;
		case ERROR_MEMORY_ALLOCATION_FAILED:
			fputs("向系統要求配置記憶體失敗", target);
			break;
		default:
			/* 不明的錯誤編碼 */
			fputs("發生未知問題（接收到本版本函式庫未知的錯誤編碼）", target);
			exit(EXIT_FAILURE);
			break;
		}
		return;
	}

	void abortError(Error_reason why){
		/* 因為我們不能確定發生錯誤當時文字游標是否在列首，我們一律先換個列先 */
			fputc('\n', stderr);
		/* 畫一條線分隔前面的輸出訊息 */
			fprintLine(stderr, "-", 20);

		fprintf(stderr, "因為「");
		printErrorReason(why, stderr);
		fprintf(
			stderr,
			"」程式必須異常中止。敬請見諒。\n"
			"請連繫開發者以解決此問題。\n");
		abort();
		return;
	}

	void exitError(Error_reason why, unsigned int exit_status_code){
		/* 因為我們不能確定發生錯誤當時文字游標是否在列首，我們一律先換個列先 */
			fputc('\n', stderr);
		/* 畫一條線分隔前面的輸出訊息 */
			fprintLine(stderr, "-", 20); fputc('\n', stderr);
			fprintf(stderr, "因為「");
			printErrorReason(why, stderr);
			fprintf(
				stderr,
				"」程式必須異常中止。敬請見諒。\n"
				"請連繫開發者以解決此問題。\n");

		if(exit_status_code == EXIT_SUCCESS){
			/* 如果使用者傳 EXIT_SUCCESS 他們其實是想要 EXIT_FAILURE */
			exit(EXIT_FAILURE);
		}else{
			exit(exit_status_code);
		}
	}

#ifdef UNIMPLEMENTED
#endif
