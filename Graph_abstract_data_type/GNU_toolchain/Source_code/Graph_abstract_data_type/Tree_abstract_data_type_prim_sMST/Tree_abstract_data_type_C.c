/* ====標準C函式庫==== */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

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
  self->levelPrint = heapLevelPrint;
  self->del = heapDelete;
  self->add = heapAdd;
  self->unitTest = heapUnitTest;
  self->has = heapHas;
  self->keyOf = heapKeyOf;
  self->decrease = heapDecrease;

  /* 建立heap[1~size] */
  self->heap = (HeapElement *)malloc(sizeof(HeapElement) * (size + 1));
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

/* 用level order形式印出heap中的資料的函式 */
void heapLevelPrint(Heap *self)
    {
    /*如果heap中無資料則直接退出*/
    if(heapIsEmpty(self)){
        printf("目前heap中無資料。\n"
               "There are currently no data in the heap.\n");
        return;
    }
    else{
      /*現在處理的元素計數器*/
      register unsigned curr_print;

      /*用for迴圈從第一個元素輸出到最後一個元素*/
      for(curr_print = 1; curr_print <= self->length; ++curr_print){
          printf("%d[%d] ", curr_print, (self->heap[curr_print]).min_weight);
      }
    }
    /*斷行*/
    putchar('\n');

    return ;
    }

/*maxHeapify函式
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

  /*if left child exist and its min_weight greater than current node*/
  if(left_child_index <= self->length &&
     ((self->type == MAX_HEAP)?
         self->heap[left_child_index].min_weight > self->heap[largest_index].min_weight:
         self->heap[left_child_index].min_weight < self->heap[largest_index].min_weight)){
     largest_index = left_child_index;
  }

  /*if right child exist and greater than current node*/
  if(right_child_index <= self->length &&
     ((self->type == MAX_HEAP)?
         self->heap[right_child_index].min_weight > self->heap[largest_index].min_weight:
         self->heap[right_child_index].min_weight < self->heap[largest_index].min_weight)){
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
  self->length++;
  self->heap[self->length] = item;

  /* 對已經不維持heap性質的陣列重新構築heap */
  heapBuildHeap(self);

  /* 完成add操作 */
  return 0;
}

/* 自Heap中delete出元素的函式 */
HeapElement heapDelete(Heap *self, short *result)
{
  HeapElement deleted;
  deleted.min_weight = -99999;

  /* 如果堆疊是空的就無法進行delete操作 */
  if(self->isEmpty(self) == 1){
    printf(ERROR_TAG HEAP_ADT_TAG "無法於空的heap進行delete操作！\n");
    *result = -1;
    return deleted;
  }
  /* 取出最小／大的根節點，現在根節點是空的 */
  deleted = self->heap[1];

  /* 把所有[2]以後的元素都往前移一位 */{
    unsigned i;
    for(i = 2; i <= self->length; ++i){
      self->heap[i-1] = self->heap[i];
    }
    self->length -= 1;
  }

  /* 已經不維持heap性質，重新構築heap */
  heapBuildHeap(self);

  /* 完成delete操作 */
  *result = 0;
  return deleted;
}

short heapUnitTest()
{
  /* 測試heap add, delete */{
    Heap max, min;
    min.create = max.create = heapCreate;

    srand(time(NULL));

    min.create(&min, HEAP_UNITTEST_SIZE, MIN_HEAP);
    {
      unsigned i;
      HeapElement augend, prev, next;
      short del_result;

      for(i = 0; i < HEAP_UNITTEST_SIZE; ++i){
        augend.min_weight = rand() % 100;
        heapAdd(&min, augend);
      }
      prev = heapDelete(&min, &del_result);
      assert(!del_result);
      for(i = 1; i < HEAP_UNITTEST_SIZE; ++i){
        next = heapDelete(&min, &del_result);
        assert(!del_result);
        assert(prev.min_weight <= next.min_weight);
        prev.min_weight = next.min_weight;
      }
    }
    min.destroy(&min);

    max.create(&max, HEAP_UNITTEST_SIZE, MAX_HEAP);
    {
      unsigned i;
      HeapElement augend, prev, next;
      short del_result;

      for(i = 0; i < HEAP_UNITTEST_SIZE; ++i){
        augend.min_weight = rand() % 100;
        heapAdd(&max, augend);
      }
      prev = heapDelete(&max, &del_result);
      assert(!del_result);
      for(i = 1; i < HEAP_UNITTEST_SIZE; ++i){
        next = heapDelete(&max, &del_result);
        assert(!del_result);
        assert(prev.min_weight >= next.min_weight);
        prev.min_weight = next.min_weight;
      }
    }
    max.destroy(&max);
  }

  /* pass */
  fprintf(stdout, HEAP_ADT_TAG "元件測試全部通過！\n");
  return 0;
}

short heapHas(Heap *self, Vertex w)
{
  unsigned i;
  for(i = 1; i <= self->length; ++i){
    if(self->heap[i].v == w){
      return 1;
    }
  }
  return 0;
}

unsigned heapKeyOf(struct heap *self, Vertex w)
{
  unsigned i;
  for(i = 1; i <= self->length; ++i){
    if(self->heap[i].v == w){
      return self->heap[i].min_weight;
    }
  }
  return 0;
}

void heapDecrease(Heap *self, Vertex w, unsigned new_weight)
{
  unsigned i;
  for(i = 1; i <= self->length; ++i){
    if(self->heap[i].v == w){
      self->heap[i].min_weight = new_weight;
      heapBuildHeap(self);
      return;
    }
  }
}
