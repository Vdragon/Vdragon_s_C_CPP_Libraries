/* Queue_abstract_data_type_CPP.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef QUEUE_ABSTRACT_DATA_TYPE_CPP_H_
  #define QUEUE_ABSTRACT_DATA_TYPE_CPP_H_

  /*模組標籤*/
  #define QUEUE_UNITTEST_TAG "【隊列(Queue)元件測試模組】"
  #define QUEUE_ENQUE_TAG "【Queue::enque()】"
  #define QUEUE_DEQUE_TAG "【Queue::deque()】"

  /*訊息*/
  #define ERROR_QUEUE_EMPTY "隊列(Queue)已經是是空的了。"

  typedef struct queueElement{
    /*資料欄位*/
    int data;

    /*指向下一個元素的指標變數*/
    struct queueElement *next;
  }QueueElement;

  class Queue{
  public:
    Queue();
    ~Queue();

    /* 把傳入的QueueElement排到 Queue 的最後面
     * 回傳數值 | Return value
     *   true - enque操作成功
     *   false - enque操作失敗（記憶體配置發生問題）*/
    /*清除Queue裡面所有的元素*/
    void reinitialize();
    bool enque(queueElement);
    /* 把 Queue 裡面排在最前面的QueueElement移出, 函式參數是一個參考變數, 移出的數字就放在這參
     * 數里面, 並且回傳 true; 如果 Queue 裡面沒有任何資料, 就回傳 false*/
    bool deque(queueElement &);

    /*取得隊列長度的函式*/
    unsigned getLength();

    /* 隊列(Queue)元件測試模組
     * 回傳數值
     *   bool - 測試成功與否*/
    static bool unitTest();
  private:
    QueueElement *m_head;
    QueueElement *m_tail;

    /* 隊列內元素的數量 */
    unsigned m_length;

    /* 對Queue進行初始化 */
    void initialize();
  };
  

#endif /* QUEUE_ABSTRACT_DATA_TYPE_CPP_H_ */
