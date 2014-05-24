/*Heap_sort.c
-----------------------------------
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
/* this */
#include "Heap_sort.h"

/*Swap_algorithm*/
#include "../Swap_algorithm/Swap_algorithm.h"

/* Tree ADT */
#include "./Tree_abstract_data_type_Int/Tree_abstract_data_type_C.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

void heapSortInt(
  int array[],
  unsigned array_size,
  Sort_way how)
{
  Heap temp;
  temp.create = heapCreate;
  temp.create(&temp, 1, (how == INCREASINGLY)? MAX_HEAP : MIN_HEAP);
  temp.destroy(&temp);
  temp.heap = array - 1;
  temp.length = temp.size = array_size;

  /* build heap from array */
  heapBuildHeap(&temp);

  /* for last heap node to second heap node */{
    unsigned i;
    for(i = temp.length; i >= 2; --i){
      /* swap last node of heap with first (biggest) node*/
      swapInt(&temp.heap[i], &temp.heap[1]);

      /* heap_size - 1*/
      --temp.length;

      /* may violate the heap property, heap(v.) it again*/
      heapBuildHeap(&temp);
    }
  }
  /*done*/
  return;
}
