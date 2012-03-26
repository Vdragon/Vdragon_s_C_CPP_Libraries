/*adjacency矩陣表示法最大大小*/
#define MAX_ADJ_MATRIX_SIZE 10

/*圖的宣告*/
typedef unsigned Graph;

/*創造一個圖的函式的function prototype*/
Graph graphMatrixCreate(void);

/*插入一個頂點(vertex)至相鄰性矩陣圖中的函式的function prototype*/
short int graphMatrixInsertVert(GraphTypes mode, Graph target, Vertex v);

/*插入一個邊(edge)至相鄰性矩陣圖中的函式的function prototype*/
short int graphMatrixInsertEdge(GraphTypes mode, Graph target[][MAX_ADJ_MATRIX_SIZE], Edge item);

/*輸出相鄰性矩陣圖的函式的function prototype*/
void graphMatrixOutput(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE]);

/*摧毀相鄰性陣列圖的函式的function prototype*/
void graphMatrixDestroy(Graph target[][MAX_ADJ_MATRIX_SIZE]);

/*適用於相鄰性陣列(Adjacency Matrix)的廣度優先搜尋(B First Search)函式的function prototype*/
short int graphAdjMatBFS(Graph target);

/*適用於相鄰性陣列(Adjacency Matrix)的尋找多連結圖元件(Biconnected Component)函式的function prototype*/
short int graphAdjMatFBC(Graph target);

/*適用於相鄰性陣列(Adjacency Matrix)的深度優先搜尋(Depth First Search)函式的function prototype*/
void graphAdjMatDFS(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE], const Vertex root);
