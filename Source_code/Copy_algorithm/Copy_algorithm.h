#ifndef COPY_ALGORITHM_H_INCLUDED
  #define COPY_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif

  /*function to copy an array to another
    destination should be bigger then the source*/
  void copyArrayInt(int destination[],
                    const int source[],
                    const unsigned source_size);

  #ifdef __cplusplus
    }
  #endif
#endif /* COPY_ALGORITHM_H_INCLUDED*/
