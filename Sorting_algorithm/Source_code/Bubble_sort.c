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
/*Swap_algorithm*/
#include "Swap_algorithm/Swap_algorithm.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

  /*bubble sort函式
  傳入參數：一個int陣列data、一個const unsigned的data
          陣列大小、一個指向提供排序順序判斷的函式的指標
  傳回值：無*/
  void bubbleSort(int data[],
                    const unsigned array_size,
                    int (*sortOrderBool)(int a,
                                          int b))
      {

          /*次數計數器*/
          unsigned times;
          unsigned compare;

          /*從最後一個數被保證排序正確至第二個數被保證排序正確*/
          for(times = array_size - 1; times >= 1; times--){
              /*從第一個數至times的前一個數取compare與compare+1開始判斷*/
              for(compare = 0; compare <= times - 1; compare++){
                  /*如果compare大於compare+1就互換*/
                   if((*sortOrderBool)(data[compare], data[compare + 1])){
                      swapInt(&data[compare], &data[compare + 1]);
                   }
              }
          }
          return;
      }

  /*提供bubble sort遞增順序比較條件函式*/
  int sortAscendingly(int a, int b)
      {
          /*如果a小於b則不對調*/
          return (a < b)? 0 : 1;
      }

  /*提供bubble sort遞減順序比較條件函式*/
  int sortDescendingly(int a, int b)
      {
          /*如果a大於b則不對調*/
          return (a > b)? 0 : 1;
      }


