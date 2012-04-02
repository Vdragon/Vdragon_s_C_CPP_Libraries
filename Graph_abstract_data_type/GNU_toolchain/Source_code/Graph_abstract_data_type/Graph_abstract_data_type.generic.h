/* Graph_abstract_data_type.generic.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef GRAPH_ABSTRACT_DATA_TYPE_GENERIC_H_
  #define GRAPH_ABSTRACT_DATA_TYPE_GENERIC_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*點的資料結構*/
  typedef int Vertex;

  /*邊(edge)的資料結構*/
  typedef struct edge{
      Vertex u, v;
      int cost;
  }Edge;

  /*堆疊(Stack)元素資料結構*/
  typedef Edge StackElement;

  /*圖的類型設定*/
  typedef enum graphTypes{
      UNDIRECTED, /*無方向性邊的圖*/
      DIRECTED /*有方向性邊的圖*/
  }GraphTypes;

  #ifdef __cplusplus
    }
  #endif
#endif /* GRAPH_ABSTRACT_DATA_TYPE_GENERIC_H_ */
