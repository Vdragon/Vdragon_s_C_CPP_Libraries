
/*插入一個邊(edge)至相鄰性陣列圖中的函式
 *  版本：1.00(1)*/
short int graphMatrixInsertEdge(GraphTypes mode, Graph target[][MAX_ADJ_MATRIX_SIZE], Edge item)
{
  /*宣告與定義(Declaration & Definition)*/
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*如果發現自loop邊就回傳失敗*/
  if(item.u == item.v){
    return -1;
  }

      target[item.u][item.v] = 1;

      if(mode == UNDIRECTED){
        target[item.v][item.u] = 1;
      }
          /*－－－－－－－－－－－－－－－－－－－－－*/
          /*回傳成功*/
          return 0;
}

/*摧毀相鄰性陣列圖的函式
 *  版本：1.00(0)*/
void graphMatrixDestroy(Graph target[][MAX_ADJ_MATRIX_SIZE])
{
  /*宣告與定義(Declaration & Definition)*/
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*for迴圈*/
  register unsigned i , j;

  for(i = 0; i < MAX_ADJ_MATRIX_SIZE; i++){
    for(j = 0; j < MAX_ADJ_MATRIX_SIZE; j++){
      target[i][j] = 0;
    }
  }
      /*－－－－－－－－－－－－－－－－－－－－－*/
      /*傳回內容*/
      return ;
}

/*輸出相鄰性矩陣圖的函式
 *  版本：1.00(1)*/
void graphMatrixOutput(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE])
{
  /*宣告與定義(Declaration & Definition)*/
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*印出陣列資料*/
  printf("  0 1 2 3 4 5 6 7 8 9\n");

  register unsigned i, j;
  for(j = 0; j < MAX_ADJ_MATRIX_SIZE; j++){
    printf("%u ", j);
    for(i = 0; i < MAX_ADJ_MATRIX_SIZE; i++){
      printf("%u ", graph_adj_matrix[i][j]);
    }
            putchar('\n');
  }
      /*－－－－－－－－－－－－－－－－－－－－－*/
      /*傳回內容*/
      return ;
}

/*適用於相鄰性陣列(Adjacency Matrix)的深度優先搜尋(Depth First Search)函式
  版本：1.00(0)*/
void graphAdjMatDFS(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE], const Vertex root)
  {
  /*宣告與定義(Declaration & Definition)*/
  /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零*/
  static unsigned visited[MAX_ADJ_LIST_SIZE] = {FALSE};

  /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
  static unsigned call_level = 1;

  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*將root的head標記為已拜訪*/
  visited[root] = TRUE;

  /*印出root*/
  printf("%d->", root);

  /**/
  register unsigned count;
  for(count = 0; count < MAX_ADJ_MATRIX_SIZE; count++){
      /*如果兩頂點有相連且還沒拜訪過該頂點*/
      if(visited[count] == FALSE && graph_adj_matrix[root][count] == 1){
          /*用該節點進行呼叫*/
          call_level++;
          graphAdjMatDFS(graph_adj_matrix, count);
      }
  }

  /*如果沒有呼叫就表示要退出*/
  if(call_level != 1){
      call_level--;
  }/*如果回到最後一層就結束*/
  else{
      register unsigned i;
      for(i = 0; i < MAX_ADJ_MATRIX_SIZE; i++){
          visited[i] = FALSE;
      }
      printf("END\n");
  }

  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*傳回內容*/
  return ;
  }
