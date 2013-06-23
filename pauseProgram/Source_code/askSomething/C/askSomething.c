/* 
	請見本檔案的標頭(header)檔案以得到更多關於本檔案的說明
	
	本程式的框架基於「C/C++ 程式範本」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
	建議編輯器設定
	Recommended editor settings
		Indentation by tab character
		Tab character width = 2 space characters
*/
/* 程式所引入(include)之函式庫的標頭(header)檔案
 * Included library headers */
	/* 自己的 header 檔案 */
		#include "askSomething.h"
		
	/* 標準 C 函式庫
	 * Standard C libraries
	 *   C library - C++ Reference
	 *   http://www.cplusplus.com/reference/clibrary/ */
		/* C library to perform Input/Output operations			#include <cstdio> */
			#include <stdio.h>

		/* C Standard General Utilities Library
			#include <stdlib.h>
			#include <cstdlib> */
		/* C error number 
			#include <errno.h>
			#include <cerrno> */
		/* C Diagnostics Library
			#include <assert.h>
			#include <cassert> */
		/* C Character handling functions
			#include <ctype.h>
			#include <cctype> */
		/* Characteristics of floating-point types
			#include <float.h>
			#include <cfloat> */		
		/* ISO 646 Alternative operator spellings
			#include <iso646.h>
			#include <ciso646> */
		/* Sizes of integral types
			#include <limits.h>
			#include <climits> */
		/* C localization library
			#include <locale.h>
			#include <clocale> */
		/* C numerics library
			#include <math.h>
			#include <cmath> */
		/* Non local jumps
			#include <setjmp.h>
			#include <csetjmp> */
		/* C library to handle signals
			#include <signal.h>
			#include <csignal> */
		/* Variable arguments handling
			#include <stdarg.h>
			#include <cstdarg> */
		/* Boolean type(C99 or later)
			#include <stdbool.h>
			#include <cstdbool> */
		/* C Standard definitions
			#include <stddef.h>
			#include <cstddef> */
		/* Integer types(C++11 later)
			#include <stdint.h>
			#include <cstdint> */
		/* C Strings
			#include <string.h>
			#include <cstring> */
		/* C Time Library
			#include <time.h>
			#include <ctime> */
		/* Unicode characters handling library(C++11 later)
			#include <uchar.h>
			#include <cuchar> */
		/* Wide characters handling library
			#include <wchar.h>
			#include <cwchar> */
		/* Wide character type
			#include <wctype.h>
			#include <cwctype> */
		/* Type-generic math(non C89)
			#include <tgmath.h>
			#include <ctgmath> */
		/* 
			#include <.h>
			#include <c> */
		
	/* 標準 C++ 函式庫 */
		/* Input/Output related */
			/* Standard Input / Output Streams Library
				#include <iostream> */
			/* Input/output file stream class
				#include <fstream> */
		/* Container */
			/* list
				#include <list> */
		/* Unclassified */
			/* Strings
				#include <string> */
			/* Standard Template Library: Algorithms
				#include <algorithm> */
			/* 
				#include <> */
	
	/* GNU gettext library */
		#include <libintl.h>
		
	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		
	
/* 常數與巨集的定義
 * Definition of constants & macros */
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)

/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage 
       預先告訴編譯器(compiler)子程式的存在 */

/* 全域變數
 * Global Variables */

/* 函式的實作
 * Function implementations */
	AskSomething_answer askSignedInteger(int *storage){
		int return_status = -1;
		char format_control[] = "%d%*c";

		printf("請輸入一個有負號整數：");
		if((return_status = scanf(format_control, storage)) != 1){
			fflush(stdout);
			fprintf(stderr, _(
				"\n" /* 避免跟提示文字同列 */
				"["PROGRAM_NAME_READABLE"]scanf() 發生錯誤！\n"
				"["PROGRAM_NAME_READABLE"]格式控制字串為 \"%s\"，但是 scanf() 只有從標準輸入裝置成功讀取到 %d 個變數內容。\n"), format_control, return_status);
			return ASKSOMETHING_FAIL;
		}
#if 0
    /* 標準 C 函式庫的 */
    if(scanf("%*c") > 0){
#ifndef _NDEBUG
			printf("[DEBUG]input stream cleared!");
#endif // _NDEBUG

    };
    #endif

		return ASKSOMETHING_SUCCESS;
	}

	AskSomething_answer askSignedDouble(double *storage){
		int return_status = -1;
		char format_control[] = "%lf";

		printf("請輸入一個有負號浮點數：");
		if((return_status = scanf(format_control, storage)) != 1){
			fflush(stdout);
			fprintf(stderr, _(
				"\n" /* 避免跟提示文字同列 */
				"["PROGRAM_NAME_READABLE"]scanf() 發生錯誤！\n"
				"["PROGRAM_NAME_READABLE"]格式控制字串為 \"%s\"，但是 scanf() 只有從標準輸入裝置成功讀取到 %d 個變數內容。\n"), format_control, return_status);
			return ASKSOMETHING_FAIL;
		}
		return ASKSOMETHING_SUCCESS;
	}
