/* C header檔案範本 */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED
  #define GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*||||| Forward declarations |||||*/

  /*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
  /*圖(graph)共同的結構*/
  #include "Graph_abstract_data_type.generic.h"

  /* 為Prim的MST演算法設計的HeapADT */
  #include "Tree_abstract_data_type_prim_sMST/Tree_abstract_data_type_C.h"

  /*|||||常數與巨集 | Constants & Macros |||||*/
  /*定義堆疊(Stack)最大容量大小
  #define MAX_STACK_SIZE 100*/

  /*定義測試用的圖的邊、頂點數量*/
  #define GRAPH01_EDGE_QUANTITY 10
  #define GRAPH01_VERTEX_QUANTITY 10
  #define GRAPH03_EDGE_QUANTITY 10
  #define GRAPH03_VERTEX_QUANTITY 10
  #define GRAPH03_MAX_WEIGHT 30

  /*||||| Definition of data type, enumeration, data structure and class |||||*/
  /*圖節點的資料結構（adjacency lists表示法）*/
  typedef struct adjListNode{
      Vertex connected_vertex;
      unsigned weight;
      struct adjListNode * next;
  }AdjListNode;
  typedef AdjListNode * AdjListHead;

  /*圖的宣告*/
  typedef struct graph{
    /* 指向各個AdjListNode的指標變數所組成的陣列[0 ~ vertex_num - 1] */
    AdjListHead * adj_list;
    /* 圖的類型：有向圖or無向圖 */
    GraphTypes type;
    /* 頂點(vertex)的數量 */
    unsigned vertex_num;

    short (*init) (struct graph *target, const unsigned vertex_num, GraphTypes type);
    short (*insertEdge) (GraphTypes mode, struct graph target, Edge item);
    void  (*destroy) (struct graph *target);
    void  (*print)(struct graph target);
    short (*prim_sMST) (struct graph target, Vertex root, Vertex parent[]);
    short (*isEmpty) (struct graph target);
    int (*getEdgeWeight)(struct graph target, Edge query, short *result);
    short (*unitTest) (void);
  }Graph;

  /* public成員函式 */
  /*初始化Graph成員函式：
   *  根據vertex_num的量動態配置記憶體作為AdjListHead的陣列[0 ~ vertex_num-1]
   *  請注意此陣列的第零個索引位址為第一個點(vertex)！*/
  short graphInit(Graph *target, const unsigned vertex_num, GraphTypes type);
  /*摧毀相鄰性List圖的函式的function prototype*/
  void graphDestroy(Graph *target);
  /*插入一個邊(edge)至相鄰性List圖中的函式的成員函式*/
  short int graphInsertEdge(GraphTypes mode, Graph target, Edge item);
  /*輸出相鄰性List圖的函式的function prototype*/
  void graphPrint(Graph target);
  /*確認圖為空函式的function prototype
   *  回傳值：true/false*/
  short graphIsEmpty(Graph target);
  /*Prim's Minimum Spanning Tree演算法
   *  參數
   *  　target
   *  　　製作MST的Graph
   *  　root
　 * 　　　MST的根節點
　 * 　　parent
   * 　　　保存MST的結果，所有頂點以及其父節點，MST根節點的父節點為0
   * 　回傳值
   * 　　0
   * 　　　成功完成
   * 　　-1
   * 　　　記憶體要求失敗*/
  short graphPrim_sMST(Graph target, Vertex root, Vertex parent[]);
  /* 查詢某已知邊的weight的函式 */
  int graphGetEdgeWeight(Graph target, Edge query, short *result);
  /* 對GraphADT進行單元測試的函式 */
  short graphUnitTest(void);
#if 0
  /*插入一個頂點(vertex)至相鄰性List圖中的函式的function prototype
  short int graphListInsertVert(GraphTypes mode, AdjListHead adj_list[], Vertex v);*/

  /*於圖中刪除一個頂點(vertex)（及其連結邊）的函式的function prototype*/
  /*Graph graphDeleteVertex(Graph target, Vertex item);*/
  /*於圖中刪除一個邊(edge)的函式的function prototype*/
  /*Graph graphDeleteEdge(Graph target, Edge item);*/
  /*製作並回傳與target圖中item頂點的Adjacency List的函式的function prototype的function prototype*/
  /*AdjListHead graphVertAdj(Graph target, Vertex item);*/

  /*適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式的function prototype*/
  void graphAdjListDFS(const Graph target, const Vertex root, unsigned max_adj_list_size);

  /*適用於相鄰性List(Adjacency List)的廣度優先搜尋(B First Search)函式的function prototype*/
  /*unsigned * graphAdjListBFS(Graph target, Vertex root);*/

  /*適用於相鄰性List(Adjacency List)的計算dfn、low值函式的function prototype*/
  short int graphAdjListDfnLow(Graph target, Vertex child, Vertex parent, unsigned max_adj_list_size);

  /*適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式的function prototype*/
  short int graphAdjListFBC(Graph target, Vertex child, Vertex parent, unsigned max_stack_size, unsigned max_adj_list_size);

#endif


  /* Prim's Minimum Spanning Tree演算法所用的物件（未完成） */
  typedef struct prim_sMSTcontainer{
    /* 屬性 */
    Heap heap;

    /* 介面 */
    short (*init)(struct prim_sMSTcontainer *self, unsigned key[], unsigned size);
    void (*destroy)(struct prim_sMSTcontainer *self);
    Vertex (*del)(struct prim_sMSTcontainer *self);
    short (*has)(struct prim_sMSTcontainer *self, Vertex w);
    unsigned (*keyOf)(struct prim_sMSTcontainer *self, Vertex w);
    void (*decrease)(struct prim_sMSTcontainer *self, Vertex w, unsigned new_weight);

  }Prim_sMSTcontainer;

  /* private 成員函式 */


  /* public 成員函式 */
  /*h.init(key, n): initializes h to the values in key
   *  回傳值
   *  　-1
   *  　　記憶體配置失敗
   *    ０
   *    　成功執行*/
  short primInit(Prim_sMSTcontainer *self, unsigned key[], unsigned size);
  void primDestroy(Prim_sMSTcontainer *self);
  /*h.del(): deletes the item in h with the smallest weight and returns the vertex (由 h 中把距離目前 MST 距離最短的節點剔除)*/
  Vertex primDel(Prim_sMSTcontainer *self);
  /*h.isin(w): returns true if vertex w is in h (這是一個簡單的測試函式, 可惜命名錯了, 想一下 isin 應該改成什麼?)*/
  short primHeapHas(Prim_sMSTcontainer *self, Vertex w);
  /*h.keyval(w): returns the weight corresponding to the vertex w (由 h 中將指定的節點到目前 MST 的距離取出)*/
  unsigned primKeyOf(Prim_sMSTcontainer *self, Vertex w);
  /*h.decrease(w, new_weight): changes the weight of w to new_weight (smaller)
   * (由於演算法一次增加一個新的節點到目前 MST 中, 每增加一個新的節點進入目前 MST,
   * 所有還沒有加入目前 MST 的節點到 目前 MST 的距離都需要修改, 此介面函式目的就是
   * 修改節點 w 距離目前 MST 的距離為 new_weight)*/
  void primDecrease(Prim_sMSTcontainer *self, Vertex w, unsigned new_weight);
#if 0


#endif

  #ifdef __cplusplus
    }
  #endif
#endif /* GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED */
