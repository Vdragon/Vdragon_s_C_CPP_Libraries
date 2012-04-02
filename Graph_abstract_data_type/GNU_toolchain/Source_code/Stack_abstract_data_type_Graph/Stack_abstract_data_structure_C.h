/* Stack抽象資料類型 | Stack Abstract Data Type
 * 相依性 | Dependency
 *   Messages_templates */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef STACK_ABSTRACT_DATA_STRUCTURE_C_H_INCLUDED
  #define STACK_ABSTRACT_DATA_STRUCTURE_C_H_INCLUDED
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
    /*StackElement的定義（於需要使用ADT的程式碼自訂）
    typedef int StackElement;*/
    #include "../Graph_abstract_data_type/Graph_abstract_data_type.generic.h"

    /*模組標籤*/
    #define STACK_ABSTRACT_DATA_STRUCTURE_TAG "【Stack抽象資料類型模組】"
    #define STACK_ADT_PUSH_TAG "【Stack ADT push模組】"

    /*讀取空堆疊錯誤訊息*/
    #define ERROR_STACK_POP_WHEN_EMPTY "處理資料所使用的Stack資料結構不能於沒有資料時進行pop操作！\n"
    /*寫入滿堆疊錯誤訊息*/
    #define ERROR_STACK_PUSH_WHEN_FULL "處理資料所使用的Stack資料結構不能於可用空間用盡時進行push操作！\n"
    /*堆疊(Stack)元素資料結構
    typedef struct stackElement{*/
      /*資料members*/

    /*}StackElement;*/

    /*判斷堆疊是否為空函式的function prototype*/
    short int stackIsEmpty(int stack_top);

    /*判斷堆疊是否已滿函式的function prototype*/
    short int stackIsFull(int stack_top, unsigned max_stack_size);

    /*將元素push至堆疊的函式*/
    short int stackPush(StackElement item, StackElement stack[], int *stack_top, unsigned max_stack_size);

    /* 將元素pop出堆疊的函式
     * 參數：
     *   stack  StackElement類型的stack
     *   *stack_top Stack的top
     * 回傳值：
     *   StackElement pop出來的stack元素
     *   *return_status 回傳狀態碼
     *     0  成功運行
     *     -1 堆疊已滿*/
    StackElement stackPop(StackElement stack[], int *stack_top, short * return_status);

  #ifdef __cplusplus
    }
  #endif
#endif /* STACK_ABSTRACT_DATA_STRUCTURE_C_H_INCLUDED */


