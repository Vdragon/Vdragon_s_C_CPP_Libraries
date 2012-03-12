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
/*節點 i 的父母節點(parent node)*/
#define INDEX_PARENT(i) i >> 1

/*節點 i 的left right children node*/
#define INDEX_LEFT_CHILD(i) (i << 1)
#define INDEX_RIGHT_CHILD(i) (i << 1) + 1

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/


  void maxHeapifyInt(int heap[], /*integer heap array*/
                  const unsigned heap_size, /*heap size, *not* array size 15*/
                  const unsigned parent_index) /*index of parent node(to be heapified)*/
    {
    /*宣告與定義(Declaration & Definition)*/
    /*--函式雛型(function prototype)--*/

    /*--局域變數--*/
    /*current largest node, presuming parent*/
    unsigned largest_index = parent_index + 1;

    /*the child index of current node may be*/
    unsigned left_child_index = INDEX_LEFT_CHILD(largest_index),
            right_child_index = INDEX_RIGHT_CHILD(largest_index);
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*if left child exist and greater than current node*/
    if(left_child_index <= heap_size &&
       heap[left_child_index - 1] > heap[largest_index - 1]){
       largest_index = left_child_index;
    }

    /*if right child exist and greater than current node*/
    if(right_child_index <= heap_size &&
       heap[right_child_index - 1] > heap[largest_index - 1]){
       largest_index = right_child_index;
    }

    /*if largest node isn't current node then swap with the largest
      then maxheapify the child which gets the parent node(which may violating the heap property)*/
    if(largest_index != parent_index + 1){
      swapInt(&heap[parent_index], &heap[largest_index - 1]);
      maxHeapifyInt(heap, heap_size, largest_index - 1);
    }

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*done*/
    return ;
    }

  /*buildMaxHeapInt function prototype
      build a max heap by calling maxHeapify from the last
      non-leaf node to root node*/
void buildMaxHeapInt(int heap[], /*heap array*/
                     const unsigned heap_size /*heap size, *not* array size*/)
{
    /*counters*/
    int i;

    /*for last non-leaf node to root*/
    for (i = (heap_size / 2 - 1); i >= 0; --i) {
      maxHeapifyInt(heap, heap_size, i);
    }

    /*done*/
    return;
}

void heapSort(int heap[],
              unsigned * heap_size)
{
  /*counters*/
  unsigned i;

  /* build max heap from array */
  buildMaxHeapInt(heap, *heap_size);

  /*for last heap node to second heap node*/
  for(i = *heap_size; i >= 2; --i){
    /* swap last node of heap with first (biggest) node*/
    swapInt(&heap[i - 1], &heap[0]);

    /* heap_size - 1*/
    --*heap_size;

    /* may violate the heap property, max-heapify it again*/
    maxHeapifyInt(heap, *heap_size, 0);
  }

  /*done*/
  return;
}
