  /* 標籤 */
  #define QUEUE_ADT_TAG "【Queue抽象資料類型】"

  /* 訊息 */
  #define ERROR_QUEUE_DELETE_EMPTY "無法delete空的隊列(queue)！\n"
  #define ERROR_QUEUE_ADD_FULL "無法新增新元素進滿的隊列(queue)！\n"

  /*Queue元素資料結構定義*/
  typedef struct queueElement{
   int data;
  }QueueElement;

  /* 隊列class的定義 */
  typedef struct queue{
    /* ====屬性==== */
    /* 隊列(queue)的陣列 */
    QueueElement *queue;

    /* 隊列(queue)所在陣列的總大小 */
    unsigned size;

    /* 指向隊列(queue)的尾端的指標 */
    QueueElement *rear;

    /* ====介面==== */
    /* ==public member functions== */
    /* 初始化並建立Queue的函式
     * 參數
     * 　*target
     * 　　尚未被初始化的Queue物件
     * 　queue_size
     * 　　Queue的大小（至少1）
     * 回傳數值
     * 　0
     * 　　初始化成功
     * 　-1
     * 　　初始化失敗，可用記憶體不足*/
    short (*CreateRef)(struct queue *target, unsigned queue_size);
    /* 摧毀Queue的函式 */
    void (*DestroyRef)(struct queue *target);
    /* 取得隊列(queue)目前長度的函式
     * 參數
     * 　*target
     * 　　隊列(queue)
     * 回傳數值
     * 　隊列(queue)的長度*/
    unsigned (*LengthRef)(struct queue *target);
    /* 判斷Queue是否為空函式 */
    short (*IsEmptyRef)(struct queue *target);
    /* 判斷Queue是否已滿函式 */
    short (*IsFullRef)(struct queue *target);
    /* 將元素add至queue的函式 */
    short (*AddRef)(struct queue *target, QueueElement item);
    /* 將元素delete出queue的函式
     * 參數
     * 　*target
     * 　　隊列(queue)
     * 回傳數值
     * 　delete出來的隊列(queue)元素
     * 　*result
     * 　　delete結果
     * 　　　-1
     * 　　　　delete失敗（隊列(queue)是空的）*/
    QueueElement (*DeleteRef)(struct queue *target, short *result);
    /* 進行元件測試的函式
     * 回傳數值
     * 　0
     * 　　測試完全通過
     * 　-1
     * 　　測試失敗 */
    short (*UnitTestRef)(void);
    /* ==private member functions== */
  }Queue;
  short queueCreate(Queue *target, unsigned queue_size);
  void queueDestroy(Queue *target);
  unsigned queueLength(Queue *target);
  short queueIsEmpty(Queue *target);
  short queueIsFull(Queue *target);
  short queueAdd(Queue *target, QueueElement item);
  QueueElement queueDelete(Queue *target, short *result);
  short queueUnitTest(void);

 /*****環狀Queue資料結構*****/
 /*環狀Queue元素資料結構*/
 typedef struct cirQueueElement{
   /*資料members*/
   int data;
 }CirQueueElement;

 /*宣告一個環狀Queue
 CirQueueElement cir_queue[MAX_CIR_QUEUE_SIZE];*/

 /*指向環狀Queue front位置跟rear位置的指標或註標(subscript)
 unsigned int cir_queue_rear = 0;
 unsigned int cir_queue_front = 0;*/

 /*判斷環狀Queue是否為空函式的function prototype*/
 short cirQueueIsEmpty(unsigned int cir_queue_rear, unsigned int cir_queue_front);

 /*判斷環狀Queue是否已滿函式的function prototype*/
 short cirQueueIsFull(unsigned cir_queue_rear, unsigned cirQueue_size);

 /*將元素add至環狀Queue的函式的function prototype*/
 short cirQueueAdd(CirQueueElement item,
                         CirQueueElement cir_queue[],
                         unsigned cirQueue_size,
                         unsigned int *cir_queue_rear);

 /*將元素delete出環狀Queue的函式的function prototype
  *  回傳值
  *    CirQueueElement - delete出來的Queue元素
  *    result - 表示delete操作的結果
  *       -1 - 試圖delete一個空的Queue
  *       0 - 成功*/
 CirQueueElement cirQueueDel(CirQueueElement cir_queue[],
                               unsigned cirQueue_size,
                               unsigned int cir_queue_rear,
                               unsigned int *cir_queue_front, int *result);


