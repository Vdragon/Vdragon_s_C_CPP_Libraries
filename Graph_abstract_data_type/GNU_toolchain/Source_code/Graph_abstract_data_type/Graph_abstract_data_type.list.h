/* C header檔案範本 */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED
  #define GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*圖(graph)共同的結構*/
  #include "Graph_abstract_data_type.generic.h"

  /*最大相鄰性列表的大小*/
  /*#define MAX_ADJ_LIST_SIZE 100*/

  /*圖節點的資料結構（adjacency lists表示法）*/
  typedef struct adjListNode{
      Vertex connected_vertex;
      int weight;
      struct adjListNode * next;
  }AdjListNode;
  typedef struct adjListNode * AdjListHead;

  /*圖的宣告*/
  /*typedef AdjListHead * Graph;*/
  typedef struct graph{
    AdjListHead * adj_list;
    GraphTypes type;
    unsigned vertex_num;

    short (*initGraphRef) (struct graph *target, const unsigned vertex_num, GraphTypes type);
    short (*insertEdgeRef) (GraphTypes mode, struct graph target, Edge item);
    void  (*destroyGraphRef) (struct graph *target);
    void  (*printGraphRef)(struct graph target);
    void  (*prim_sMSTref) (struct graph target);
    short (*graphIsEmpty) (struct graph target);
  }Graph;

  /*初始化Graph成員函式：
   *  根據vertex_num的量動態配置記憶體作為AdjListHead的陣列[0 ~ vertex_num-1]
   *  請注意此陣列的第零個索引位址為第一個點(vertex)！*/
  short initGraph(struct graph *  target, const unsigned vertex_num, GraphTypes type);
  /*摧毀相鄰性List圖的函式的function prototype*/
  void destroyGraph(struct graph * target);
  /*插入一個邊(edge)至相鄰性List圖中的函式的成員函式*/
  short int graphListInsertEdge(GraphTypes mode, Graph target, Edge item);
  /*輸出相鄰性List圖的函式的function prototype*/
  void printGraph(struct graph target);
  /*確認圖為空函式的function prototype
   *  回傳值：true/false*/
  short graphIsEmpty(Graph target);
  /*Prim's Minimum Spanning Tree演算法*/
  void prim_sMST(Graph target, Vertex start, Vertex parent[]);

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


  /*Prim's Minimum Spanning Tree演算法所用的物件*/
  typedef struct prim_sMst{
    int *keyArray;


    short (*primInitRef)(Vertex * key, unsigned size);
    Vertex (*primDelRef)();
    short (*primConsistOfRef)();
    unsigned (*primKeyValRef)(Vertex w);
    void (*primDecreaseRef)(Vertex w, unsigned new_weight);
  }Prim_sMst;

/*h.init(key, n): initializes h to the values in key (程式開始時 h 裡面有 n-1 個節點,
 *  也就是除掉 start 之外的所有節點)*/
  short primInit(Vertex * key, unsigned size);

/*h.del(): deletes the item in h with the smallest weight and returns the vertex (由 h 中把距離目前 MST 距離最短的節點剔除)*/
  Vertex primDel();

  /*h.isin(w): returns true if vertex w is in h (這是一個簡單的測試函式, 可惜命名錯了, 想一下 isin 應該改成什麼?)*/
  short primConsistOf(Vertex w);

  /*h.keyval(w): returns the weight corresponding to the vertex w (由 h 中將指定的節點到目前 MST 的距離取出)*/
  unsigned primKeyval(Vertex w);

  /*h.decrease(w, new_weight): changes the weight of w to new_weight (smaller) (由於演算法一次增加一個新的節點到目前 MST 中, 每增加一個新的節點進入目前 MST, 所有還沒有加入目前 MST 的節點到 目前 MST 的距離都需要修改, 此介面函式目的就是修改節點 w 距離目前 MST 的距離為 new_weight)*/
  void primDecrease(Vertex w, unsigned new_weight);

  #ifdef __cplusplus
    }
  #endif
#endif /* GRAPH_ABSTRACT_DATA_TYPE_LIST_H_INCLUDED */
