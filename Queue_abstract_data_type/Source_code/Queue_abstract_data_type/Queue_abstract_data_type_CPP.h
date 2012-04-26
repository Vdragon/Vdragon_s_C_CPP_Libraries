/* Queue_abstract_data_type_CPP.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef QUEUE_ABSTRACT_DATA_TYPE_CPP_H_
  #define QUEUE_ABSTRACT_DATA_TYPE_CPP_H_

  /*模組標籤*/
  #define QUEUE_UNITTEST_TAG "【隊列(Queue)元件測試模組】"
  #define QUEUE_ENQUE_TAG "【Queue::enque()】"

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
    /* 對Queue進行初始化
     * 回傳數值 | Return value
     *   true - 初始化成功
     *   false - 該Queue已經被初始化過了*/
    void initialize();
    /* 把傳入的QueueElement排到 Queue 的最後面
     * 回傳數值 | Return value
     *   true - enque操作成功
     *   false - enque操作失敗（記憶體配置發生問題）*/
    bool enque(queueElement);
    /* 把 Queue 裡面排在最前面的QueueElement移出, 函式參數是一個參考變數, 移出的數字就放在這參
     * 數裡面, 並且回傳 true; 如果 Queue 裡面沒有任何資料, 就回傳 false*/
    bool deque(queueElement &);
    /* 隊列(Queue)元件測試模組
     * 回傳數值
     *   bool - 測試成功與否*/
    static bool unitTest();
  private:
    QueueElement *m_head;
    QueueElement *m_tail;
  };
  

#endif /* QUEUE_ABSTRACT_DATA_TYPE_CPP_H_ */
