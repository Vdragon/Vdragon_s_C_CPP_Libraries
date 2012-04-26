/* Queue_abstract_data_type_CPP.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef QUEUE_ABSTRACT_DATA_TYPE_CPP_H_
  #define QUEUE_ABSTRACT_DATA_TYPE_CPP_H_

  typedef struct queueElement{
    /*資料欄位*/
    struct queueElement *next;
  }QueueElement;

  class queue{
  public:
    queue();
    ~queue();
    void initialize();
    void enque(int);
    bool deque(int &);
  private:
    QueueElement *m_head;
    QueueElement *m_tail;
  };
  

#endif /* QUEUE_ABSTRACT_DATA_TYPE_CPP_H_ */
