/*程式框架(Program Framework)
-----------------------------------
程式名稱(program name)：。
程式描述(program description)：。
程式版本(program version)：0.00(0)
程式框架版本(program framework version)：A
程式框架修訂號(program framework revision number)：201109251624
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
智慧財產授權條款：
*//* Copyright (C) 2012 林博仁(Henry Lin)
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
#include "Swap_algorithm.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

/*maxHeapify函式
  版本：0.00(0)*/
void maxHeapify(int data[], unsigned array_size, unsigned current_index)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*--函式雛型(function prototype)--*/

    /*--局域變數--*/
    /*current largest node*/
    unsigned largest_index = current_index;

    /*the child index of current node may be*/
    unsigned left_child_index = current_index * 2,
            right_child_index = current_index * 2 + 1;
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*if left child exist and greater than current node*/
    if(left_child_index <= array_size - 1 &&
       data[left_child_index] > data[current_index]){
       largest_index = left_child_index;
    }

    /*if right child exist and greater than current node*/
    if(right_child_index <= array_size - 1 &&
       data[right_child_index] > data[current_index]){
       largest_index = right_child_index;
    }

    /*if largest node isn't current node then swap with the largest
      then maxheapify it's child*/
    if(largest_index != current_index){
      swapInt(&data[current_index], &data[largest_index]);
      maxHeapify(data, array_size, largest_index);
    }

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return ;
    }
