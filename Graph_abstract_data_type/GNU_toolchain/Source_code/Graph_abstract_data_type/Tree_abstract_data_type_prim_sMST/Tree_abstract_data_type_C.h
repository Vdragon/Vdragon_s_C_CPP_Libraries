#ifndef TREE_ADT_PRIM_MST
  #define TREE_ADT_PRIM_MST
  #ifdef __cplusplus
    extern "C"{
  #endif

  /* 訊息 */
  #define HEAP_ADT_TAG "【Heap抽象資料類型】"

  /* HEAP單元測試所使用的HEAP最大大小 */
  #define HEAP_UNITTEST_SIZE 100


/* ====堆(heap)抽象資料類型定義====
 * 1.本class以陣列(array)來實作heap，結構如下：
 *   不使用 最大／最小元素 比[1]大／小的元素 比[2]大／小的元素 比[3]大／小的元素 ...
 *     0        1           2 & 3           4 & 5           6 & 7      ...
 *            1    <---根節點
 *          2   3
 *         4 5 6 7
 **/
#include "../Graph_abstract_data_type.generic.h"

/* heap元素的定義 */
typedef struct heapElement{
  Vertex v;
  unsigned min_weight;
}HeapElement;

/* Heap的類型定義 */
typedef enum heapType{
  MAX_HEAP, MIN_HEAP
}HeapType;

/* Heap的class定義 */
typedef struct heap{
  /* ====屬性==== */
  /* heap的類型(max-heap/min-heap) */
  HeapType type;
  /* heap陣列
   * 由heap[1]至heap[size] */
  HeapElement *heap;
  /* heap陣列的總大小（不包括下標(subscript)為零者） */
  unsigned size;
  /* 目前heap使用的元素數（不包括下標(subscript)為零者） */
  unsigned length;

  /* ====介面==== */
  /* 建構並初始化heap物件的函式
   * 參數
   * 　*self
   * 　　物件本身
   * 　size
   * 　　heap大小
   * 回傳數值
   * 　-1
   * 　　系統可用記憶體空間不足*/
  short (*create)(struct heap *self, unsigned size, HeapType type);
  /* 清除heap物件的函式 */
  void (*destroy)(struct heap *self);
  /* 判斷heap是否為空的函式 */
  short (*isEmpty)(struct heap *self);
  /* 判斷heap是否為滿的函式 */
  short (*isFull)(struct heap *self);
  /* 用level order形式印出heap中的資料的函式 */
  void (*levelPrint)(struct heap *self);
  /* 將元素加入至Heap中的函式
     時間複雜度：O(log(2,n)) */
  short (*add)(struct heap *self, HeapElement item);
  /* 對heap進行delete操作的函式 */
  HeapElement (*del)(struct heap *self, short *result);
  short (*has)(struct heap *self, Vertex w);
  unsigned (*keyOf)(struct heap *self, Vertex w);
  void (*decrease)(struct heap *self, Vertex w, unsigned new_weight);
  /* heap ADT的單元測試函式
   * 回傳值
   * 　0 測試通過*/
  short (*unitTest)(void);
}Heap;
/* ==private成員函式== */
/* 產生父母節點索引值的inline函式 */
unsigned INDEX_PARENT(const unsigned parent_index);
/* 產生左子節點索引值的inline函式 */
unsigned INDEX_LEFT_CHILD(const unsigned parent_index);
/* 產生右節點索引值的inline函式 */
unsigned INDEX_RIGHT_CHILD(const unsigned parent_index);
/*將子節點為heap但根節點未必遵守heap性質的完整二元樹變為heap的函式
    When assuming the left and right children node are max heaps,
    let the complete binary tree rooted by parent node be a max heap.
  參數
  　parent_index
  　　父母節點的索引值（可能不符合heap性質）*/
void heapHeapify(Heap *self, const unsigned parent_index);
/*heapBuildHeap function
  build a heap by calling Heapify from the last
  non-leaf node to root node*/
void heapBuildHeap(Heap *self);

/* ==public 成員函式== */
short heapCreate(Heap *self, unsigned size, HeapType type);
void heapDestroy(Heap *self);
short heapIsEmpty(Heap *self);
short heapIsFull(Heap *self);
void heapLevelPrint(Heap *self);
short heapAdd(Heap *self, HeapElement item);
HeapElement heapDelete(Heap *self, short *result);
short heapHas(Heap *self, Vertex w);
short heapUnitTest();
unsigned heapKeyOf(Heap *self, Vertex w);
void heapDecrease(Heap *self, Vertex w, unsigned new_weight);
#ifdef __cplusplus
    }
  #endif
#endif
