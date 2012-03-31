﻿/*testComplex.cpp
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
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
/*We need complex number class*/
#include "Complex_number_abstract_data_structure/Complex.h"

/*We need pauseProgram function*/
#include "pauseProgram/Pause_program.h"

/*We need console output method*/
#include <iostream>

/*我們需要程式名稱*/
#include "testComplex.h"

/*我們需要showSoftwareInfo() */
#include "Show_software_info/Show_software_info.h"

/*我們需要訊息標籤*/
#include "Messages_templates/zh_TW.h"

/*我們需要處理EOL*/
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/*我們需要預先定義好的回傳狀態碼*/
#include <cstdlib>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
int main()
{

restart_program:
  /*顯示軟體資訊*/
  show_software_info((char *)PROGRAM_NAME);

  //進行複數類別元件測試
  if(!CComplex::unitTest()){
    cout << "元件測試未通過！軟體無法繼續運行。" << endl
         << "請保留程式輸出之所有訊息以提交程式缺陷報告供軟體開發者處理這個問題。" << endl
         << "提交程式缺陷報告網址：https://github.com/Vdragon/NTOU_CPP_Lab_Opensource_Project/issues" << endl;
  }

  /*暫停程式運行*/
  if(pauseProgram() == 1){
    goto restart_program;
  }
/*end_program:*/
  return EXIT_SUCCESS;
}
