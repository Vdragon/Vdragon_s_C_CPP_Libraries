/*程式框架(Program Framework)
-----------------------------------
程式框架版本(program framework version)：A
程式框架修訂號(program framework revision number)：201109251624
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
智慧財產授權條款：

*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/

/*////////程式所include的標頭檔(Included Headers)////////*/
	/* Standard C library */
		#include <stdio.h>

#include "pauseProgram/pauseProgram.h"
#include "askSomething/C/askSomething.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*main函式－Ｃ語言程式的進入點(entry point)
  版本：1.01(18)
    回傳值：
        0-正常結束程式
        其他值-不正常結束程式
*/
int main(void)
  {
  /*宣告與定義(Declaration & Definition)*/
  /*--函式雛型(function prototype)--*/
  /*暫停運行函式的function prototype*/

  /*--局域變數--*/

  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*程式從這個標籤重新啟動(program restarts from this label)*/
  restart_program:
  /* do something to input stream 來判斷 pauseProgram 能不能正確處理標準輸入緩衝問題 */{
  	int test;

  	askSignedInteger(&test);
  }

  /*呼叫暫停運行函式(放在main函式中)*/
  if(pauseProgram() == 1){
    goto restart_program;
  }
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*傳回數字０（表程式運行成功）*/
  return 0;
  }
