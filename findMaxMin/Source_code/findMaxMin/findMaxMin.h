#ifndef FIND_MAX_MIN_H_INCLUDED
  #define FIND_MAX_MIN_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*比較兩數較小值的巨集*/
  #define MIN_OF_2(x, y) (x < y ? (x) : (y))

  /*比較兩數較小值的巨集*/
  #define MAX_OF_2(x, y) (x > y ? (x) : (y))

  /*intArrayMax函式雛型*/
    int intArrayMax(int target[], unsigned array_size);

  /*intArrayMin的函式雛型*/
    int intArrayMin(int input[], unsigned short int arraySize);


  #ifdef __cplusplus
    }
  #endif
#endif
