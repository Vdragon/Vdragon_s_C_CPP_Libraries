
/*--------------程式碼開始(Code Started)--------------*/
/*--------------前置處理器選項(Preprocessor Code)--------------*/
/*程式所include的標頭檔(Included Headers)*/
/*standard input/output library*/
#include <stdio.h> /*for printf(), scanf(), fgetc()*/
/*C Standard General Utilities Library*/
#include <stdlib.h>
/*header for Date and time functions Library*/
#include <time.h>

/**/
#include "pauseProgram/Pause_program.h"
/**/
#include "Graph_abstract_data_type/Graph_abstract_data_type.list.h"

/*環境設定(Environment Settings)*/

/*----常數與巨集(Constants & Macros)----*/

/*堆疊(Stack)*/
/*定義堆疊(Stack)最大容量大小*/
#define MAX_STACK_SIZE 100

/*定義測試用的圖的邊、頂點數量*/
#define TEST_EDGE_QUANTITY 100
#define GRAPH01_VERTEX 100

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*----資料結構(Structures), typedefs, enums----*/


/*----函式原型(Function Prototypes)----*/

/*----全域變數(Global Variables)----*/

/*--------------主要程式碼(Main Code)--------------*/
/*main函式
  版本：1.00(0)
  程式的運行從main函數開始*/
int main(void)
	{
	/*宣告與定義(Declaration & Definition)*/
    /* 圖的宣告（adjacency list表示法）
     * FIXME:應該是graph1跟TEST_VERTEX_QUANTITY才對*/
    AdjListHead graph01[GRAPH01_VERTEX] = {NULL};

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

    for(i = 1; i <= 100; i++){
        /*測試edge*/
        testEdge.u = rand() % TEST_EDGE_QUANTITY;
        while((testEdge.v = rand() % TEST_EDGE_QUANTITY) == testEdge.u);
        testEdge.cost = -1;

        /*測試edge插入陣列中*/
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
            goto insert_edge_into_graph_list_end;
        }

        /*測試將edge插入相鄰性List中*/
        func_call_result = graphListInsertEdge(UNDIRECTED, graph01, testEdge);
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
    graphListOutput(graph01, GRAPH01_VERTEX);

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
#ifdef DEBUG
        printf("input_number = %u\n", input_number);

#endif
    }while(input_number >= TEST_EDGE_QUANTITY || checksum != 1);

    /*呼叫適用於相鄰性List(Adjacency List)的深度優先搜尋(Depth First Search)函式*/
    graphAdjListDFS(graph01, input_number, GRAPH01_VERTEX);

    putchar('\n');

    /*呼叫適用於相鄰性List(Adjacency List)的計算各頂點dfn、low值的函式*/
    /*graphAdjListDfnLow(graph01, 0, -1);*/

    /*putchar('\n');*/


    /*呼叫適用於相鄰性List(Adjacency List)的尋找多連結圖元件(Biconnected Component)函式*/
    graphAdjListFBC(graph01, 0, -1, MAX_STACK_SIZE, TEST_EDGE_QUANTITY);

    }
    /*-------程式結束前清理----------*/
    graphListDestroy(graph01, GRAPH01_VERTEX);

    /*呼叫暫停運行函式(放在main函式中)*/
    if(pauseProgram() == 1){
        goto restart_program;
    }

	/*－－－－－－－－－－－－－－－－－－－－－*/
	/*傳回數字０（表程式運行成功）*/
	return 0;
	}

