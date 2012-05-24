/* ====標準C函式庫==== */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* this */
#include "Tree_abstract_data_type_C.h"

/* Vdragon's Library Collection */
#include "../../Messages_templates/zh_TW.h"
#include "Swap_algorithm_heap_element/Swap_algorithm.h"

/* ====堆抽象資料類型 | Heap Abstract Data Structure==== */
/* 建構並初始化heap物件的函式 */
short heapCreate(Heap *self, unsigned size, HeapType type)
{
  /* 初始化各個函式指標 */
  self->destroy = heapDestroy;
  self->isEmpty = heapIsEmpty;
  self->isFull = heapIsFull;

  /* 建立heap[1~size] */
  self->heap = (HeapElement *)malloc(sizeof(HeapElement) * size + 1);
  if(self->heap == NULL){
    fprintf(stderr, ERROR_TAG ERROR_MEMORY_ALLOCATION_FAIL);
    return -1;
  }

  /* 初始化屬性 */
  self->length = 0;
  self->size = size;
  self->type = type;

  /* 完成create操作 */
  return 0;
}

/* 清除heap物件的函式 */
void heapDestroy(Heap *self)
{
  /* 釋放記憶體空間 */
  free(self->heap);
  self->size = self->length = 0;

  /* 完成destroy操作 */
  return;
}

/* 判斷heap是否為空的函式 */
short heapIsEmpty(Heap *self)
{
  if(self->length == 0){
    return 1;
  }else{
    return 0;
  }
}

/* 判斷heap是否為滿的函式 */
short heapIsFull(Heap *self)
{
  if(self->length == self->size){
    return 1;
  }else{
    return 0;
  }
}

/* 產生父母節點索引值的inline函式 */
unsigned INDEX_PARENT(const unsigned child_index)
{
  return child_index >> 1;
}
/* 產生左子節點索引值的inline函式 */
unsigned INDEX_LEFT_CHILD(const unsigned parent_index)
{
  return parent_index << 1;
}

/* 產生右節點索引值的inline函式 */
unsigned INDEX_RIGHT_CHILD(const unsigned parent_index)
{
  return (parent_index << 1) + 1;
}

/*Heapify函式
    When assuming the left and right children node are heaps,
    let the complete binary tree rooted by parent node be a heap.
  參數
  　parent_index
  　　父母節點的索引值（可能不符合heap性質）*/
void heapHeapify(Heap *self, const unsigned parent_index)
{
  /*current largest node, preassuming parent*/
  unsigned largest_index = parent_index;

  /*the child index of current node may be*/
  unsigned left_child_index = INDEX_LEFT_CHILD(largest_index),
            right_child_index = INDEX_RIGHT_CHILD(largest_index);
  /*－－－－－－－－－－－－－－－－－－－－－*/

  /*if left child exist and its key greater than current node*/
  if(left_child_index <= self->length &&
     ((self->type == MAX_HEAP)?
         self->heap[left_child_index] > self->heap[largest_index]:
         self->heap[left_child_index] < self->heap[largest_index])){
     largest_index = left_child_index;
  }

  /*if right child exist and greater than current node*/
  if(right_child_index <= self->length &&
     ((self->type == MAX_HEAP)?
         self->heap[right_child_index] > self->heap[largest_index]:
         self->heap[right_child_index] < self->heap[largest_index])){
     largest_index = right_child_index;
  }

  /*if largest node isn't current node then swap with the largest
    then maxheapify the child which gets the parent node(which may violating the heap property)*/
  if(largest_index != parent_index){
    swapHeapElement(&(self->heap[parent_index]), &(self->heap[largest_index]));
    heapHeapify(self, largest_index);
  }
  /* 完成 */
  return;
}

/*buildHeap function
  build a heap by calling Heapify from the last
  non-leaf node to root node*/
void heapBuildHeap(Heap *self)
{
  unsigned parent;

  /*for last non-leaf node to root*/
  for (parent = (self->length / 2); parent >= 1; --parent) {
    heapHeapify(self, parent);
  }

  /*done*/
  return;
}

/* Add元素至Heap中的函式 */
short heapAdd(Heap *self, HeapElement item)
{
  /*如果heap已滿就異常退出*/
  if(self->length == self->size){
    fprintf(stderr, ERROR_TAG "無法新增元素於已滿的heap！");
    return -1;
  }

  /* 將欲加入的元素放置於heap的尾端之後 */
  self->heap[++self->length] = item;

  /* 對已經不維持heap性質的陣列重新構築heap */
  heapBuildHeap(self);

  /* 完成add操作 */
  return 0;
}

