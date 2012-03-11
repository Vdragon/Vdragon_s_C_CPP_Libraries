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

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

/*Insertion sort（插入式排序演算法）函式
  版本：1.02(12)
  傳入值：array整數陣列、array_size陣列大小
  傳回值：無
  */
void insertionSort(int array[], unsigned array_size)
{
  /*宣告與定義(Declaration & Definition)*/
  /*--函式雛型(function prototype)--*/

  /*--局域變數--*/
  /*當前要插入的元素*/
  int current_insert_element;

  /*－－－－－－－－－－－－－－－－－－－－－*/
  {
    int final_insert_index;

    /*處理序列中第二個物件到最後一個物件的迴圈。完成此
     * 迴圈表示序列已經完成排序。*/
    unsigned i;
    for(i = 1; i < array_size; i++){
      /*用一個變數current_insert_element備份目前處理的物件的值。*/
      current_insert_element = array[i];

      /*用一個變數final_insert_index持有最後要插入目前處
       * 理的物件的index（索引）*/
      final_insert_index = i;

      /*從i到0尋找插入的位置（比較現在要插入的元素跟前面的元素的大小）*/
      while(final_insert_index != 0 &&
              array[final_insert_index - 1] >
              current_insert_element){
        /*將前面的元素移到後面*/
        array[final_insert_index] = array[final_insert_index - 1];
        /*判斷更前面的元素*/
        final_insert_index--;
      }

      /*插入現在要插入的元素*/
      array[final_insert_index] = current_insert_element;

    }
  }
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*傳回內容*/
  return ;
}
