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
	/* 自己
		#include "printSomething.h" */

	/* 標準 C 函式庫 */
		#include <stdio.h>

#if defined(__unix) || defined(__unix__)
	/* POSIX API(Unix only) */
		#include <unistd.h>

	/* limits.h for PATH_MAX */
		#include <linux/limits.h>
#endif

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */

/* 主要程式碼
 * Main Code */
	void printCstring(const char c_string[]){
		printf("%s", c_string);

		return;
	}

	void fprintCstring(FILE *output_stream, const char c_string[]){
		fputs(c_string, output_stream);

		return;
	}

	void printLine(
		/* 線的組成成份 */
			const char component[],
		/* 線的長度 */
			const unsigned short length
	){
		register unsigned short i;

		for(i = 1; i <= length; ++i){
			fputs(component, stdout);
		}

		putchar('\n');
		return;
	}

	void fprintLine(
		/* 輸出資料流 */
			FILE *output_stream,
		/* 線的組成成份 */
			const char component[],
		/* 線的長度 */
			unsigned short length
	){
		register unsigned short i;

		for(i = 1; i <= length; ++i){
			fputs(component, output_stream);
		}

		putchar('\n');
		return;
	}

#if defined(__unix) || defined(__unix__)
	void printCurrentWorkingDirectory(void){
		char buffer[PATH_MAX];

		getcwd(buffer, sizeof(buffer));
		fputs(buffer, stdout);
		return;
	}
#endif
