/*Test_program.cpp
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
  Test_program.cpp is part of Operate_resources_helper
  Operate_resources_helper is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Operate_resources_helper is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Operate_resources_helper.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/**/
#include <iostream>
/**/
#include <cstdlib>
/**/
#include <fstream>

/**/
#include "pauseProgram/Pause_program.h"
/**/
#include "Operate_resources_helper/Operate_file_CPP.h"
/**/
#include "Messages_templates/zh_TW.h"

using namespace std;
/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

int main()
{
/*用來重新運行程式的label*/
restart_program:

  string filename;

  /*stream*/
  ifstream input_file;

  /*buffer*/
  char buffer[30];
  //char bufferChar;

  /*open file
   * 如何於讀取資料時正確處理eof bit ： http://www.velocityreviews.com/forums/t716773-what-does-fstream-getline-return-after-setting-fail-bit.html
   * */
  askFile(filename);
  if(openFile(filename, "r", input_file) == 0){
    while(input_file.getline(buffer, 30)){
      cout << buffer << endl;
    }
    if(!input_file.eof()){
      cerr << ERROR_TAG
           << "getline()發生錯誤！" << endl;
    }

    closeFile(filename, input_file);

  }
  else{
    cerr << ERROR_TAG
         << "檔案讀取失敗！" << endl;
  }


  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /*done*/
  return EXIT_SUCCESS;
}
