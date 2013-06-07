/*Test_program.cpp
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
著作權宣告：
  Copyright 2012 林博仁(Henry Lin)
智慧財產授權條款：
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/

/*////////程式所include的標頭檔(Included Headers)////////*/
/*include our library*/
#include "portableEOLalgorithm/CPP/portableEOLalgorithm.hpp"

/*include list files */
#include "List_directory_files/listDirectoryFiles.h"

/* include constants*/
#include "Test_program.h"

/*我們需要輸入／輸出資料的method*/
#include <iostream>

/*我們需要打開檔案的class*/
#include <fstream>

/* We need a string that don't overflow ! */
#include <string>

/*錯誤訊息header*/
#include "Messages_templates/zh_TW.h"

/*我們需要暫停程式*/
#include "pauseProgram/Pause_program.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/* 直接使用標準命名空間 */
	using namespace std;

int main()
{
  int buffer = 0;
  std::string filename;
  ifstream input_file;

restart_program:

/*open file*/
  listDirectoryFiles();
  cout << "當前console作用中的目錄如上所示。" << endl
       << "請輸入要用來測試的檔案路徑：";
  cin >> filename;
  switch(skipEOLsequence(cin)){
  case 1:
    cout << "[cin]偵測到並丟棄[LF]"<< endl;
    break;
  case -1:
  default:
    cout << "[cin]沒有偵測到換行字元序列" << endl;
    break;
  }
  printf("%s", "---------------------");

  input_file.open(filename.c_str() , input_file.in);
  if(input_file.is_open()){
    /*read file*/
    while(true){
      input_file >> buffer;
      if(input_file.eof()){
        cout << "[END OF FILE]" << endl;
        break;
      }else if(input_file.fail()){
        cout << "讀取到非預期的資料，跳過繼續。" << endl;
        input_file.clear();
        break;
      }
      cout << buffer;
      skipEOLsequence(input_file);
    }
    /*close file*/
    	input_file.close();

  }else{
		cout << ERROR_FILE_OPEN_FAIL;
  }

  /* pause */
  if(pauseProgram() == 1){
      goto restart_program;
  }

  /*exit*/
  return 0;
  }
