#ifndef BUBBLE_SORT_H_INCLUDED
  #define BUBBLE_SORT_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*bubble sort（冒泡式排序演算法）函式的(function prototype)*/
  void bubbleSort(int data[],
                    const unsigned array_size,
                    int (*sortOrderBool)(int a,
                                          int b));
          /*提供bubble sort遞增順序比較條件函式*/
          int sortAscendingly(int a, int b);

          /*提供bubble sort遞減順序比較條件函式*/
          int sortDescendingly(int a, int b);
  #ifdef __cplusplus
    }
  #endif

#endif /* BUBBLE_SORT_H_INCLUDED*/
