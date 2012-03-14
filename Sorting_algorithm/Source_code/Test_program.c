/*程式框架(Program Framework)
-------------------------------------------------------------------
程式名稱(Program Name)：。
程式敘述(Program Description)：。
程式版本(Program Version)：0.00(0)
程式框架版本(Program Framework Version)：A
程式框架修訂號(Program Framework Revision Number)：40
最新更新紀錄(Latest Update Log)：專案開始。
更新紀錄(Changelog)：
0.00(0)　專案開始
已知問題(Known Issue)：

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
/*////////程式所include的標頭檔(Included Headers)////////*/
/*標準輸入／輸出函式庫(standard input/output library)
  版本：1.12(4)
  for printf(), scanf(), fgetc()...etc*/
#include <stdio.h>
/*or in C++*/
/*#include <cstdio>*/

/*C Standard General Utilities Library
  版本：1.01(8)*/
#include <stdlib.h>
/*or in C++*/
/*#include <cstdlib>*/

/*header for Date and time functions Library
  版本：1.02(3)*/
#include <time.h>

/*my sort functions*/
#include "Insertion_sort.h"
#include "Bubble_sort.h"
#include "Merge_sort.h"
#include "Heap_sort.h"

/*Randomize_algorithm*/
#include "Randomize_algorithm/Randomize_algorithm.h"

/*Display_content_algorithm*/
#include "Display_content_algorithm/Display_array.h"

/*Copy_algorithm*/
#include "Copy_algorithm/Copy_algorithm.h"

/*////////環境設定(Environment Settings)////////*/
/*是否顯示偵錯數據（０為否）？*/
#define SHOW_DEBUG_MESSAGE 1

/*編譯ＯＳ種類：
Windows console = 0, Linux console = 1, Symbian console = 2, PSP console = 3*/
#define SYSTEM_CATEGORY 1

/*////////常數與巨集(Constants & Macros)////////*/
/* */
#define SIZE 15

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式原型(Function Prototypes)////////*/
/*暫停運行函式的function prototype*/
short int mainPauseProgram(void);

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*main函式（C語言程式的進入點）
  版本：1.00(17)
*/
int main(void)
    {
    /*宣告與定義(Declaration & Definition)*/
    /* create a random array*/
    int unsorted[SIZE], sorted[SIZE];

    /* heapsort need variable size...make them happy*/
    unsigned heap_size = SIZE;
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*程式從這個標籤重新啟動(program restarts from this label)*/
    restart_program:


    randomizeArray(unsorted, SIZE, 0, 99);
    copyArrayInt(sorted, unsorted, SIZE);

    /*print unsorted array*/
    printf( "Unsorted array:\n" );
    displayArrayInt(unsorted, SIZE, 2, " ", 15);

    putchar('\n');

    printf("******insertion sort******\n");
    insertionSort( sorted, SIZE );
    printf( "Sorted array:\n" );
    displayArrayInt(sorted, SIZE, 2, " ", 15);

    printf( "\n\n" );
    copyArrayInt(sorted, unsorted, SIZE);

    printf("******bubble sort******\n");
    bubbleSort(sorted, SIZE, sortDescendingly);
    printf( "Sorted array(descendingly):\n" );
    displayArrayInt(sorted, SIZE, 2, " ", 15);

    copyArrayInt(sorted, unsorted, SIZE);

    bubbleSort(sorted, SIZE, sortAscendingly);
    printf( "Sorted array(ascendingly):\n" );
    displayArrayInt(sorted, SIZE, 2, " ", 15);

    printf( "\n\n" );
    copyArrayInt(sorted, unsorted, SIZE);

    printf("******merge sort******\n");
    mergeSort(sorted, 0, SIZE - 1);
    printf( "Sorted array:\n" );
    displayArrayInt(sorted, SIZE, 2, " ", 15);

    printf( "\n\n" );
    copyArrayInt(sorted, unsorted, SIZE);

    printf("******heap sort******\n");
    heap_size = SIZE;
    heapSortInt(sorted, heap_size);
    printf( "Sorted array:\n" );
    displayArrayInt(sorted, SIZE, 2, " ", 15);

    /*呼叫暫停運行函式(放在main函式中)*/
    if(mainPauseProgram() == 1){
        goto restart_program;
    }

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回數字０（表程式運行成功）*/
    return 0;
    }

/*－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
  暫停運行函式
  版本：1.30(9)*/
short int mainPauseProgram(void)
    {
	printf("\n------------------------------------------------\n");

	printf("顯示運行結果，程式暫停運行...\nProgram paused for displaying execution result...\n");

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
