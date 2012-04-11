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
  Test_program.c is part of portableGetCh
  portableGetCh is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  portableGetCh is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with portableGetCh.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要portableGetCh()*/
#include "portableGetCh/portableGetCh.h"

/*我們需要跨平台的狀態碼*/
#include <stdlib.h>

/*我們需要顯示軟體訊息*/
#include "Show_software_info/Show_software_info.h"

/*我們需要暫停程式*/
#include "pauseProgram/Pause_program.h"

/*我們需要程式名稱*/
#include "Test_program.h"

/*我們需要stdout函式*/
#include <stdio.h>

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

  show_software_info(PROGRAM_NAME);

  /*counter*/
  unsigned keystroke;

  for(keystroke = 0; keystroke < 10; ++keystroke){
    printf("You pressed '%c'\n", portableGetCh());

  }

  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /*done*/
  return EXIT_SUCCESS;
}
