/*Queue_abstract_data_type_CPP.cpp
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  Queue_abstract_data_type_CPP.cpp is part of 隊列(Queue)抽像資料類型
  隊列(Queue)抽像資料類型 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  隊列(Queue)抽像資料類型 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with 隊列(Queue)抽像資料類型.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*Queue ADT*/
#include "./Queue_abstract_data_type_CPP.h"

/***Standard C++函式庫***/
/*NULL定義*/
#include <cstddef>
/**/
#include <iostream>
/**/
#include <cassert>
using namespace std;

/***Ｖ字龍的C++函式庫蒐集*/
/**/
#include "../Messages_templates/zh_TW.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
Queue::Queue()
{
  initialize();
}
Queue::~Queue()
{
  reinitialize();
  return;
}

void Queue::initialize()
{
  m_head = NULL;
  m_tail = NULL;
  m_length = 0;
  return;
}

void Queue::reinitialize()
{
  if(m_head == NULL){
    return;
  }
  /* 消滅掉所有的元素 */
  QueueElement *del, *next;
  for(del = m_head; del != m_tail; ){
    next = del->next;
    delete del;
    del = next;
  }
  delete del;
  m_head = m_tail = NULL;
  m_length = 0;
  return;
}
bool Queue::unitTest()
{
  /* 測試Queue::initialize()*/ {
    Queue target;

    assert(target.m_head == NULL && target.m_tail == NULL);
  }

  /* 測試Queue::enque()、Queue::deque()、Queue::getLength() */{
     Queue theQueue;
     QueueElement insert, dequed;

     for (int i = 1; i <= 100; ++i) {
       insert.data = i;
       theQueue.enque(insert);
     }

     assert(100 == theQueue.getLength());

     for (int i = 1; i <= 100; ++i) {
       theQueue.deque(dequed);
       assert(dequed.data == i);
     }
     assert(theQueue.getLength() == 0);
     theQueue.reinitialize();
   }

  /*元件測試成功*/
  cout << QUEUE_UNITTEST_TAG << "元件測試全部成功！" << endl;
  return true;
}

bool Queue::enque(QueueElement enque_item)
{
  /*配置一個新的元素*/
  QueueElement *newItem = new QueueElement;
  if(newItem == NULL){
    cerr << QUEUE_ENQUE_TAG
         << ERROR_MEMORY_ALLOCATION_FAIL << endl;
    return false;
  }
  *newItem = enque_item;
  newItem->next = NULL;

  /* 情形1—Queue是空的 */
  if(m_tail == NULL){
    m_tail = m_head = newItem;
  }/* 情形2—Queue不是空的 */else{
    m_tail->next = newItem;
    m_tail = newItem;
  }

  /* enque操作成功 */
  ++m_length;
  return true;
}

bool Queue::deque(QueueElement& dequed)
{
  /*情形A - 如果 Queue 裡沒有任何元素就無法進行deque操作*/
  if(m_tail == NULL){
    cerr << QUEUE_DEQUE_TAG
         << ERROR_QUEUE_EMPTY << endl;
    return false;
  }/*情形B - 如果 Queue中有元素，就進行deque操作 */else{
    dequed = *m_head;
    QueueElement *new_head = m_head->next;
    delete m_head;

    /*情形B.1 - 如果Queue中只有一個元素就連tail也要更動*/
    if(new_head == NULL){
      m_head = m_tail = NULL;
    }/*情形B.2 - 如果Queue中不只有一個元素就只需更動head*/else{
      m_head = new_head;
    }
    --m_length;
    return true;
  }
}

unsigned Queue::getLength(){
  return m_length;
}
