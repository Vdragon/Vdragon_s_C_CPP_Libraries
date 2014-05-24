/*Graph_abstract_data_type.list.c
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  Graph_abstract_data_type.list.c is part of Graph抽象資料結構
  Graph抽象資料結構 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Graph抽象資料結構 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Graph抽象資料結構.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*this*/
#include "Graph_abstract_data_type.list.h"

/* 標準C函式庫 */
/*we need NULL*/
#include <stddef.h>
/*we need malloc() free()*/
#include <stdlib.h>
/*we need printf*/
#include <stdio.h>
/*we need memcpy*/
#include <string.h>
/* UINT_MAX的定義 */
#include <limits.h>
/*header for Date and time functions Library*/
#include <time.h>
#include <assert.h>

/* Vdragon's Library Collection */
/*we need stack adt*/
#include "Stack_abstract_data_type_Graph/Stack_abstract_data_structure_C.h"
/* we need MIN_OF_2 macro*/
#include "../findMaxMin/findMaxMin.h"
/**/
#include "../Messages_templates/zh_TW.h"

/*////////常數與巨集(Constants & Macros)////////*/
/* 定義用於Prim's MST的無限*/
#define INFINITE UINT_MAX
/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*插入一個邊(edge)至相鄰性List圖中的函式
  參數：mode（有無方向性）、target（相鄰性List圖Head陣列）、item（限定非Loop的邊）*/
short int graphListInsertEdge(GraphTypes mode, Graph target, Edge item)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*1.2用的讀取指標*/
    register AdjListNode * current_node_position = NULL;

    /*用來第二次呼叫的邊*/
    Edge exchange_edge;

    /*判斷是否是第二次呼叫的靜態字元*/
    static char second_call = 'n';

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*0.-如果出現自成loop的邊的話就錯誤退出*/
    if(item.u == item.v){
        return -2;
    }
    /*1.-先處理u頂點*/
    /*1.1-如果說該邊的Head目前沒有點...*/
    if(target.adj_list[item.u] == NULL){
        /*1.1.1-要求一個節點的記憶體並附加在Head上*/
        target.adj_list[item.u] = (AdjListNode *)malloc(sizeof(AdjListNode));

        /*1.1.2-如果要求記憶體失敗*/
        if(target.adj_list[item.u] == NULL){
            return -1;
        }

        /*1.1.3-設定該節點*/
        target.adj_list[item.u]->connected_vertex = item.v;
        target.adj_list[item.u]->weight = item.cost;
        target.adj_list[item.u]->next = NULL;

        /*如果是無向圖且非第二次呼叫的話就將點交換頂點再呼叫自己一次*/
        if(second_call == 'n' && mode == UNDIRECTED){
            exchange_edge.u = item.v;
            exchange_edge.v = item.u;
            exchange_edge.cost = item.cost;
            second_call = 'y';
            graphListInsertEdge(UNDIRECTED, target, exchange_edge);
        }
        second_call = 'n';

        /*1.1.4-正常離開*/
        return 0;
    }
    /*1.2-將current_node_position設定為第一個節點*/
    current_node_position = target.adj_list[item.u];

    /*1.3-當還沒到最後一個節點前一直往前*/
    for(current_node_position = target.adj_list[item.u];
        1;
        current_node_position = current_node_position->next){
        /*1.3.1-如果發現重複的點就正常離開*/
        if(current_node_position->connected_vertex == item.v){
            return 0;
        }
        /*1.3.2-如果此為最後一個節點就離開迴圈*/
        if(current_node_position->next == NULL){
            break;
        }
    }

    /*要求一個節點的記憶體並附加在最後一個頂點節點上*/
    current_node_position->next = (AdjListNode *)malloc(sizeof(AdjListNode));

    /*如果要求記憶體失敗回傳失敗*/
    if(current_node_position->next == NULL){
        return -1;
    }

    /*設定該新節點*/
    current_node_position->next->connected_vertex = item.v;
    current_node_position->next->weight = item.cost;
    current_node_position->next->next = NULL;

    /*如果是無向圖且非第二次呼叫的話就將點交換頂點再呼叫自己一次*/
    if(item.u != item.v && second_call == 'n' && mode == UNDIRECTED){
        exchange_edge.u = item.v;
        exchange_edge.v = item.u;
        exchange_edge.cost = item.cost;
        second_call = 'y';
        graphListInsertEdge(UNDIRECTED, target, exchange_edge);
    }

    /*重設second_call*/
    second_call = 'n';

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return 0;
    }

/*摧毀相鄰性List圖的函式*/
void graphDestroy(struct graph *target)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*指向要刪除節點的指標*/
    AdjListNode * curr_destroy_node = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*1-處理每個Head*/
    register unsigned i;
    for(i = 0; i < (*target).vertex_num; i++){
        /*1.1-如果Head沒有節點就跳過*/
        if((*target).adj_list[i] == NULL){
            continue;
        }

        /*將curr_destroy_node設定成Head指向的節點*/
        curr_destroy_node = (*target).adj_list[i];

        /*1.2-在該Head指向的節點後方的節點尚未釋放之前*/
        while(curr_destroy_node->next != NULL){
            /*1.2.1-在curr_destroy_node指向的下一個節點的next不是NULL時將
                    curr_destroy_node指向下一個節點*/
            for(; curr_destroy_node->next->next != NULL ; curr_destroy_node = curr_destroy_node->next){
                ;
            }
            /*1.2.2-將curr_destroy_node的節點指向的下一個節點釋放*/
            free(curr_destroy_node->next);
            curr_destroy_node->next = NULL;

            /*1.2.3-將curr_destroy_node設定成Head指向的節點*/
            curr_destroy_node = (*target).adj_list[i];

        }

        /*1.3-將Head指向的節點釋放*/
        free((*target).adj_list[i]);
        (*target).adj_list[i] = NULL;

    }

    /*把target釋放掉*/
    free((*target).adj_list);
    (*target).adj_list = NULL;
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*離開*/
    return ;
    }

/*輸出相鄰性List圖的函式*/
void graphPrint(const Graph target)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*現在正在讀取node的位置的指標*/
    AdjListNode * curr_read_node_pos = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*從第一個輸出到最後一個Head*/
    register unsigned i;
    for(i = 0; i < target.vertex_num; i++){
        /*輸出Head*/
        printf("頂點""(Vertex)""%u""與""(links with)", i);

        /*如果沒有*/
        if(target.adj_list[i] == NULL){
            printf("無頂點相連""(no vertex)。\n");
            continue;
        }

        /*輸出節點*/
        printf("頂點""(vertex)");
        for(curr_read_node_pos = target.adj_list[i];
            curr_read_node_pos != NULL;
            curr_read_node_pos = curr_read_node_pos->next){
            if(curr_read_node_pos == target.adj_list[i]){
                printf("%u(%d)", curr_read_node_pos->connected_vertex, curr_read_node_pos->weight);
            }
            else{
                printf(",%u(%d)", curr_read_node_pos->connected_vertex, curr_read_node_pos->weight);
            }
        }

        printf("相連。\n");
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return ;
    }

/*適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式*/
/*版本：1.00(1)*/
void graphAdjListDFS(const Graph target, const Vertex root, unsigned max_adj_list_size)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零*/
    static unsigned *visited;

    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 0;

    /*用來讀取Node的指標*/
    AdjListNode *readPtr = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*如果剛開始呼叫就動態配置visited陣列*/
    if(call_level == 0){
      visited = (unsigned *)malloc(sizeof(unsigned) * max_adj_list_size);
      memset(visited, 0, sizeof(unsigned) * max_adj_list_size);
    }
    /*將root的head標記為已拜訪*/
    visited[root] = 1;

    /**/
    printf("%d->", root);

    /**/
    for(readPtr = target.adj_list[root]; readPtr != NULL; readPtr = readPtr->next){
        /*如果還沒拜訪過該節點*/
        if(visited[readPtr->connected_vertex] != 1){
            /*用該節點進行呼叫*/
            call_level++;
            graphAdjListDFS(target, readPtr->connected_vertex, max_adj_list_size);
        }
    }

    if(call_level != 1){
        call_level--;
    }
    else{
        register unsigned i;
        for(i = 0; i < max_adj_list_size; i++){
            visited[i] = 0;
        }
        printf("END\n");
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*離開函式*/
    return ;
    }

/*適用於相鄰性List(Adjacency List)的計算dfn、low值函式
  傳入參數：圖target、子頂點、parent頂點
  回傳參數：執行狀態*/
short int graphAdjListDfnLow(Graph target, Vertex child, Vertex parent, unsigned max_adj_list_size)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零（改為用dfn值 = -1代替無拜訪過。）*/
    /*static unsigned visited[MAX_ADJ_LIST_SIZE] = {0};*//*被替代*/

    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 0;

    /* 用來保存dfn、low值的靜態陣列
     * 以靜態指標變數保存動態配置的陣列空間*/
    static short int *dfn = NULL, *low = NULL;

    /*用來遞增dfn跟low的變數*/
    static int num;

    /*讀取List的指標*/
    AdjListNode * readPtr = NULL;

    /*暫存讀取到的下一個子頂點的頂點*/
    Vertex next_child;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*在最外層呼叫時動態配置並初始化dfn、low值陣列*/
    if(call_level == 0){
        register unsigned i;

        dfn = (short int *)malloc(sizeof(short int) * max_adj_list_size);
        low = (short int *)malloc(sizeof(short int) * max_adj_list_size);
        for(i = 0; i < max_adj_list_size; i++){
            dfn[i] = low[i] = -1;
        }
        num = 0;
        call_level = 1;
    }

    /*設定child頂點的dfn值為num，low值先設為跟dfn值一樣，有變再改*/
    dfn[child] = low[child] = num++;

    /*從相鄰性List的第一項至最後一項*/
    for(readPtr = target.adj_list[child]; readPtr != NULL; readPtr = readPtr->next){
        /*從指標獲取下一個子頂點*/
        next_child = readPtr->connected_vertex;

        /*如果還沒拜訪過下一個子頂點*/
        if(dfn[next_child] == -1){
            /*用下一個子頂點當作子頂點呼叫本身*/
            call_level++;
            graphAdjListDfnLow(target, next_child, child, max_adj_list_size);

            /*如果呼叫完表示說low(u)跟low(w)計算好了嗎？*/
            low[child] = MIN_OF_2(low[child], low[next_child]);
        }
        /*如果拜訪過下一個子頂點，下一個子頂點又不是parent頂點的話...*/
        else if(next_child != parent){
            /**/
            /*low(child) = min(low(child), dfn(next_child))*/
            low[child] = MIN_OF_2(low[child], dfn[next_child]);
        }
    }

    /*如果是level = 1就結束，不然level--*/
    if(call_level != 1){
        call_level--;
    }
    else{
#ifdef DEBUG
        /*輸出測試數據*/
        register unsigned j, k;

        for(j = 0; j < max_adj_list_size; ){

            for(k = 0; k < max_adj_list_size; k++){
                /*測試輸出*/
                if(dfn[k] == j){
                    printf("dfn(%u)=%d  low(%u)=%d\n", k, dfn[k], k, low[k]);
                    j++;
                }
                else if(dfn[k] == -1){
                    printf("dfn(%u)=%d  low(%u)=%d\n", k, dfn[k], k, low[k]);
                    j++;
                }
            }
        }
#endif

        /*清除靜態陣列以後才能繼續使用dfnlow函式
        register unsigned i;

        for(i = 0; i < max_adj_list_size; i++){*/
            /*clear
            dfn[i] = low[i] = -1;
        }
        num = 0;*/
        /*釋放動態配置的記憶體*/
        free(dfn);free(low);

    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回執行狀態*/
    return 0;
    }

/*適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式*/
short int graphAdjListFBC(Graph target, Vertex child, Vertex parent, unsigned max_stack_size, unsigned max_adj_list_size)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 0;
    /*指向堆疊top位置指標或註標(subscript)*/
    static int stack_top = -1;
    /* 用來保存dfn、low值的靜態陣列
     * 以靜態指標變數保存動態配置的陣列空間*/
    static short *dfn = NULL, *low = NULL;
    /*用來遞增dfn跟low的變數*/
    static int num;
    /*宣告一個堆疊(Stack)*/
    static StackElement *stack;

    /*讀取List的指標*/
    AdjListNode * readPtr = NULL;
    /*暫存讀取到的下一個子頂點的頂點*/
    Vertex next_child;
    /*暫時存放stack的edge*/
    StackElement temp_edge;

    /*回傳狀態
     * FIXME:why unused?*/
    short call_result;

    temp_edge.u = 0;
    temp_edge.v = 0;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*在最外層呼叫時動態配置並初始化dfn、low值陣列*/
    {
    if(call_level == 0){
        /**/
        register unsigned i;


        /*FIXME:malloc check!*/
        stack = (StackElement *)malloc(sizeof(StackElement) * max_stack_size);
        dfn = (short *)malloc(sizeof(short) * max_adj_list_size);
        low = (short *)malloc(sizeof(short) * max_adj_list_size);

        for(i = 0; i < max_adj_list_size; i++){
            dfn[i] = low[i] = -1;
        }
        num = 0;
        call_level = 1;
    }
    }

    /*設定child頂點的dfn值為num，low值先設為跟dfn值一樣，有變再改*/
    dfn[child] = low[child] = num++;

    /*從相鄰性List的第一項至最後一項*/
    for(readPtr = target.adj_list[child]; readPtr != NULL; readPtr = readPtr->next){
        /*從指標獲取下一個子頂點*/
        next_child = readPtr->connected_vertex;

        /**/
        if(parent != next_child && dfn[next_child] < dfn[child]){
            /*將線push至stack中*/
            temp_edge.u = child;
            temp_edge.v = next_child;
            call_result = stackPush(temp_edge, stack, &stack_top, max_stack_size);
            if(call_result == -1){
              fprintf(stderr, ERROR_TAG"尋找多連結圖元件(Biconnected Component)失敗！\n");
              return -1;
            }
            /*如果next_child沒有拜訪過*/
            if(dfn[next_child] == -1){
                /*用下一個子頂點當作子頂點呼叫本身*/
                call_level++;
                graphAdjListFBC(target, next_child, child, max_stack_size, max_adj_list_size);

                /*如果呼叫完表示說low(u)跟low(w)計算好了嗎？*/
                /*low(child) = min(low[child], low[next_child])
                low[child] = MIN_OF_2(low[child], low[next_child]);*/

                /*如果low(w) >= dfn(u)（發現關節點*/
                if(low[next_child] >= dfn[child]){

                    printf("找到一個新的biconnected component：\n"
                           "Find a new biconnected component:\n");
                    do{
                        /*自stack delete edge*/
                        temp_edge = stackPop(stack, &stack_top, &call_result);
                        if(call_result == -1){
                            printf("ERROR!\n");
                            return -1;
                        }
                        printf("<%d,%d>", temp_edge.u, temp_edge.v);

                    }while(!((temp_edge.u == child) && (temp_edge.v == next_child)));
                    putchar('\n');
                }
            }
            else if(next_child != parent){
                low[child] = MIN_OF_2(low[child], dfn[next_child]);
            }
        }
        /*如果拜訪過下一個子頂點，下一個子頂點又不是parent頂點的話...*/
        else if(next_child != parent){
            /**/
            /*low(child) = min(low(child), dfn(next_child))*/
            low[child] = MIN_OF_2(low[child], dfn[next_child]);
        }
    }

    /*如果不是最外層呼叫就level-1*/
    if(call_level != 1){
        call_level--;
    }
    else{
        /*釋放記憶體*/
        free(dfn);dfn = NULL;
        free(low);low = NULL;
        free(stack);stack = NULL;

        /*將call_level重置為零*/
        call_level = 0;
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return 0;
    }

/*初始化Graph函式：根據vertex_num的量動態配置記憶體作為AdjListHead的陣列*/
short graphInit(struct graph *target, const unsigned vertex_num, GraphTypes type)
  {
    /* 要求記憶體 */
    target->adj_list = malloc(sizeof(AdjListHead) * vertex_num);
    if(target->adj_list == NULL){
      fprintf(stderr, ERROR_TAG ERROR_MEMORY_ALLOCATION_FAIL);
      return -1;
    }
    {/* memory guard */
      /**/
      unsigned counter01;
      for(counter01 = 0; counter01 < vertex_num; ++counter01){
        target->adj_list[counter01] = NULL;
      }
    }
    target->vertex_num = vertex_num;
    target->type = type;

    target->destroy = graphDestroy;
    target->insertEdge = graphListInsertEdge;
    target->print = graphPrint;
    target->isEmpty = graphIsEmpty;
    target->unitTest = graphUnitTest;
    target->prim_sMST = graphPrim_sMST;
    target->getEdgeWeight = graphGetEdgeWeight;
    return 0;
  }

short graphIsEmpty(Graph target)
  {
    return !target.vertex_num;
  }

/* 查詢某已知邊的weight的函式 */
int graphGetEdgeWeight(Graph target, Edge query, short *result)
{
  AdjListNode *iterator;
  for(iterator = target.adj_list[query.getU(query)];
      iterator != NULL;
      iterator = iterator->next){
    if(iterator->connected_vertex == query.getV(query)){
      /* 操作成功完成 */
      *result = 0;
      return iterator->weight;
    }
  }

  /* 找不到欲求weight的邊 */
  *result = -1;
  return -1;
}

short graphUnitTest(void)
{
  printf("開始進行GraphADT元件測試。\n");
  /* 測試Graph::init, insertEdge... */{
    Graph graph01;
    /*用來保存函式運行結果的變數*/
    short func_call_result = 0;
    Edge testEdge;

    printf("=====測試Graph::init, insertEdge...開始=====\n");
    /*初始化測試亂數產生器*/
    srand(time(NULL));

    /*初始化Graph*/
    graph01.init = graphInit;
    graph01.init(&graph01, GRAPH01_VERTEX_QUANTITY, UNDIRECTED);

    /*for迴圈*/{
      register unsigned i;
      for(i = 1; i <= GRAPH01_EDGE_QUANTITY; i++){
        testEdge.init = edgeInit;
        testEdge.init(&testEdge);
        do{
          testEdge.setEdge(&testEdge, rand() % GRAPH01_VERTEX_QUANTITY, rand() % GRAPH01_VERTEX_QUANTITY, -1);
        }while(testEdge.getU(testEdge) == testEdge.getV(testEdge));

        /*測試將edge插入相鄰性List中*/
        func_call_result = (graph01.insertEdge)(UNDIRECTED, graph01, testEdge);
        if(func_call_result != 0){
          switch(func_call_result){
          case -1:
            printf("軟體使用之graphListInsertEdge函式向作業系統要求記憶體空間失敗！\n"
                   "請檢查系統的可用記憶體空間是否足夠。\n"
                   "The function \"graphListInsertEdge\" in the software failed of requesting memory space from operating system!\n"
                   "Please check if the free memory space is sufficient.\n");
            break;
          case -2:
            printf("軟體使用之graphListInsertEdge函式偵測到引數item的member \n"
                   "u跟v兩個頂點相同（函式不允許頂點loop的邊線(edge)作為引數）。\n"
                   "The function \"graphListInsertEdge\" in the software detected\n"
                   "the augument \"item\"'s member:u and v vertex are same.\n"
                   "(Function doesn't permit a self-loop edge as an argument.)\n");
            break;
          default:
            printf("graphListInsertEdge函式發生未知的錯誤。\n"
                   "The graphListInsertEdge function has unknown error.\n");
            break;
          }
          printf("graphListInsertEdge函式異常退出！\n"
                 "graphListInsertEdge function has errorly exited!\n");
          return -1;
        }
      }
    }
    /*輸出list、 矩陣*/
    graph01.print(graph01);
    graph01.destroy(&graph01);
    printf("=====測試Graph::init, insertEdge...結束=====\n");
  }

  putchar('\n');
#if 0
    /*-----DFS、FBC--------*/
    {
    unsigned input_number;
    unsigned checksum = 0;
    do{
    printf("請輸入您要從哪一個頂點開始Depth First Search？\n"
           "Please enter which vertex you want to start Depth First Search?\n");
    printf("->");
    checksum = scanf("%u%*c", &input_number);
#ifdef DEBUG
        printf("input_number = %u\n", input_number);

#endif
    }while(input_number >= TEST_EDGE_QUANTITY || checksum != 1);

    /*呼叫適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式*/
    graphAdjListDFS(graph01, input_number, GRAPH01_VERTEX_QUANTITY);

    putchar('\n');

    /*呼叫適用於相鄰性List(Adjacency List)的計算各key頂點dfn、low值的函式*/
    /*graphAdjListDfnLow(graph01, 0, -1);*/

    /*putchar('\n');*/


    /*呼叫適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式*/
    graphAdjListFBC(graph01, 0, -1, MAX_STACK_SIZE, TEST_EDGE_QUANTITY);

    }
#endif

  /* 測試Prim's MST演算法 */{
    Vertex parent[6];
    Graph target;
    Edge input;

    printf("=====測試Prim's MST演算法=====\n");
    target.init = graphInit;
    target.init(&target, 6, UNDIRECTED);
    input.init = edgeInit;
    input.init(&input);
    input.setEdge(&input, 1 - 1, 2 - 1, 4);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 1 - 1, 3 - 1, 2);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 1 - 1, 5 - 1, 3);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 2 - 1, 4 - 1, 5);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 3 - 1, 4 - 1, 1);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 3 - 1, 5 - 1, 6);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 3 - 1, 6 - 1, 3);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 4 - 1, 6 - 1, 6);
    target.insertEdge(UNDIRECTED, target, input);
    input.setEdge(&input, 5 - 1, 6 - 1, 2);
    target.insertEdge(UNDIRECTED, target, input);
    target.print(target);

    target.prim_sMST(target, 4, parent);

    /* 印出結果 */{
      unsigned i;
      printf("parent[] = ");
      for(i = 0; i < 6; ++i){
        printf("%d ", parent[i]);
      }
      putchar('\n');
    }

    target.destroy(&target);
    printf("=====測試Prim's MST演算法結束=====\n");
  }

  putchar('\n');

  /* 測試Graph::getEdgeWeight() */{
    Graph graph03;
    /*用來保存函式運行結果的變數*/
    short func_call_result = 0;
    Edge testEdge;

    printf("=====測試Graph::init, insertEdge...開始=====\n");
    /*初始化測試亂數產生器*/
    srand(time(NULL));

    /*初始化Graph*/
    graph03.init = graphInit;
    graph03.init(&graph03, GRAPH03_VERTEX_QUANTITY, UNDIRECTED);

    /*for迴圈*/{
      register unsigned i;
      for(i = 1; i <= GRAPH03_EDGE_QUANTITY; i++){
        testEdge.init = edgeInit;
        testEdge.init(&testEdge);
        do{
          testEdge.setEdge(&testEdge, rand() % GRAPH03_VERTEX_QUANTITY, rand() % GRAPH03_VERTEX_QUANTITY, rand() % GRAPH03_MAX_WEIGHT);
        }while(testEdge.getU(testEdge) == testEdge.getV(testEdge));

        /*測試將edge插入相鄰性List中*/
        func_call_result = (graph03.insertEdge)(UNDIRECTED, graph03, testEdge);
        if(func_call_result != 0){
          switch(func_call_result){
          case -1:
            printf("軟體使用之graphListInsertEdge函式向作業系統要求記憶體空間失敗！\n"
                   "請檢查系統的可用記憶體空間是否足夠。\n"
                   "The function \"graphListInsertEdge\" in the software failed of requesting memory space from operating system!\n"
                   "Please check if the free memory space is sufficient.\n");
            break;
          case -2:
            printf("軟體使用之graphListInsertEdge函式偵測到引數item的member \n"
                   "u跟v兩個頂點相同（函式不允許頂點loop的邊線(edge)作為引數）。\n"
                   "The function \"graphListInsertEdge\" in the software detected\n"
                   "the augument \"item\"'s member:u and v vertex are same.\n"
                   "(Function doesn't permit a self-loop edge as an argument.)\n");
            break;
          default:
            printf("graphListInsertEdge函式發生未知的錯誤。\n"
                   "The graphListInsertEdge function has unknown error.\n");
            break;
          }
          printf("graphListInsertEdge函式異常退出！\n"
                 "graphListInsertEdge function has errorly exited!\n");
          return -1;
        }
      }
    }

    /* 輸出、查詢 */{
      Edge query;
      short query_result;
      int input_result = 0;
      Vertex u, v;

      graph03.print(graph03);
      query.init = edgeInit;
      query.init(&query);
      printf("請輸入欲查詢的邊（格式：(u,v)）後按Enter鍵\n");
      do{
        printf("->");
        input_result = scanf("(%d,%d)", &u, &v);
        getchar();
      }while(input_result != 2);
      query.setEdge(&query, u, v, -1);
      query.setEdge(&query, u, v, graph03.getEdgeWeight(graph03, query, &query_result));
      if(query_result == -1){
        printf("找不到邊。\n");
      }else{
        printf("weight = %d\n", query.getCost(query));
      }
    }

    graph03.destroy(&graph03);
    printf("=====測試Graph::init, insertEdge...結束=====\n");
  }

  /* done */
  printf("完成GraphADT元件測試。\n");
  return 0;
}

/*Prim's Minimum Spanning Tree演算法*/
short graphPrim_sMST(Graph target, Vertex root, Vertex parent[])
{
  Prim_sMSTcontainer h;
  unsigned *initial_weight = (unsigned *)malloc(sizeof(unsigned) * (target.vertex_num));
  if(initial_weight == NULL){
    return -1;
  }

  /* initialize key[], parent[] */{
    register unsigned i;
    for(i = 0; i < target.vertex_num; ++i){
      initial_weight[i] = INFINITE;
      /* 未被賦值的節點預設為-1 */
      parent[i] = -1;
    }
    /* 讓根節點一開始的weight為零，讓他於第一次循環時被delete出來 */
    initial_weight[root] = 0;
    parent[root] = -1;
  }

  /* initialize minheap */{
    h.init = primInit;
    h.init(&h, initial_weight, target.vertex_num);
    free(initial_weight);
    initial_weight = NULL;
  }

  /* 依序將最小weight的edge delete出來 */{
    register unsigned i;
    for(i = 1; i <= target.vertex_num; ++i){
      Vertex deleted;

      deleted = h.del(&h);

      /* 更新h中各個為未於tree中的頂點至tree的最小weight */{
        AdjListNode *iterator;

        for(iterator = target.adj_list[deleted];
            iterator != NULL;
            iterator = iterator->next){
          /* 如果在MST外含有與deleted相鄰的頂點且deleted到該節點的weight小於MST
           * 到該頂點的最小weight，則將MST到該頂點的最小weight換為deleted到該頂
           * 點的weight並將該頂點的父母節點設定為deleted
           */
          if(h.has(&h, iterator->connected_vertex) &&
             iterator->weight < h.keyOf(&h, iterator->connected_vertex)){
            h.decrease(&h, iterator->connected_vertex, iterator->weight);
            parent[iterator->connected_vertex] = deleted;
          }
        }
      }
    }
  }

  h.destroy(&h);
  /* 成功完成 */
  return 0;
}

short primInit(Prim_sMSTcontainer *self, unsigned key[], unsigned size)
{
  /* 要求Vertex數 + 1大小的陣列 */
  self->heap.create = heapCreate;
  self->heap.create(&(self->heap), size, MIN_HEAP);

  /* 初始化各個成員函式 */
  self->destroy = primDestroy;
  self->del = primDel;
  self->has = primHeapHas;
  self->keyOf = primKeyOf;
  self->decrease = primDecrease;

  /* 依據key[]的資料新增未在MST中的節點至heap */{
    register unsigned i;
    HeapElement temp;
    for(i = 0; i < size; ++i){
      temp.v = i;
      temp.min_weight = key[i];
      self->heap.add(&(self->heap), temp);
    }
  }
  return 0;
}

void primDestroy(Prim_sMSTcontainer *self)
{
  self->heap.destroy(&(self->heap));
  return;
}

/*h.del(): deletes the item in h with the smallest weight and returns the vertex (由 h 中把距離目前 MST 距離最短的節點剔除)*/
Vertex primDel(Prim_sMSTcontainer *self)
{
  HeapElement temp;
  short dummy;
  temp = self->heap.del(&(self->heap), &dummy);

  return temp.v;
}

/*h.isin(w): returns true if vertex w is in h (這是一個簡單的測試函式, 可惜命名錯了, 想一下 isin 應該改成什麼?)*/
short primHeapHas(Prim_sMSTcontainer *self, Vertex w)
{
  return self->heap.has(&(self->heap), w);
}

unsigned primKeyOf(Prim_sMSTcontainer *self, Vertex w)
{
  return self->heap.keyOf(&(self->heap), w);
}

void primDecrease(Prim_sMSTcontainer *self, Vertex w, unsigned new_weight)
{
  self->heap.decrease(&(self->heap), w, new_weight);
  return;
}

