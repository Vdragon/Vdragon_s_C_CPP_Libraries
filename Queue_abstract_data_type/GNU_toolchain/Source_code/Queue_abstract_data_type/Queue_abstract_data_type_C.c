/*Queue_abstract_data_type_C.c
* -----------------------------------
* 更新紀錄 | Changelog
*  Changelog is now stored on GitHub
* 已知問題 | Known Issues
*  Known issues is now stored on GitHub
* 待辦事項 | Todos
*  Todo is now stored on GitHub
* 著作權宣告 | Copyright notice
*  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
* 智慧財產授權條款：
*  This program is part of this software
*  This software is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This software is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this software.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*header*/
#include "Queue_abstract_data_type_C.h"

/* 訊息標籤 */
#include "../Messages_templates/zh_TW.h"

/* ====標準C函式庫==== */
#include <stddef.h>
/* fprintf() */
#include <stdio.h>
/* malloc() */
#include <stdlib.h>
/* cassert() */
#include <assert.h>

/*////////常數與巨集(Constants & Macros)////////*/
/* 測試的Queue大小 */
#define TEST_SIZE 10

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式和函式雛型(Function & Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/* 初始化Queue物件的函式 */
short queueCreate(Queue *target, unsigned queue_size)
{
  /* 檢查錯誤的參數 */
  if(queue_size == 0){
    fprintf(stderr, ERROR_TAG QUEUE_ADT_TAG "無法初始化一個大小為0的隊列(Queue)！");
    return -1;
  }

  /* 建立隊列(queue)陣列 */
  target->queue = (QueueElement *)malloc(sizeof(QueueElement) * queue_size);
  target->size = queue_size;
  target->rear = NULL;

  /* 保存各個member function的指標到Reference */
  target->DestroyRef = queueDestroy;
  target->LengthRef = queueLength;
  target->AddRef = queueAdd;
  target->DeleteRef = queueDelete;
  target->IsEmptyRef = queueIsEmpty;
  target->IsFullRef = queueIsFull;
  target->UnitTestRef = queueUnitTest;

  /* Queue初始化成功 */
  return 0;
}

/* 摧毀Queue的函式 */
void queueDestroy(Queue *target)
{
  free(target->queue);
  target->queue = target->rear = NULL;
  target->size = 0;
  return;
}

/* 取得隊列(queue)目前長度的函式 */
unsigned queueLength(Queue *target)
{
  return (target->rear - target->queue) + 1;
}

 /*將元素add至queue的函式*/
 short queueAdd(Queue *self, QueueElement item)
 {
   /*如果queue已滿就錯誤離開*/
   if(queueIsFull(self)){
#ifndef NDEBUG
     fprintf(stderr, ERROR_TAG QUEUE_ADT_TAG ERROR_QUEUE_ADD_FULL);
#endif
     return -1;
   }
   /* 如果隊列(queue)是空的就更動head跟tail */
   if(queueIsEmpty(self)){
     self->rear = self->queue;
     self->queue[0] = item;
   }else{
     /*將元素插入queue中*/
     self->rear += 1;
     *(self->rear) = item;
   }
   /* add操作完成 */
   return 0;
 }

 /*將元素delete出queue的函式*/
 QueueElement queueDelete(Queue *self, short *result)
 {
   QueueElement deleted;

   /*如果queue已空就錯誤離開*/
   if(queueIsEmpty(self)){
#ifndef NDEBUG
     fprintf(stderr, ERROR_TAG QUEUE_ADT_TAG ERROR_QUEUE_DELETE_EMPTY);
#endif
     QueueElement dummy;
     *result = -1;
     return dummy;
   }

   /*傳回head位置的元素 */
   deleted = self->queue[0];

   /* 如果只剩下一個則無效化head、rear */
   if(queueLength(self) == 1){
     self->rear = NULL;
   }else{
     QueueElement *gap = NULL;
     /* 將後面的元素往前面移動一位 */
     for(gap = self->queue; gap < self->rear; ++gap){
       *gap = *(gap + 1);
     }
     --self->rear;
   }
   *result = 0;
   return deleted;
 }

/*判斷Queue是否為空函式*/
short int queueIsEmpty(Queue *target)
{
  return target->rear == NULL;
}

 /*判斷Queue是否已滿函式*/
 short int queueIsFull(Queue *target)
 {
   return queueLength(target) == target->size;
 }

/* 進行元件測試的函式 */
short queueUnitTest(void)
{
  Queue test;
  QueueElement item;
  short call_result;

  /*  */{
    unsigned i;

    test.CreateRef = queueCreate;
    (*test.CreateRef)(&test, TEST_SIZE);
    assert(test.rear == NULL);

    for(i = 0; i < TEST_SIZE + 1; ++i) {
      item.data = i;
      call_result = (*test.AddRef)(&test, item);
      if(i < TEST_SIZE){
        assert(call_result == 0);
      }else{
        assert(call_result != 0);
      }
    }
    for(i = 0; i < TEST_SIZE + 1; ++i){
      item = (*test.DeleteRef)(&test, &call_result);
      if(i < TEST_SIZE){
        assert(call_result == 0 && item.data == i);
      }else{
        assert(call_result != 0);
      }
    }
  }
  queueDestroy(&test);

  /* 測試完全通過 */
  fprintf(stdout, QUEUE_ADT_TAG "元件測試完全通過！");
  return 0;
}

 /*將元素add至環狀Queue的函式*/
 short int cirQueueAdd(CirQueueElement item,
                         CirQueueElement cir_queue[],
                         unsigned cirQueue_size,
                         unsigned int *cir_queue_rear)
 {

   /*將cir_queue_rear後移一格*/
   *cir_queue_rear = (*cir_queue_rear + 1) % cirQueue_size;

   /*如果queue已滿就錯誤離開*/
   if(cirQueueIsFull(*cir_queue_rear, cirQueue_size)){
     return -1;
   }

   /*將元素插入queue中*/
       cir_queue[*cir_queue_rear] = item;

   return 0;
 }

/*將元素delete出環狀Queue的函式*/
CirQueueElement cirQueueDel(
  CirQueueElement cir_queue[],
  unsigned cirQueue_size,
  unsigned int cir_queue_rear,
  unsigned int *cir_queue_front, int *result)
{
 /*如果queue為空就錯誤離開*/
 if(cirQueueIsEmpty(cir_queue_rear, *cir_queue_front)){
   /*製造表示queue為空的元素*/
   CirQueueElement dummy;
   /*設定錯誤值*/
   *result = -1;
   /*傳回表示queue為空的元素*/
   return dummy;
 }

 /*將front移至被delete的元素的下一個位置*/
 *cir_queue_front = (*cir_queue_front + 1) % cirQueue_size;

 /*傳回被delete的元素*/
 *result = 0;
 return cir_queue[*cir_queue_front - 1];
}


 /*判斷環狀Queue是否為空函式*/
 short int cirQueueIsEmpty(unsigned int cir_queue_rear, unsigned int cir_queue_front)
 {
   return (cir_queue_rear == cir_queue_front) ? 1 : 0;
 }
 /*判斷環狀Queue是否已滿函式*/
 short int cirQueueIsFull(unsigned cir_queue_rear, unsigned cirQueue_size)
 {
   return (cir_queue_rear == cirQueue_size - 1) ? 1 : 0;
 }
