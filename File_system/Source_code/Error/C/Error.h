/*
	程式名稱
	Program name */
		#define MODULE_NAME	 "Error processing library"
		#define MODULE_NAME_DOMAIN "org.vsdg.lib.vccl.error"
/*更新紀錄
	Changelog
		Changelog is now stored on GitHub(http://www.github.com)
	已知問題
	Known issues
		Known issues is now stored on GitHub(http://www.github.com)
	待辦事項
	Todos
		Todo is now stored on GitHub(http://www.github.com)
	著作權宣告
	Copyright declaration
		Copyright 2013 林博仁<pika1021@gmail.com>
	智慧財產授權條款
	Intellectual property license
		「程式名稱 | Program name」 is part of 「軟體名稱 | Software name」
		「軟體名稱 | Software name」 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

		「軟體名稱 | Software name」 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

		You should have received a copy of the GNU Lesser General Public License along with 「軟體名稱 | Software name」.  If not, see <http://www.gnu.org/licenses/>.
	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
	建議編輯器設定
	Recommended editor settings
		Indentation by tab character
		Tab character width = 2 space characters
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
	#ifndef VCCL_ERROR
		#define VCCL_ERROR
		/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
		#ifdef __cplusplus
			extern "C"{
		#endif /* __cplusplus */

		/* Forward declarations */

		/* 程式所 include 之函式庫的標頭檔
		   Included Library Headers */
			/* 標準Ｃ函式庫 */
			#include <stdio.h>

		/* 常數與巨集
		   Constants & Macros */

		/* Definition of data type, enumeration, data structure and class */
			typedef enum error_reason{
				ERROR_UNEXPECTED_CONDITION = 0,
				ERROR_SELF_DEFINED,
				ERROR_UNKNOWN,
				ERROR_NOT_IMPLEMENTED,
				ERROR_MEMORY_ALLOCATION_FAILED
			}Error_reason;

		/* 函式雛型
		   Function prototypes */
			void printError(
					const char operation_name[],
					Error_reason why,
				const char self_defined_why[]);
			void printErrorErrno(const char operation_name[], const int error_id);
			void printErrorReason(const Error_reason reason, FILE* target);
			void abortError(Error_reason why);
			void exitError(Error_reason why, unsigned int exit_status_code);
#ifdef UNIMPLEMENTED

#endif /* Unimplemented */
		/* 全域變數
		   Global variables */

		/* Inline 子程式的實作
		   Inline procedure implementations
		     限制
		     Limitations
		       C89 規範中不可用
		     參考資料
		     Reference resources
		       How do you tell the compiler to make a member function inline?, C++ FAQ
		       http://www.parashift.com/c++-faq-lite/inline-member-fns.html */

		#ifdef __cplusplus
			}
		#endif /* __cplusplus */
	#endif/* VCCL_ERROR */
