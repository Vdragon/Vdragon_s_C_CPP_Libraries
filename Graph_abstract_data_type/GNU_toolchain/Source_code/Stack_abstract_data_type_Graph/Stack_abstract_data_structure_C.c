/*Stack_abstract_data_structure_C.c
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
  Stack_abstract_data_structure_C.c is part of Stack抽象資料類型
  Stack抽象資料類型 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stack抽象資料類型 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Stack抽象資料類型.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*we need our header file*/
#include "Stack_abstract_data_structure_C.h"

/**/
#include "../Messages_templates/zh_TW.h"

/**/
#include <stdio.h>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

//判斷堆疊是否為空函式
//版本：1.00(0)
short int stackIsEmpty(int stack_top)
  {
    return (stack_top == -1) ? 1 : 0;
  }
//判斷堆疊是否已滿函式
//版本：1.00(0)
short int stackIsFull(int stack_top, unsigned max_stack_size)
  {
    return (stack_top == max_stack_size - 1) ? 1 : 0;
  }

//將元素push至堆疊的函式
short int stackPush(StackElement item, StackElement stack[], int *stack_top, unsigned max_stack_size)
    {
    //宣告與定義(Declaration & Definition)
    //－－－－－－－－－－－－－－－－－－－－－
    //如果堆疊已滿就錯誤離開
    if(stackIsFull(*stack_top, max_stack_size)){
        printf(ERROR_TAG STACK_ADT_PUSH_TAG
               ERROR_STACK_PUSH_WHEN_FULL
               DEBUG_TAG "位於原始程式碼：" __FILE__ " 第%d行。\n", __LINE__);
        return -1;
    }
    /*將元素插入堆疊中*/
    stack[++*stack_top] = item;

    /*push操作完成*/
    return 0;
    }

//將元素pop出堆疊的函式
//版本：1.00(0)
StackElement stackPop(StackElement stack[], int *stack_top, short * return_status)
    {
    //宣告與定義(Declaration & Definition)
    //－－－－－－－－－－－－－－－－－－－－－
    //如果堆疊為空就錯誤離開
    if(stackIsEmpty(*stack_top)){
      StackElement need_not_initialize;

      printf(ERROR_TAG STACK_ADT_PUSH_TAG
             ERROR_STACK_POP_WHEN_EMPTY
             DEBUG_TAG "位於原始程式碼：" __FILE__ " 第%d行。\n", __LINE__);
        *return_status = -1;

        return need_not_initialize;
    }else{
      *return_status = 0;
      //傳回top位置的元素並遞減top
      return stack[(*stack_top)--];
    }
    }

