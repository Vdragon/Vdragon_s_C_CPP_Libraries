#ifndef SWAP_ALGORITHM_H_INCLUDED
  #define SWAP_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
  extern "C"{
  #endif
  /*swap函式 func. prototype*/
      void swapInt(int *a, int *b);

  /*func. prototype for swap func.(unsigned整數專用版本)*/
      void swapUnsignedInt(unsigned *a, unsigned *b);

  /*func. prototype of swapLongInt*/
      void swapLongInt(long *a,long *b);

  /*func. prototype for Swap(無負短整數專用版本)*/
      void swapUnsignedShortInt(unsigned short *a, unsigned short *b);

  /*swapDouble func. prototype*/
      void swapDouble(double *a,double *b);
  #ifdef __cplusplus
  }
  #endif
#endif
