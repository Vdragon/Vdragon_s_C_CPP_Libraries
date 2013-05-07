/*
	程式名稱
	Program name
		printSomething library
	更新紀錄
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
		printSomething library is part of Ｖ字龍的C、C++程式語言函式庫收集
		Ｖ字龍的C、C++程式語言函式庫收集 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

		Ｖ字龍的C、C++程式語言函式庫收集 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

		You should have received a copy of the GNU Lesser General Public License along with Ｖ字龍的C、C++程式語言函式庫收集.  If not, see <http://www.gnu.org/licenses/>.
	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
	建議編輯器設定
	Recommended editor settings
		Indentation by tab character
		Tab character width = 2 space characters
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
	#ifndef PRINTSOMETHING_H_INCLUDED
		#define PRINTSOMETHING_H_INCLUDED
		/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
		#ifdef __cplusplus
			extern "C"{
		#endif /* __cplusplus */

		/* Forward declarations */

		/* 程式所 include 之函式庫的標頭檔
		   Included Library Headers */
			/* 標準 C 函式庫 */
				#include <stdio.h>

		/* 常數與巨集
		   Constants & Macros */

		/* Definition of data type, enumeration, data structure and class */

		/* 函式雛型
		   Function prototypes */
			/* 印出一個 C 語言的字串 */
				inline void printCstring(const char c_string[]);

			/* 印出一條由成份字串組成的線 */
				void printLine(
					/* 線的組成成份 */
						const char component[],
					/* 線的長度 */
						unsigned short length
				);

		/* 全域變數
		   Global variables */

		/* Inline 子程式的實作
		   Inline procedure implementations */
				inline void printCstring(const char c_string[]){
					printf("%s", c_string);

					return;
				}

		#ifdef __cplusplus
			}
		#endif /* __cplusplus */
	#endif/* PRINTSOMETHING_H_INCLUDED */
