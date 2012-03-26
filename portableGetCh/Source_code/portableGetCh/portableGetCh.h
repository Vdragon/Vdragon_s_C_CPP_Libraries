/* C header檔案範本 */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef _H_INCLUDED
  #define _H_INCLUDED
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*getch()（相容於Standard C(POSIX)的getch()替代方案）*/
  char portableGetCh(void);
  #ifdef __cplusplus
    }
  #endif
#endif /* _H_INCLUDED */
