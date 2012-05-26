
/*--------------程式碼開始(Code Started)--------------*/
/*--------------前置處理器選項(Preprocessor Code)--------------*/
/*程式所include的標頭檔(Included Headers)*/
/*standard input/output library*/
#include <stdio.h> /*for printf(), scanf(), fgetc()*/
/*C Standard General Utilities Library*/
#include <stdlib.h>

/**/
#include "pauseProgram/Pause_program.h"
/**/
#include "Graph_abstract_data_type/Graph_abstract_data_type.list.h"

/*環境設定(Environment Settings)*/

/*----常數與巨集(Constants & Macros)----*/

/*堆疊(Stack)*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*----資料結構(Structures), typedefs, enums----*/

/*----函式原型(Function Prototypes)----*/

/*----全域變數(Global Variables)----*/

/*--------------主要程式碼(Main Code)--------------*/
/*main函式
  版本：1.00(0)
  程式的運行從main函數開始*/
int main(void)
	{
  /*程式從這個標籤重新啟動(program restarts from this label)*/
  restart_program:

  graphUnitTest();


  /*呼叫暫停運行函式(放在main函式中)*/
  if(pauseProgram() == 1){
      goto restart_program;
  }

	/*－－－－－－－－－－－－－－－－－－－－－*/
	/*傳回數字０（表程式運行成功）*/
	return 0;
	}

