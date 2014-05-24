#ifndef HEAP_SORT_H_INCLUDED
  #define HEAP_SORT_H_INCLUDED

  /* sort way */
  typedef enum sort_way{
    INCREASINGLY, DECREASINGLY
  }Sort_way;

  /*Heap sort function
      sort data by first heapify it and deletes root consequently*/
  void heapSortInt(
    int array[],
    unsigned array_size,
    Sort_way how);


#endif /* HEAP_SORT_H_INCLUDED*/
