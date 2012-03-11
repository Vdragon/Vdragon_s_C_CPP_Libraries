/*Randomize_algorithm.c
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
/*we need srand() and rand()*/
#include <stdlib.h>

/*we need time()*/
#include <time.h>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
  void randomizeArray(int array_source[], /*the source array*/
                      const unsigned array_size, /*array size*/
                      const int min_result, /*the minimum value to exist*/
                      const int max_result /*the maximum value to exist, if you put 3, it may generate 3.*/)
  {
    /*counters*/
    unsigned i;

    /*initialize random number generator*/
    srand(time(NULL));

    /*for first index to last index, assign random number to array*/
    for (i = 0; i < array_size; ++i) {
      /*result = min + rand() % (max - min + 1)*/
      array_source[i] = min_result + rand() % (max_result - min_result + 1);
    }

    /*done*/
    return;
  }
