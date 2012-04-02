/*Stack抽像資料類型測試程式
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  Stack抽像資料類型測試程式 is part of Stack抽像資料類型
  Stack抽像資料類型 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stack抽像資料類型 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Stack抽像資料類型.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要可移植的狀態碼*/
#include <cstdlib>

/*我們需要library*/
#include "Stack_abstract_data_type/Stack_abstract_data_structure_C.h"

/**/
#include "Project_specific_configurations/Max_value.h"

/**/
#include "Show_software_info/Show_software_info.h"

/**/
#include "pauseProgram/Pause_program.h"

/*我們需要stack元素的定義*/
#include "Test_program.h"

/**/
#include <cstdio>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
int main()
{
/*用來重新運行程式的label*/
restart_program:

  /**/
  show_software_info((char*)"Stack抽像資料類型測試程式");


  /*單元測試*/
  if(!stackUnitTest()){
    printf("Stack 抽像資料類型單元測試全部通過！\n");
  }else{
    printf("Stack 抽像資料類型單元測試失敗！\n");
  }

  /*呼叫暫停運行函式(放在main函式中)*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /* EXIT*/
  return EXIT_SUCCESS;
}

/*單元測試函式*/
short stackUnitTest(void)
{

  /*宣告一個堆疊(Stack)*/
  StackElement test01[MAX_STACK_SIZE];

  /*指向堆疊top位置指標或註標(subscript)*/
  int stack_top01 = -1;

  /*counter*/
  unsigned i;

  /*test Result*/
  short result;

  /*測試stack_push*/
  for(i = 0; i <= MAX_STACK_SIZE; ++i){
    result = stackPush(i, test01, &stack_top01, MAX_STACK_SIZE);
    if(i < MAX_STACK_SIZE){
      if(result == -1){
        return -1;
      }
    }else{
      if(result == 0){
        return -1;
      }
    }
  }
  /*測試stack_pop*/
  for(i = 0; i <= MAX_STACK_SIZE; ++i){
    int buffer01;
    if(i == MAX_STACK_SIZE){
      putchar('\n');
    }
    buffer01 = stackPop(test01, &stack_top01, &result);

    if(i < MAX_STACK_SIZE){
      printf("%d  ", buffer01);
      /*FIXME:unknown "警告： 在有號和無號整數運算式間比較 [-Wsign-compare]*/
      if(result == -1 || buffer01 != (MAX_STACK_SIZE - 1) - i){
        putchar('\n');
        return -1;
      }
    }else{

      if(result == 0){
        return -1;
      }
    }
  }

  /*success*/
  return 0;
}
