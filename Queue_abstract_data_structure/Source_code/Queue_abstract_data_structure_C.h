 //Queue的資料結構
 //定義Queue最大容量大小
 #define MAX_QUEUE_SIZE 100

 //Queue元素資料結構
 typedef struct queueElement{
   //資料members

 }QueueElement;
 ////Queue元素資料結構

 //宣告一個Queue
 QueueElement queue[MAX_QUEUE_SIZE];

 //指向Queue front位置跟rear位置的指標或註標(subscript)
 int queue_rear = -1;
 int queue_front = -1;

 //判斷Queue是否為空函式的function prototype
 inline short int queueIsEmpty(int queue_rear, int queue_front);

 //判斷Queue是否為空函式
 //版本：0.00(0)
 inline short int queueIsEmpty(int queue_rear, int queue_front)
 {
   return (queue_rear == queue_front) ? 1 : 0;
 }

 //判斷Queue是否已滿函式的function prototype
 inline short int queueIsFull(int queue_rear);

 //判斷Queue是否已滿函式
 //版本：0.00(0)
 inline short int queueIsFull(int queue_rear)
 {
   return (queue_rear == MAX_QUEUE_SIZE - 1) ? 1 : 0;
 }

 //將元素add至queue的函式的function prototype
 short int queueAdd(QueueElement item, QueueElement queue[], int *queue_rear);

 //將元素add至queue的函式
 //版本：0.00(0)
 short int queueAdd(QueueElement item, QueueElement queue[], int *queue_rear)
 {
   //宣告與定義(Declaration & Definition)
       //－－－－－－－－－－－－－－－－－－－－－
           //如果queue已滿就錯誤離開
               if(queueIsFull(*queue_rear)){
                 return -1;
               }
                   //將元素插入queue中
                       queue[++*queue_rear] = item;

                       //－－－－－－－－－－－－－－－－－－－－－
                       //傳回0
                       return 0;
 }

 //將元素delete出queue的函式的function prototype
 QueueElement queueDel(QueueElement stack[], int *queue_rear);

 //將元素delete出queue的函式
 //版本：0.00(0)
 QueueElement queueDel(QueueElement stack[], int *queue_rear)
 {
   //宣告與定義(Declaration & Definition)
       //－－－－－－－－－－－－－－－－－－－－－
           //如果queue已滿就錯誤離開
               if(queueIsEmpty(*queue_rear)){
                 //製造表示函式錯誤的元素
                         QueueElement errorElement;
                         //傳回表示函式錯誤的元素
                         return errorElement;
               }
                   //－－－－－－－－－－－－－－－－－－－－－
                       //傳回rear位置的元素並遞減rear
                           return queue[--*queue_rear];
 }

 //環狀Queue資料結構
 //定義環狀Queue最大容量大小
 #define MAX_CIR_QUEUE_SIZE 100

 //環狀Queue元素資料結構
 typedef struct cirQueueElement{
   //資料members

 }CirQueueElement;
 ////環狀Queue元素資料結構

 //宣告一個環狀Queue
 CirQueueElement cir_queue[MAX_CIR_QUEUE_SIZE];

 //指向環狀Queue front位置跟rear位置的指標或註標(subscript)
 unsigned int cir_queue_rear = 0;
 unsigned int cir_queue_front = 0;

 //判斷環狀Queue是否為空函式的function prototype
 inline short int cirQueueIsEmpty(unsigned int cir_queue_rear, unsigned int cir_queue_front);

 //判斷環狀Queue是否為空函式
 //版本：0.00(0)
 inline short int cirQueueIsEmpty(unsigned int cir_queue_rear, unsigned int cir_queue_front)
 {
   return (cir_queue_rear == cir_queue_front) ? 1 : 0;
 }

 //判斷環狀Queue是否已滿函式的function prototype
 inline short int cirQueueIsFull(unsigned int cir_queue_rear);

 //判斷環狀Queue是否已滿函式
 //版本：0.00(0)
 inline short int cirQueueIsFull(unsigned int cir_queue_rear)
 {
   return (cir_queue_rear == MAX_CIR_QUEUE_SIZE - 1) ? 1 : 0;
 }

 //將元素add至環狀Queue的函式的function prototype
 short int cirQueueAdd(CirQueueElement item, CirQueueElement cir_queue[],
                       unsigned int *cir_queue_rear);

 //將元素add至環狀Queue的函式
 //版本：0.00(0)
 short int cirQueueAdd(CirQueueElement item, CirQueueElement cir_queue[],
                       unsigned int *cir_queue_rear)
 {
   //宣告與定義(Declaration & Definition)
       //－－－－－－－－－－－－－－－－－－－－－
           //將cir_queue_rear後移一格
               *cir_queue_rear = (*cir_queue_rear + 1) % MAX_CIR_QUEUE_SIZE;

               //如果queue已滿就錯誤離開
               if(cirQueueIsFull(*cir_queue_rear)){
                 return -1;
               }

                   //將元素插入queue中
                       cir_queue[*cir_queue_rear] = item;

                       //－－－－－－－－－－－－－－－－－－－－－
                       //傳回0
                       return 0;
 }

 //將元素delete出環狀Queue的函式的function prototype
 CirQueueElement cirQueueDel(CirQueueElement cir_queue[], unsigned int cir_queue_rear,
                             unsigned int *cir_queue_front);

 //將元素delete出環狀Queue的函式
 //版本：0.00(0)
 CirQueueElement cirQueueDel(CirQueueElement cir_queue[], unsigned int cir_queue_rear,
                             unsigned int *cir_queue_front);
 {
   //宣告與定義(Declaration & Definition)
       //－－－－－－－－－－－－－－－－－－－－－
           //如果queue為空就錯誤離開
               if(cirQueueIsEmpty(cir_queue_rear, *cir_queue_front)){
                 //製造表示queue為空的元素
                         CirQueueElement errorElement;
                         //設定錯誤值

                         //傳回表示queue為空的元素
                         return errorElement;
               }

                   //將front移至被delete的元素的下一個位置
                       *cir_queue_front = (*cir_queue_front + 1) % MAX_CIR_QUEUE_SIZE;

                       //－－－－－－－－－－－－－－－－－－－－－
                       //傳回被delete的元素
                       return cir_queue[*cir_queue_front - 1];
 }

