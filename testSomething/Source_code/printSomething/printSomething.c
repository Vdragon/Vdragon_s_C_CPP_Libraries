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

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */

/* 主要程式碼
 * Main Code */
	void printLine(
		/* 線的組成成份 */
			const char component[],
		/* 線的長度 */
			const unsigned short length
	){
		register unsigned short i;

		for(i = 1; i <= length; ++i){
			printCstring(component);
		}

		/* FIXME: 要換成跨平台的版本 */
			putchar('\n');
		return;
	}
