/*Test_program.c
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
  Test_program.c is part of Show_software_info
  Show_software_info is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Show_software_info is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Show_software_info.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/* 我們需要顯示軟體資訊的library*/
#include "showSoftwareInfo/showSoftwareInfo.h"

/* 我們需要暫停程式*/
#include "pauseProgram/Pause_program.h"

/* 我們需要EXIT_SUCCESS */
#include <stdlib.h>

/*我們需要程式名稱*/
#include "Test_program.h"
/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
int main(void)
{

/*用來重新運行程式的label*/
restart_program:
  /*呼叫Show software info*/
  showSoftwareInfo(PROGRAM_NAME);
  showSoftwareInfo("test_string");
  /*呼叫暫停運行函式(放在main函式中)*/
  if(pauseProgram() == 1){
    goto restart_program;
  }
  /*exit successful*/
  return EXIT_SUCCESS;
}
