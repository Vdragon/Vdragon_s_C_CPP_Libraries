/*程式框架(Program Framework)
  -------------------------------------------------------------------
  程式名稱(Program Name)：圖的資料結構與演算法。
  程式敘述(Program Description)：。
  程式版本(Program Version)：0.00(5)201106161840
  程式框架版本(Program Framework Version)：A
  程式框架修訂號(Program Framework Revision Number)：38
  最新更新紀錄(Latest Update Log)：專案開始。

更新紀錄(Changelog)：
0.00(0)　專案開始
0.00(1)201106041639　加了一些東西
0.00(2)201106070131　加入DFS
0.00(4)201106151815　加入相鄰性陣列DFS
0.00(5)201106161840
完成
將邊插入相鄰性陣列函式
插入一個邊(edge)至相鄰性List函式
摧毀相鄰性List圖的函式
輸出相鄰性List圖的函式
對counter優化
以及bug修正
0.00(3)201106080102
完成：
插入一個邊(edge)至相鄰性List圖中的函式--漏一、邊界檢查錯誤修正
加了const
將邊插入相鄰性陣列函式加入自loop邊線偵測功能
更新紀錄(Changelog)：
已知問題(Known Issue)：
0.00(2)：出現重複頂點->解決

--------------注意事項--------------

１.有BUG先檢查scanf()參數的資料型態是否正確。
２.不同的compiler可能有處理函數、變數之先後差異，請＊不要＊在同一語句(Statement)中同時處理兩者。
３.運行函數要注意是否有return值。
４.在condition statement 中要使用多個AND、OR混合之判斷句時宜將AND分隔之各OR句用括號括起來。
５.用指標陣列指向字串之方式定義string literal 請用const char * 〔指標名稱〕 = 〔字串〕;
６. * (dereferencing operater) 優先級很低，與其他運算子在同一個語句中需檢查其優先級。
*/
/*--------------程式碼開始(Code Started)--------------*/
/*--------------前置處理器選項(Preprocessor Code)--------------*/
/*程式所include的標頭檔(Included Headers)*/
/*standard input/output library*/
/*版本：1.10(1)*/
#include <stdio.h> /*for printf(), scanf(), fgetc()*/
/*or in C++*/
/*#include <cstdio>*/

/*C Standard General Utilities Library*/
/*版本：1.00(6)*/
#include <stdlib.h>
/*or in C++*/
/*#include <cstdlib>*/

/*header for Date and time functions Library*/
/*版本：1.00(1)*/
#include <time.h>

/*環境設定(Environment Settings)*/
/*是否顯示偵錯數據（０為否）？*/
#define SHOW_DEBUG_MESSAGE 1

/*編譯ＯＳ種類*/
#define SYSTEM_CATEGORY 1/*Windows console = 0, Linux console = 1, Symbian console = 2, PSP console = 3*/

/*----常數與巨集(Constants & Macros)----*/
/*adjacency矩陣表示法最大大小*/
#define MAX_ADJ_MATRIX_SIZE 10

/*adjacency list表示法頂點數量*/
#define MAX_ADJ_LIST_SIZE 10

/*真／假*/
#define TRUE 1
#define FALSE 0

/*比較兩數較小值的巨集*/
#define MIN_OF_2(x, y) (x < y ? (x) : (y))

/*堆疊(Stack)*/
/*定義堆疊(Stack)最大容量大小*/
#define MAX_STACK_SIZE 100

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*----資料結構(Structures), typedefs, enums----*/
/*圖的資料結構（adjacency lists表示法）*/
typedef struct adjListNode * AdjListHead;
typedef struct adjListNode{
    signed connected_vertex;
    struct adjListNode * next;
}AdjListNode;

/*點的資料結構*/
typedef signed Vertex;

/*邊的資料結構*/
typedef struct edge{
    Vertex u, v;
}Edge;

/*圖的宣告*/
/*typedef unsigned Graph;*/
typedef AdjListHead * Graph;

/*圖的類型設定*/
typedef enum graphTypes{
    UNDIRECTED, DIRECTED
}GraphTypes;

/*堆疊(Stack)元素資料結構*/
typedef Edge StackElement;

/*----函式原型(Function Prototypes)----*/
/*暫停運行函式的function prototype*/
short int main_pause_program(void);

/*創造一個圖的函式的function prototype*/
/*Graph graphMatrixCreate(void);*/

/*插入一個頂點(vertex)至相鄰性矩陣圖中的函式的function prototype*/
/*short int graphMatrixInsertVert(GraphTypes mode, Graph target, Vertex v);*/

/*插入一個頂點(vertex)至相鄰性List圖中的函式的function prototype*/
short int graphListInsertVert(GraphTypes mode, Graph target, Vertex v);

/*插入一個邊(edge)至相鄰性矩陣圖中的函式的function prototype*/
short int graphMatrixInsertEdge(GraphTypes mode, Graph target[][MAX_ADJ_MATRIX_SIZE], Edge item);

/*插入一個邊(edge)至相鄰性List圖中的函式的function prototype*/
short int graphListInsertEdge(GraphTypes mode, Graph target, Edge item);

/*輸出相鄰性矩陣圖的函式的function prototype*/
/*void graphMatrixOutput(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE]);*/

/*輸出相鄰性List圖的函式的function prototype*/
void graphListOutput(const Graph target);

/*摧毀相鄰性陣列圖的函式的function prototype*/
/*void graphMatrixDestroy(Graph target[][MAX_ADJ_MATRIX_SIZE]);*/

/*摧毀相鄰性List圖的函式的function prototype*/
void graphListDestroy(Graph target);

/*於圖中刪除一個頂點(vertex)（及其連結邊）的函式的function prototype*/
/*Graph graphDeleteVertex(Graph target, Vertex item);*/

/*於圖中刪除一個邊(edge)的函式的function prototype*/
/*Graph graphDeleteEdge(Graph target, Edge item);*/

/*確認圖為空函式的function prototype*/
/*short int graphIsEmpty(Graph target);*/

/*製作並回傳與target圖中item頂點的Adjacency List的函式的function prototype的function prototype*/
/*AdjListHead graphVertAdj(Graph target, Vertex item);*/

/*適用於相鄰性陣列(Adjacency Matrix)的深度優先搜尋(Depth First Search)函式的function prototype*/
/*void graphAdjMatDFS(Graph graph_adj_matrix[][MAX_ADJ_MATRIX_SIZE], const Vertex root);*/

/*適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式的function prototype*/
void graphAdjListDFS(const Graph target, const Vertex root);

/*適用於相鄰性陣列(Adjacency Matrix)的廣度優先搜尋(B First Search)函式的function prototype*/
/*short int graphAdjMatBFS(Graph target);*/

/*適用於相鄰性List(Adjacency List)的廣度優先搜尋(B First Search)函式的function prototype*/
/*unsigned * graphAdjListBFS(Graph target, Vertex root);*/

/*適用於相鄰性List(Adjacency List)的計算dfn、low值函式的function prototype*/
short int graphAdjListDfnLow(Graph target, Vertex child, Vertex parent);

/*適用於相鄰性陣列(Adjacency Matrix)的尋找多連結圖元件(Biconnected Component)函式的function prototype*/
/*short int graphAdjMatFBC(Graph target);*/

/*適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式的function prototype*/
short int graphAdjListFBC(Graph target, Vertex child, Vertex parent);

/*將元素pop出堆疊的函式的function prototype*/
StackElement stackPop(StackElement stack[], int *stack_top);

/*判斷堆疊是否為空函式的function prototype*/
inline short int stackIsEmpty(int stack_top);

/*判斷堆疊是否已滿函式的function prototype*/
inline short int stackIsFull(int stack_top);

/*將元素push至堆疊的函式的function prototype*/
short int stackPush(StackElement item, StackElement stack[], int *stack_top);

/*----全域變數(Global Variables)----*/

/*--------------主要程式碼(Main Code)--------------*/
/*main函式
  版本：1.00(0)
  程式的運行從main函數開始*/
int main(void)
	{
	/*宣告與定義(Declaration & Definition)*/
    /*圖的宣告（adjacency矩陣表示法）*/
    Graph graph_adj_matrix1[MAX_ADJ_MATRIX_SIZE][MAX_ADJ_MATRIX_SIZE] = {{0}};

    /*圖的宣告（adjacency list表示法）*/
    AdjListHead graph_adj_list1[MAX_ADJ_LIST_SIZE] = {NULL};

    /*用來保存函式運行結果的變數*/
    short int func_call_result = 0;

    /*測試edge*/
    Edge testEdge;

	/*－－－－－－－－－－－－－－－－－－－－－*/
	/*程式從這個標籤重新啟動(program restarts from this label)*/
	restart_program:

    /*初始化測試亂數產生器*/
    srand(time(NULL));

    /*標題*/
    printf("圖的資料結構與演算法\n"
           "09957010_1A_林博仁 (c) 保留所有權利\n09957010_1A_Henry Lin (c) All RIGHTS RESERVED\n"
           "----------------------------------------------------------------\n");


    {/*測試迴圈*/
    /*for迴圈*/
    register unsigned i;

    for(i = 1; i <= 5; i++){
        /*測試edge*/
        testEdge.u = rand() % MAX_ADJ_LIST_SIZE;
        while((testEdge.v = rand() % MAX_ADJ_LIST_SIZE) == testEdge.u);

        /*testEdge.u = 0;*/
        /*testEdge.v = 2;*/

        /*測試edge插入陣列中*/
        func_call_result = graphMatrixInsertEdge(UNDIRECTED, graph_adj_matrix1, testEdge);
        if(func_call_result != 0){
            switch(func_call_result){
            case -1:
                printf("軟體使用之graphMatrixInsertEdge函式偵測到引數item的member \n"
                       "u跟v兩個頂點相同（函式不允許頂點loop的邊線(edge)作為引數）。\n"
                       "The function \"graphMatrixInsertEdge\" in the software detected\n"
                       "the augument \"item\"'s member:u and v vertex are same.\n"
                       "(Function doesn't permit a self-loop edge as an argument.)\n");
                break;
            default:
                printf("graphMatrixInsertEdge函式發生未知的錯誤。\n"
                       "The graphMatrixInsertEdge function has unknown error.\n");
                break;
            }
            printf("graphMatrixInsertEdge函式異常退出！\n"
                   "graphMatrixInsertEdge function has errorly exited!\n"
                   "軟體將跳至不會受到影響的位置繼續執行。\n"
                   "Software will jump to somewhere not affected to continue.\n");
            goto insert_edge_into_graph_matrix_end;
        }

        /*測試將edge插入相鄰性List中*/
        func_call_result = graphListInsertEdge(UNDIRECTED, graph_adj_list1, testEdge);
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
                   "graphListInsertEdge function has errorly exited!\n"
                   "軟體將跳至不會受到影響的位置繼續執行。\n"
                   "Software will jump to somewhere not affected to continue.\n");
            goto insert_edge_into_graph_list_end;
        }
        /*測試將edge插入相鄰性List中*/
    }
    }/*測試迴圈*/

    /*輸出list、 矩陣*/
    /*graphMatrixOutput(graph_adj_matrix1);*/
    graphListOutput(graph_adj_list1);

    insert_edge_into_graph_matrix_end:
    insert_edge_into_graph_list_end:

    /*-----DFS、FBC--------*/
    {
    unsigned input_number;
    unsigned checksum = 0;
    do{
    printf("請輸入您要從哪一個頂點開始Depth First Search？\n"
           "Please enter which vertex you want to start Depth First Search?\n");
    printf("->");
    checksum = scanf("%u%*c", &input_number);
    if(SHOW_DEBUG_MESSAGE){
        printf("input_number = %u\n", input_number);
    }
    }while(input_number >= MAX_ADJ_MATRIX_SIZE || checksum != 1);

    /*呼叫適用於相鄰性陣列(Adjacency Matrix)的深度優先搜尋(Depth First Search)函式*/
    /*graphAdjMatDFS(graph_adj_matrix1, input_number);*/

    /*呼叫適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式*/
    graphAdjListDFS(graph_adj_list1, input_number);

    putchar('\n');

    /*呼叫適用於相鄰性陣列(Adjacency Matrix)的計算各頂點dfn、low值的函式*/
    /*graphAdjMatDfnLow(graph_adj_matrix1, 0, -1);*/

    /*呼叫適用於相鄰性List(Adjacency List)的計算各頂點dfn、low值的函式*/
    /*graphAdjListDfnLow(graph_adj_list1, 0, -1);*/

    /*putchar('\n');*/


    /*呼叫適用於相鄰性陣列(Adjacency Matrix)的尋找多連結圖元件(Biconnected Component)函式*/
    /*graphAdjMatFBC(graph_adj_matrix1);*/

    /*呼叫適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式*/
    graphAdjListFBC(graph_adj_list1, 0, -1);

    }
    /*-------程式結束前清理----------*/
    /*Destroy graph_adj_list1*/
    graphListDestroy(graph_adj_list1);

    /*Clean graph_adj_matrix1*/
    /*graphMatrixDestroy(graph_adj_matrix1);*/

    /*呼叫暫停運行函式(放在main函式中)*/
    if(main_pause_program() == 1){
        goto restart_program;
    }

	/*－－－－－－－－－－－－－－－－－－－－－*/
	/*傳回數字０（表程式運行成功）*/
	return 0;
	}

/*插入一個邊(edge)至相鄰性陣列圖中的函式
  版本：1.00(1)*/
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

/*插入一個邊(edge)至相鄰性List圖中的函式
  版本：1.00(1)
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
    if(target[item.u] == NULL){
        /*1.1.1-要求一個節點的記憶體並附加在Head上*/
        target[item.u] = (AdjListNode *)malloc(sizeof(AdjListNode));

        /*1.1.2-如果要求記憶體失敗*/
        if(target[item.u] == NULL){
            return -1;
        }

        /*1.1.3-設定該節點*/
        target[item.u]->connected_vertex = item.v;
        target[item.u]->next = NULL;

        /*如果是無向圖且非第二次呼叫的話就將點交換頂點再呼叫自己一次*/
        if(second_call == 'n' && mode == UNDIRECTED){
            exchange_edge.u = item.v;
            exchange_edge.v = item.u;
            second_call = 'y';
            graphListInsertEdge(UNDIRECTED, target, exchange_edge);
        }
        second_call = 'n';

        /*1.1.4-正常離開*/
        return 0;
    }
    /*1.2-將current_node_position設定為第一個節點*/
    current_node_position = target[item.u];

    /*1.3-當還沒到最後一個節點前一直往前*/
    for(current_node_position = target[item.u];
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
    current_node_position->next->next = NULL;

    /*如果是無向圖且非第二次呼叫的話就將點交換頂點再呼叫自己一次*/
    if(item.u != item.v && second_call == 'n' && mode == UNDIRECTED){
        exchange_edge.u = item.v;
        exchange_edge.v = item.u;
        second_call = 'y';
        graphListInsertEdge(UNDIRECTED, target, exchange_edge);
    }

    /*重設second_call*/
    second_call = 'n';

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return 0;
    }

/*摧毀相鄰性List圖的函式
  版本：1.00(1)*/
void graphListDestroy(Graph target)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*指向要刪除節點的指標*/
    AdjListNode * curr_destroy_node = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*1-處理每個Head*/
    register unsigned i;
    for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
        /*1.1-如果Head沒有節點就跳過*/
        if(target[i] == NULL){
            continue;
        }

        /*將curr_destroy_node設定成Head指向的節點*/
        curr_destroy_node = target[i];

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
            curr_destroy_node = target[i];

            /*debug*/
            /*graphListOutput(target);*/
        }

        /*1.3-將Head指向的節點釋放*/
        free(target[i]);
        target[i] = NULL;

        /*debug*/
        /*graphListOutput(target);*/
    }

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*離開*/
    return ;
    }


/*摧毀相鄰性陣列圖的函式
  版本：1.00(0)*/
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

/*輸出相鄰性List圖的函式
  版本：1.00(3)*/
void graphListOutput(const Graph target)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*現在正在讀取node的位置的指標*/
    AdjListNode * curr_read_node_pos = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*從第一個輸出到最後一個Head*/
    register unsigned i;
    for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
        /*輸出Head*/
        printf("頂點""(Vertex)""%u""與""(links with)", i);

        /*如果沒有*/
        if(target[i] == NULL){
            printf("無頂點相連""(no vertex)。\n");
            continue;
        }

        /*輸出節點*/
        printf("頂點""(vertex)");
        for(curr_read_node_pos = target[i];
            curr_read_node_pos != NULL;
            curr_read_node_pos = curr_read_node_pos->next){
            if(curr_read_node_pos == target[i]){
                printf("%u", curr_read_node_pos->connected_vertex);
            }
            else{
                printf(",%u", curr_read_node_pos->connected_vertex);
            }
        }

        printf("相連。\n");
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return ;
    }

/*輸出相鄰性矩陣圖的函式
  版本：1.00(1)*/
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

/*適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式*/
/*版本：1.00(1)*/
void graphAdjListDFS(const Graph target, const Vertex root)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零*/
    static unsigned visited[MAX_ADJ_LIST_SIZE] = {FALSE};

    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 1;

    /*用來讀取Node的指標*/*
    AdjListNode * readPtr = NULL;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*將root的head標記為已拜訪*/
    visited[root] = TRUE;

    /**/
    printf("%d->", root);

    /**/
    for(readPtr = target[root]; readPtr != NULL; readPtr = readPtr->next){
        /*如果還沒拜訪過該節點*/
        if(visited[readPtr->connected_vertex] != TRUE){
            /*用該節點進行呼叫*/
            call_level++;
            graphAdjListDFS(target, readPtr->connected_vertex);
        }
    }

    if(call_level != 1){
        call_level--;
    }
    else{
        register unsigned i;
        for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
            visited[i] = FALSE;
        }
        printf("END\n");
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*離開函式*/
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

/*適用於相鄰性List(Adjacency List)的計算dfn、low值函式
  版本：1.10(2)
  傳入參數：圖target、子頂點、parent頂點
  回傳參數：執行狀態*/
short int graphAdjListDfnLow(Graph target, Vertex child, Vertex parent)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零（改為用dfn值 = -1代替無拜訪過。）*/
    /*static unsigned visited[MAX_ADJ_LIST_SIZE] = {FALSE};*//*被替代*/

    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 0;

    /*用來保存dfn、low值的靜態陣列*/
    static short int dfn[MAX_ADJ_LIST_SIZE], low[MAX_ADJ_LIST_SIZE];

    /*用來遞增dfn跟low的變數*/
    static int num;

    /*讀取List的指標*/
    AdjListNode * readPtr = NULL;

    /*暫存讀取到的下一個子頂點的頂點*/
    Vertex next_child;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*在最外層呼叫時初始化dfn、low值陣列*/
    {
    if(call_level == 0){
        register unsigned i;
        for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
            dfn[i] = low[i] = -1;
        }
        num = 0;
        call_level = 1;
    }
    }

    /*設定child頂點的dfn值為num，low值先設為跟dfn值一樣，有變再改*/
    dfn[child] = low[child] = num++;

    /*從相鄰性List的第一項至最後一項*/
    for(readPtr = target[child]; readPtr != NULL; readPtr = readPtr->next){
        /*從指標獲取下一個子頂點*/
        next_child = readPtr->connected_vertex;

        /*如果還沒拜訪過下一個子頂點*/
        if(dfn[next_child] == -1){
            /*用下一個子頂點當作子頂點呼叫本身*/
            call_level++;
            graphAdjListDfnLow(target, next_child, child);

            /*如果呼叫完表示說low(u)跟low(w)計算好了嗎？*/
            /*low(child) = min(low[child], low[next_child])*/
            low[child] = MIN_OF_2(low[child], low[next_child]);
        }
        /*如果拜訪過下一個子頂點，下一個子頂點又不是parent頂點的話...*/
        else if(next_child != parent){
            /*
            /*low(child) = min(low(child), dfn(next_child))*/
            low[child] = MIN_OF_2(low[child], dfn[next_child]);
        }
    }

    /*如果不是最外層呼叫就level-1*/
    if(call_level != 1){
        call_level--;
    }
    else{
        /*輸出測試數據*/
        register unsigned j, k;

        for(j = 0; j < MAX_ADJ_LIST_SIZE; ){

            for(k = 0; k < MAX_ADJ_LIST_SIZE; k++){
                /*測試輸出*/
                if(dfn[k] == j && SHOW_DEBUG_MESSAGE == 1){
                    printf("dfn(%u)=%d  low(%u)=%d\n", k, dfn[k], k, low[k]);
                    j++;
                }
                else if(dfn[k] == -1 && SHOW_DEBUG_MESSAGE == 1){
                    printf("dfn(%u)=%d  low(%u)=%d\n", k, dfn[k], k, low[k]);
                    j++;
                }
            }
        }

        /*清除靜態陣列以後才能繼續使用dfnlow函式*/
        register unsigned i;

        for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
            /*clear*/
            dfn[i] = low[i] = -1;
        }
        num = 0;
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回執行狀態*/
    return 0;
    }

/*將元素push至堆疊的函式
  版本：1.00(0)*/
short int stackPush(StackElement item, StackElement stack[], int *stack_top)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*如果堆疊已滿就錯誤離開*/
    if(stackIsFull(*stack_top)){
        return -1;
    }
    /*將元素插入堆疊中*/
    stack[++*stack_top] = item;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回0*/
    return 0;
    }

/*將元素pop出堆疊的函式*/
/*版本：0.00(0)*/
StackElement stackPop(StackElement stack[], int *stack_top)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*如果堆疊已滿就錯誤離開*/
    if(stackIsEmpty(*stack_top)){
        /*製造表示函式錯誤的元素*/
        StackElement errorElement = {-1, -1};
        /*傳回表示函式錯誤的元素*/
        return errorElement;
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回top位置的元素並遞減top*/
    return stack[--*stack_top];
    }

/*判斷堆疊是否為空函式*/
/*版本：0.00(0)*/
inline short int stackIsEmpty(int stack_top)
	{
    return (stack_top == -1) ? 1 : 0;
    }

/*判斷堆疊是否已滿函式*/
/*版本：0.00(0)*/
inline short int stackIsFull(int stack_top)
	{
    return (stack_top == MAX_STACK_SIZE - 1) ? 1 : 0;
    }

/*適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式*/
/*版本：0.00(0)*/
short int graphAdjListFBC(Graph target, Vertex child, Vertex parent)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*用來判斷該Head有無拜訪過的陣列，有為非零、沒有為零（改為用dfn值 = -1代替無拜訪過。）*/
    /*static unsigned visited[MAX_ADJ_LIST_SIZE] = {FALSE};*//*被替代*/

    /*用來判斷是否為最外層呼叫的靜態變數，假設最外層為１*/
    static unsigned call_level = 0;

    /*用來保存dfn、low值的靜態陣列*/
    static int dfn[MAX_ADJ_LIST_SIZE], low[MAX_ADJ_LIST_SIZE];

    /*用來遞增dfn跟low的變數*/
    static int num;

    /*讀取List的指標*/*
    AdjListNode * readPtr = NULL;

    /*暫存讀取到的下一個子頂點的頂點*/
    Vertex next_child;

    /*暫時存放stack的edge*/
    StackElement temp_edge;
    temp_edge.u = 0;
    temp_edge.v = 0;

    /*宣告一個堆疊(Stack)*/
    StackElement stack[MAX_STACK_SIZE];

    /*指向堆疊top位置指標或註標(subscript)*/
    int stack_top = -1;

    /*回傳狀態*/
    short int call_result;

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*在最外層呼叫時初始化dfn、low值陣列*/
    {
    if(call_level == 0){
        register unsigned i;
        for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
            dfn[i] = low[i] = -1;
        }
        num = 0;
        call_level = 1;
    }
    }

    /*設定child頂點的dfn值為num，low值先設為跟dfn值一樣，有變再改*/
    dfn[child] = low[child] = num++;

    /*從相鄰性List的第一項至最後一項*/
    for(readPtr = target[child]; readPtr != NULL; readPtr = readPtr->next){
        /*從指標獲取下一個子頂點*/
        next_child = readPtr->connected_vertex;

        /**/
        if(parent != next_child && dfn[next_child] < dfn[child]){
            /*將線push至stack中*/
            temp_edge.u = child;
            temp_edge.v = next_child;
            call_result = stackPush(temp_edge, stack, &stack_top);

            /*如果next_child沒有拜訪過*/
            if(dfn[next_child] == -1){
                /*用下一個子頂點當作子頂點呼叫本身*/
                call_level++;
                graphAdjListFBC(target, next_child, child);

                /*如果呼叫完表示說low(u)跟low(w)計算好了嗎？*/
                /*low(child) = min(low[child], low[next_child])
                low[child] = MIN_OF_2(low[child], low[next_child]);*/

                /*如果low(w) >= dfn(u)（發現關節點*/
                if(low[next_child] >= dfn[child]){
                    printf("找到一個新的biconnected component：\n"
                           "Find a new biconnected component:\n");
                    do{
                        /*自stack delete edge*/
                        temp_edge = stackPop(stack, &stack_top);
                        if(temp_edge.u == -1 && temp_edge.v == -1){
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

        /*清除靜態陣列以後才能繼續使用dfnlow函式*/
        register unsigned i;

        for(i = 0; i < MAX_ADJ_LIST_SIZE; i++){
            /*clear*/
            dfn[i] = low[i] = -1;
        }
        num = 0;
    }
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return 0;
    }

/*－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－*/
/*暫停運行函式*/
/*版本：1.30(8)*/
short int main_pause_program(void)
    {
	/*我是分隔線*/
	printf("\n------------------------------------------------\n");
	/*提示A*/
	printf("顯示運行結果，程式暫停運行...\nProgram paused for displaying execution result...\n");

	/*取得欲進行動作*/
	{
	/*儲存輸入的字元*/
	char inputChar;

    do{
        printf("請問您要重新運行本程式嗎（Ｙ／Ｎ）？\nDo you want to execute this program again(Y/N)?");

    /*確保輸入是正確的*/
    }while(!((inputChar = getchar()) == 'y' || inputChar == 'Y'
                || inputChar == 'n' || inputChar == 'N'));

	if(inputChar == 'y' || inputChar == 'Y'){
		/*丟掉換行符號*/
		scanf("%*c");

		/*清空螢幕*/
		if(SYSTEM_CATEGORY == 0){
			system("cls");
		}
		else{
			system("clear");
		}

		/*return true*/
		return 1;
	}
	}

	/*return false*/
		return 0;
    }
