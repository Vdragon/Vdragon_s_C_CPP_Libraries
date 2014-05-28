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
		#include "Unit_test.hpp"

	/* 標準 C 函式庫
	 * Standard C libraries
	 *   C library - C++ Reference
	 *   http://www.cplusplus.com/reference/clibrary/ */
		/* C library to perform Input/Output operations
			#include <stdio.h>
			#include <cstdio> */
		/* C Standard General Utilities Library
			#include <stdlib.h> */
			#include <cstdlib>
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
#if 0
	/* GNU gettext library */
		#include <libintl.h>
#endif
	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		#include "pauseProgram/pauseProgram.h"
		#include "showSoftwareInfo/showSoftwareInfo.h"
		/* #include "Project_specific_configurations/GNU_gettext_library.h" */

/* 常數與巨集的定義
 * Definition of constants & macros */
#if 0
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)
#endif
/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage
       預先告訴編譯器(compiler)子程式的存在 */

/* 全域變數
 * Global Variables */
	/* 定義於 showSoftwareInfo */
		extern Software_information global_software_information;
/* 函式的實作
 * Function implementations */
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
#if 0
    	/* 初始化 GNU gettext 函式庫 */
				/* Use system default locale instead of "C" locale */
					setlocale(LC_MESSAGES, "");
				bindtextdomain(MESSAGE_DOMAIN, LOCALEDIR);
				textdomain(MESSAGE_DOMAIN);
				bind_textdomain_codeset(MESSAGE_DOMAIN, MESSAGE_CHARSET);
#endif
    /*用來重新運行程式的label*/
    restart_program:
			global_software_information.software_name = "Ｖ字龍的Ｃ、Ｃ＋＋函式庫蒐集";
			global_software_information.software_official_website = "https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection/";
			global_software_information.software_issue_tracker = "https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection/issues";
			global_software_information.software_developer_name = "Ｖ字龍";
			global_software_information.software_developer_email = "pika1021@gmail.com";
			global_software_information.software_copyright_valid_year = 2014;
			global_software_information.software_license = SOFTWARE_LICENSE_LGPL;
			global_software_information.software_license_version = "3";
			global_software_information.software_license_version_or_later = 1;
			global_software_information.software_license_other_url = NULL;
			global_software_information.software_license_other_name = NULL;
			
      showSoftwareInfo(/* _(*/PROGRAM_MAIN_NAME/*)*/);

      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }

      return EXIT_SUCCESS;
    }
