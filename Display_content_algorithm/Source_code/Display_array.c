/*Display_array.c
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
著作權宣告：
  Copyright 2012 林博仁(Henry Lin)
智慧財產授權條款：
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/

/*////////程式所include的標頭檔(Included Headers)////////*/
/* we need printf()*/
#include <stdio.h>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
void displayArrayInt(const int source[] , /*source_array*/
                      const unsigned source_size, /*array size*/
                      const unsigned item_field_width, /*field width of all items*/
                      const char delimit_character_sequence[], /*character sequence to apart 2 items*/
                      const unsigned items_per_line) /*how many items to show in one line*/
{
  /*counters*/
  unsigned i;

  /*for first item to last item, display them*/
  for (i = 0; i < source_size; ++i) {
    /*print item*/
    printf("%*d", item_field_width, source[i]);

    /*if not last item or last item of the line, print delimit string*/
    if(!(i == source_size - 1 || (i + 1) % items_per_line == 0)){
      printf("%s", delimit_character_sequence);
    }

    /*if the item is the last item of the line, print end of line sequence*/
    if((i + 1) % items_per_line == 0){
      putchar('\n');
    }
  }

  /*if the item is the last item of the array, print end of line sequence*/
  putchar('\n');

  /*done*/
  return;
}
