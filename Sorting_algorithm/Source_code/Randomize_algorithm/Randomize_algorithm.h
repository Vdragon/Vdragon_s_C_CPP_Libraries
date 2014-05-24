#ifndef RANDOMIZE_ALGORITHM_H_INCLUDED
  #define RANDOMIZE_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*randomize an array*/
  void randomizeArray(int array_source[], /*the source array*/
                      const unsigned array_size, /*array size*/
                      const int min_result, /*the minimum value to exist*/
                      const int max_result);/*the maximum value to exist*/
  #ifdef __cplusplus
    }
  #endif
#endif /* RANDOMIZE_ALGORITHM_H_INCLUDED*/
