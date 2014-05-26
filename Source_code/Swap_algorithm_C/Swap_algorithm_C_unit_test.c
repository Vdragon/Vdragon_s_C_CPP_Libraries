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
	/* 自己的 header 檔案
		#include "SELF_NAME.h" */

	/* 標準Ｃ函式庫
	 * Standard C library
	 *   C library - C++ Reference
	 *   http://www.cplusplus.com/reference/clibrary/ */
		/* Definitions of functions to perform data input/output(I/O) operations
			#include <stdio.h>
			#include <cstdio> */
		/* Definitions of functions/constants that provides general utilities(that are otherwise homeless)
			#include <stdlib.h>
			#include <cstdlib> */
		/* C error number
			#include <errno.h>
			#include <cerrno> */
		/* C Diagnostics Library */
			#include <assert.h>
			/* #include <cassert> */
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
		/* <title>
			#include <<name>.h>
			#include <c<name>> */

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

	/* GNU gettext library
		#include <libintl.h> */

	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		/* function under test */
			#include "VCCL_Swap_algorithm_C.h"

/* 常數與巨集的定義
 * Definition of constants & macros */
	/* GNU gettext library
		#define _(Untranslated_C_string) gettext(Untranslated_C_string) */

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
void Swap_algorithm_C_unit_test(void){
	/* 測試 swapInteger() */{
		int integer_a = 123, integer_b = 246;

		swapInteger(&integer_a, &integer_b);
		assert(integer_a == 246 && integer_b == 123);
	}
	#if 0
	double double_a = 1.23, double_b = 2.46;
	long int long_integer_a = 12345, long_integer_b = 246810;
	unsigned int unsigned_integer_a = 123, unsigned_integer_b = 246;
	unsigned short int unsigned_short_integer_a = 12, unsigned_short_integer_b = 24;
	#endif
	return;
}
