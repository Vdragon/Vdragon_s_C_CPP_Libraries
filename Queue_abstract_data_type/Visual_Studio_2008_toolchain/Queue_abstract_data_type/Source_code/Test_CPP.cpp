/*Test.cpp
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
  Test.cpp is part of 隊列(Queue)抽像資料類型
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
/* 標準C++函式庫*/
#include <cstdlib>
#include <cassert>

/* Vdragon的C、C++函式庫收集*/
#include "Show_software_info/Show_software_info.h"
#include "pauseProgram/Pause_program.h"

/*測試的程式*/
#include "Queue_abstract_data_type/Queue_abstract_data_type_CPP.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
int main()
{
restart_program:
  show_software_info("隊列(Queue)抽象資料類型測試程式");

  /*元件測試*/
  assert(Queue::unitTest());

  if(pauseProgram() == 1){
    goto restart_program;

  }
  return EXIT_SUCCESS;
}
