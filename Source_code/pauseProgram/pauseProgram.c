/*Pause_program.c
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todos)：
  Todos is now stored on github
智慧財產授權條款：
*//* Copyright (C) 2012, 2013 林博仁(Henry Lin)
   *
   * This library is free software; you can redistribute it and/or
   * modify it under the terms of the GNU Lesser General Public
   * License as published by the Free Software Foundation version 2.1
   * of the License.
   *
   * This library is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   * Lesser General Public License for more details.
   *
   * You should have received a copy of the GNU Lesser General Public
   * License along with this library; if not, write to the Free Software
   * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
   */

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/

/*////////程式所include的標頭檔(Included Headers)////////*/
/* we need printf and scanf*/
  #include <stdio.h>
#ifdef __gnu_linux__
	#include <stdio_ext.h>
#endif

/* we need system() */
  #include <stdlib.h>

/* definitions of Standard C character handling functions */
	#include <ctype.h>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/
	int generic_return_value;

/*--------------主要程式碼(Main Code)--------------*/
/* 暫停運行函式 */
short int pauseProgram(void){
	char inputChar;

	printf(
		"\n"
		"------------------------------------------------\n"
		"顯示運行結果，程式暫停運行...\n"
		"Program paused for displaying execution result...\n");

	/* 迴避 input stream 殘留行結尾字元造成詢問訊息重覆印出的解決方案 */{
#ifdef __gnu_linux__
		/* glibc 實作了 __fpurge(3) 可以清除 input buffer */
			__fpurge(stdin);

#else
		fputs("（如果程式卡在此句末端請按 Enter 鍵繼續）", stdout);
		if(scanf("%*c") > 0){
	#ifndef _NDEBUG
			printf("[DEBUG]input stream successfully cleared!");
	#endif /* _NDEBUG */
		}
#endif
	}

	do{
		printf(
			"請問您要重新運行本程式嗎（Ｙ／Ｎ）？\n"
			"Do you want to execute this program again(Y/N)?");

		/* 確保輸入是正確的 */
			inputChar = tolower(getchar());
			if(inputChar == 'y' || inputChar == 'n'){
				break;
			}
	}while(1);

	if(inputChar == 'y'){
		/* 可行的話清空螢幕 */{
#ifdef _WIN32
			generic_return_value = system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix)
			generic_return_value = system("clear");
	#ifndef _NDEBUG
			printf("[DEBUG]__unix__ cleared the screen!\n");
	#endif /* _NDEBUG */
#else
			generic_return_value = system("clear");
	#ifndef _NDEBUG
			printf("[DEBUG]__else__ cleared the screen!\n");
	#endif /* _NDEBUG */
#endif /* _WIN32 */

			if(generic_return_value != 0){
				fprintf(
					stderr,
					"【警告】清除螢幕失敗！\n"
					"【警告】回傳碼為 %d\n", generic_return_value);
			}
		}
			/*return true*/
			return 1;
		}

	/*return false*/
	return 0;
}
