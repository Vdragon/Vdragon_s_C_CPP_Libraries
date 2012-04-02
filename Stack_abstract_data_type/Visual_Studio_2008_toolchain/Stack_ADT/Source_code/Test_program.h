/* Test_program.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef TEST_PROGRAM_H_
  #define TEST_PROGRAM_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*定義堆疊(Stack)最大容量大小*/
  #define MAX_STACK_SIZE 100

  /*單元測試函式*/
  short stackUnitTest(void);
  #ifdef __cplusplus
    }
  #endif
#endif /* TEST_PROGRAM_H_ */
