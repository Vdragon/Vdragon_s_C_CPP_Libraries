#ifndef HEAP_SORT_H_INCLUDED
  #define HEAP_SORT_H_INCLUDED
  /*Heap sort function prototype
  void heapSort(int data[],
                 const unsigned array_size,
                 );*/

  /*maxHeapify函式
      When assuming the left and right children node are max heaps,
      let the complete binary tree rooted by parent node be a max heap.*/
  void maxHeapify(int heap[], /*heap array*/
                  const unsigned heap_size, /*heap size, *not* array size*/
                  const unsigned parent_index); /*index of parent node(to be heapified)*/


#endif // HEAP_SORT_H_INCLUDED
