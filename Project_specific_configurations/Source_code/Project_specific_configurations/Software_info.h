/* Software_info.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef SOFTWARE_INFO_H_
  #define SOFTWARE_INFO_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  
  /*軟體名稱*/
  #define SOFTWARE_NAME "Software Name"
  /*軟體開發者名稱*/
  #define DEVELOPER_NAME "Developer Name"
  /*軟體開發者的電子郵件地址*/
  #define DEVELOPER_EMAIL "developer@host.category.region"
  /*用在著作權宣告的軟體釋出年份*/
  #define SOFTWARE_RELEASE_YEAR "2012"

  #ifdef __cplusplus
    }
  #endif
#endif /* SOFTWARE_INFO_H_ */
