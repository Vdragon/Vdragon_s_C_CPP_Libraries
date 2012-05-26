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
#include <stdio.h>
#include <stdlib.h>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

/*合併式的排序演算法
 * 版本：1.00(0)201110052034
 * 傳入值：
 *  array
 *  start_index
 *  end_index
 * 傳回值：
 *  0 -> 成功
 *  -1 ->可用記憶體不足
 */
void mergeSort(int array[],
         const unsigned start_index,
        const unsigned end_index)
{
   /*合併並排序子陣列的函式prototype*/
   int mergeAndSort(int subArray[], unsigned start_index,
         unsigned half_index, unsigned end_index);

      if(end_index > start_index){
        unsigned half_index = (start_index + end_index) / 2;

        /* split array in half and sort each half recursively */
        mergeSort( array, start_index, half_index ); /* first half */
        mergeSort( array, half_index + 1, end_index ); /* second half */
        mergeAndSort( array, start_index, half_index, end_index);
      }

}

/*合併並排序子陣列的函式*/
int mergeAndSort(int subArray[], unsigned start_index,
      unsigned half_index, unsigned end_index)
{
  /*將兩子陣列資料複製到記憶體*/
  unsigned sizeA = half_index - start_index + 1,
            sizeB = end_index - half_index;

  int *memPtrA = (int *) malloc(sizeof(int) * sizeA);

  int *memPtrB = (int *) malloc(sizeof(int) * sizeB);

  if(memPtrA != NULL){
  }else{
    printf("失敗！請確定可用記憶體是否不足。\n");
    return -1;
  }

  {
  unsigned i;
  for(i = 0; i < sizeA; i++){
    memPtrA[i] = subArray[start_index + i];
  }

  }

  if(memPtrB != NULL){
  }else{
    printf("失敗！請確定可用記憶體是否不足。\n");
    return -1;
  }

  {
  unsigned i;
  for(i = 0; i < sizeB; i++){
    memPtrB[i] = subArray[half_index + 1 + i];
  }
  }

  {
  unsigned i;
  unsigned j = 0, k = 0;
  for(i = start_index; i <= end_index; i++){
    if(j != sizeA && k != sizeB){
      if(memPtrA[j] <= memPtrB[k]){
        subArray[i] = memPtrA[j];
        j++;
      }else{
        subArray[i] = memPtrB[k];
        k++;
      }
    }else{
      if(j == sizeA){
        subArray[i] = memPtrB[k];
        k++;
      }else{
        subArray[i] = memPtrA[j];
        j++;
      }
    }
  }
  }

  /*結束前清理*/
  free(memPtrA);
  free(memPtrB);

  return 0;
}
