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
		#include "main.hpp"

	/* 標準 C 函式庫
	 * Standard C libraries
	 *   C library - C++ Reference
	 *   http://www.cplusplus.com/reference/clibrary/ */
		/* C library to perform Input/Output operations
			#include <stdio.h> */
			#include <cstdio>
		/* C Standard General Utilities Library
			#include <stdlib.h> */
			#include <cstdlib>
		/* C error number
			#include <errno.h> */
			#include <cerrno>
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
			#include <locale.h> */
			#include <clocale>
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
			/* Standard Input / Output Streams Library */
				#include <iostream>
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
		using namespace std;

	/* GNU gettext library */
		#include <libintl.h>

	/* Ｖ字龍的 C／C++ 程式語言函式庫
	 * Vdragon's C/CPP Libraries */
		#include "pauseProgram/pauseProgram.h"
		#include "showSoftwareInfo/showSoftwareInfo.h"
		#include "Project_specific_configurations/GNU_gettext_library.h"
		#include "testSomething/C/testSomething.h"
		#include "Error/C/Error.h"

	/* 測試中模組 */
		#include "File_system/CPP/File_system.hpp"

#if defined(__unix__) || defined(__unix)
	/* POSIX API */
		/* for stat(2) */
			#include <sys/types.h>
			#include <sys/stat.h>
			#include <unistd.h>
#endif //Unix system only

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
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
    	/* 測試函式 */
#if defined(__unix__) || defined(__unix)
    		void test_isDirectory(void);
    		void test_printItemType(void);
    		void test_printWhoPermission(void);
    		void test_printItemPermission(void);
    		void test_printItemOwnership(void);
    		void test_showPathInfo(void);
#endif

    	/* 初始化 GNU gettext 函式庫 */
				/* Use system default locale instead of "C" locale
				 * FIXME: 中文訊息變成問號，原因不明
					setlocale(LC_MESSAGES, ""); */
				bindtextdomain(MESSAGE_DOMAIN, LOCALEDIR);
				textdomain(MESSAGE_DOMAIN);
				bind_textdomain_codeset(MESSAGE_DOMAIN, MESSAGE_CHARSET);

    /*用來重新運行程式的label*/
    restart_program:
      showSoftwareInfo(_(PROGRAM_MAIN_NAME));
#if defined(__unix__) || defined(__unix)
      testProcedure("isDirectory", test_isDirectory, "-", 20);
      testProcedure("printWhoPermission", test_printWhoPermission, "-", 20);
      testProcedure("printItemPermission", test_printItemPermission, "-", 20);
      testProcedure("printItemOwnership", test_printItemOwnership, "-", 20);
      testProcedure("showPathInfo", test_showPathInfo, "-", 20);
      testProcedure("printItemType", test_printItemType, "-",20);
#endif // Unix only
      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }

      return EXIT_SUCCESS;
    }
#if defined(__unix__) || defined(__unix)
    void test_isDirectory(void){
			if(isDirectory("Resources")){
				cout << "Res is directory." << endl;
			}
			if(isDirectory("README.md") == false){
				cout << "Readme is NOT directory." << endl;
			}
    	return;
    }

    void test_printItemType(void){
    	struct stat item_status;
    	string item_name;

    	item_name = "README.md";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
    		printItemType(SHORT, item_status.st_mode);
				putchar('\n');
    	}
    	putchar('\n');
    	item_name = "Build";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
    		printItemType(SHORT, item_status.st_mode);
				putchar('\n');
    	}
    	putchar('\n');
    	return;
    }

    void test_printWhoPermission(void){
    	struct stat item_status;
    	string item_name;

    	item_name = "README.md";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
				printWhoPermission(SHORT, OWNER, item_status.st_mode);
				printWhoPermission(SHORT, GROUP, item_status.st_mode);
				printWhoPermission(SHORT, OTHER, item_status.st_mode);
				putchar('\n');
    	}
    	putchar('\n');

    	item_name = "/usr/bin/passwd";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
				printWhoPermission(SHORT, OWNER, item_status.st_mode);
				printWhoPermission(SHORT, GROUP, item_status.st_mode);
				printWhoPermission(SHORT, OTHER, item_status.st_mode);
				putchar('\n');
    	}
    	putchar('\n');

    	item_name = "/tmp";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
				printWhoPermission(SHORT, OWNER, item_status.st_mode);
				printWhoPermission(SHORT, GROUP, item_status.st_mode);
				printWhoPermission(SHORT, OTHER, item_status.st_mode);
				putchar('\n');
    	}
    	return;
    }

    void test_printItemPermission(void){
    	struct stat item_status;
    	string item_name;

    	item_name = "README.md";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
    		printItemPermission(SHORT, item_status.st_mode); putchar('\n');
    		printItemPermission(OCTAL, item_status.st_mode); putchar('\n');
    	}
    	putchar('\n');

    	item_name = "/usr/bin/passwd";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
    		printItemPermission(SHORT, item_status.st_mode); putchar('\n');
    		printItemPermission(OCTAL, item_status.st_mode); putchar('\n');
    	}
    	putchar('\n');

    	item_name = "/tmp";
    	cout << item_name << ":" << endl;
    	if(stat(item_name.c_str(), &item_status) != 0){
    		printErrorErrno("stat()", errno);
    	}else{
    		printItemPermission(SHORT, item_status.st_mode); putchar('\n');
    		printItemPermission(OCTAL, item_status.st_mode); putchar('\n');
    	}
    	return;
    }

    void test_printItemOwnership(void){
    	printItemOwnership(DECIMAL, 12345, 12345);putchar('\n');
    	printItemOwnership(LONG, 12345, 12345);putchar('\n');
    	return;
    }

    void test_showPathInfo(void){
    	showPathInfo(string("README.md"));
    	showPathInfo(string("/usr/bin/passwd"));
    	showPathInfo(string("/home/Vdragon/工作空間/Programming/Libraries/Vdragons_C_CPP_Libraries_Collection/File_system/Source_code/main.cpp"));
    	return;
    }
#endif //Unix system only
