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
	/* 自己 */
		#include "printSomething.h"

	/* 標準 C 函式庫 */
		#include <stdio.h>
		#include <errno.h>

#if defined(__unix) || defined(__unix__)
	/* POSIX API(Unix only) */
		#include <unistd.h>

	/* limits.h for PATH_MAX */
		#include <linux/limits.h>
#endif

	/* GNU gettext library */
		#include <libintl.h>

	/* VCCL */
		#include "../Error/C/Error.h"

/* 常數與巨集
 * Constants & Macros */
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */
	void printSomething_checkGettext(void);
/* 全域變數
 * Global Variables */
	short gettext_is_initialized = 0;

/* 主要程式碼
 * Main Code */
	void printSomething_checkGettext(void){
		if(gettext_is_initialized == 0){
			bindtextdomain(VCCL_printSomething, "Translations");
			gettext_is_initialized = 1;
		}
		return;
	}
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

	void fprintMessageDebug(FILE *output_stream, const char message[]){
		printSomething_checkGettext();

#ifndef NDEBUG
		fputs(_("除錯用訊息："), output_stream);
		fputs(message, output_stream);
		fputc('\n', output_stream);
#endif
		return;
	}

	void printMessageDebug(const char message[]){
		fprintMessageDebug(stdout, message);
		return;
	}
#if defined(__unix) || defined(__unix__)
	void printCurrentWorkingDirectory(void){
		char buffer[PATH_MAX];

		if(getcwd(buffer, sizeof(buffer)) == NULL){
			printErrorErrno("getcwd", errno);
		}
		fputs(buffer, stdout);
		return;
	}
#endif
