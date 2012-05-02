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

/*////////常數與巨集(Constants & Macros)////////*/
 /*判斷Queue是否為空函式*/
 short int queueIsEmpty(int queue_rear, int queue_front)
 {
   return (queue_rear == queue_front) ? 1 : 0;
 }

 /*判斷Queue是否已滿函式*/
 short int queueIsFull(int queue_rear, unsigned queue_size)
 {
   return (queue_rear == queue_size - 1) ? 1 : 0;
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
/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式和函式雛型(Function & Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
 /*將元素add至queue的函式*/
 short int queueAdd(QueueElement item, QueueElement queue[], unsigned queue_size, int *queue_rear)
 {

   /*如果queue已滿就錯誤離開*/
   if(queueIsFull(*queue_rear, queue_size)){
     return -1;
   }
   /*將元素插入queue中*/
   queue[++*queue_rear] = item;

   return 0;
 }

 /*將元素delete出queue的函式*/
 QueueElement queueDel(QueueElement queue[], int *queue_rear, int queue_front, int *result)
 {

   /*如果queue已滿就錯誤離開*/
   if(queueIsEmpty(*queue_rear, queue_front)){
     QueueElement dummy;
     *result = -1;
     return dummy;
   }

   /*傳回rear位置的元素並遞減rear*/
   *result = 0;
   return queue[--*queue_rear];
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
 CirQueueElement cirQueueDel(CirQueueElement cir_queue[],
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
