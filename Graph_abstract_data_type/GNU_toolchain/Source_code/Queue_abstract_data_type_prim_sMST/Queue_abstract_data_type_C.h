/*****Queue資料結構*****/
 /*Queue元素資料結構定義*/
 typedef struct queueElementPrimMST{
   unsigned min_weight;
 }QueueElementPrimMST;


 /*指向Queue front位置跟rear位置的指標或註標(subscript)
 int queue_rear = -1;
 int queue_front = -1;*/

 /*判斷Queue是否為空函式的function prototype*/
 short int queueIsEmpty(int queue_rear, int queue_front);

 /*判斷Queue是否已滿函式的function prototype*/
 short int queueIsFull(int queue_rear, unsigned queue_size);

 /*將元素add至queue的函式的function prototype*/
 short int queueAdd(QueueElementPrimMST item, QueueElementPrimMST queue[], unsigned queue_size, int *queue_rear);

 /*將元素delete出queue的函式的function prototype*/
 QueueElementPrimMST queueDel(QueueElementPrimMST queue[], int *queue_rear, int queue_front, int *result);

 /*****環狀Queue資料結構*****/
 /*環狀Queue元素資料結構*/
 typedef struct cirQueueElement{
   /*資料members*/
   int data;
 }CirQueueElement;

 /*宣告一個環狀Queue
 CirQueueElementPrimMST cir_queue[MAX_CIR_QUEUE_SIZE];*/

 /*指向環狀Queue front位置跟rear位置的指標或註標(subscript)
 unsigned int cir_queue_rear = 0;
 unsigned int cir_queue_front = 0;*/

 /*判斷環狀Queue是否為空函式的function prototype*/
 short int cirQueueIsEmpty(unsigned int cir_queue_rear, unsigned int cir_queue_front);

 /*判斷環狀Queue是否已滿函式的function prototype*/
 short int cirQueueIsFull(unsigned cir_queue_rear, unsigned cirQueue_size);

 /*將元素add至環狀Queue的函式的function prototype*/
 short int cirQueueAdd(CirQueueElement item,
                         CirQueueElement cir_queue[],
                         unsigned cirQueue_size,
                         unsigned int *cir_queue_rear);

 /*將元素delete出環狀Queue的函式的function prototype
  *  回傳值
  *    CirQueueElementPrimMST - delete出來的Queue元素
  *    result - 表示delete操作的結果
  *       -1 - 試圖delete一個空的Queue
  *       0 - 成功*/
 CirQueueElement cirQueueDel(CirQueueElement cir_queue[],
                               unsigned cirQueue_size,
                               unsigned int cir_queue_rear,
                               unsigned int *cir_queue_front, int *result);


