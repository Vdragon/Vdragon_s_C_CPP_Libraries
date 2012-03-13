#ifndef HEAP_SORT_H_INCLUDED
  #define HEAP_SORT_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*Heap sort function prototype
      sort data by first maxHeapify it and deletes root consequently*/
  void heapSortInt(int heap[],
                 const unsigned *heap_size);

  /*maxHeapifyInt函式
      When assuming the left and right children node are max heaps,
      let the complete binary tree rooted by parent node be a max heap.*/
  void maxHeapifyInt(int heap[], /*heap array*/
                  const unsigned heap_size, /*heap size, *not* array size*/
                  const unsigned parent_index); /*index of parent node(to be heapified)*/

  /*buildMaxHeapInt function prototype
      build a max heap by calling maxHeapify from the last
      non-leaf node to root node*/
  void buildMaxHeapInt(int heap[], /*heap array*/
                       unsigned heap_size /*heap size, *not* array size*/);
  #ifdef __cplusplus
    }
  #endif
#endif /* HEAP_SORT_H_INCLUDED*/
