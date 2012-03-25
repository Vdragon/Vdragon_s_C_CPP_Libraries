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
  Test_program.cpp is part of Solve_equations_algorithms
  Solve_equations_algorithms is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Solve_equations_algorithms is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Solve_equations_algorithms.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/* 我們需要可移植的系統參數*/
#include <cstdlib>

/* 我們需要顯示軟體資訊的函式*/
#include "Show_software_info/Show_software_info.h"

/* 我們需要程式名稱的字串*/
#include "Test_program.h"

/* 我們需要暫停程式運行的函式*/
#include "pauseProgram/Pause_program.h"

/*我們需要複數抽象資料結構*/
#include "Complex_number_abstract_data_structure/Complex.h"

/*我們需要偵錯訊息標籤*/
#include "Messages_templates/zh_TW.h"

/*我們需要cout*/
#include <iostream>

/*我們需要處理EOL的函式*/
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/*我們需要Complex類別的定義*/
#include "Complex_number_abstract_data_structure/Complex.h"

/*我們需要Solve_equations_algorithms*/
#include "Solve_equations_algorithms/Solve_equations_algorithms.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*使用standard namespace*/
using namespace std;

int main()
{

/*用來重新運行程式的label*/
restart_program:
  /*顯示軟體資訊*/
  show_software_info((char *)PROGRAM_NAME);

  /*測試解一元二次方程式演算法*/
  {/*向使用者要求a x^2 + b x + c = 0係數 a, b, c*/
    /*方程式的係數*/
    int a, b, c;

    /*存放解方程式的根的兩個複數*/
    CComplex root1, root2;

    cout << "ax^2 + bx + c = 0" << endl
         << "請輸入上列方程式的係數a, b, c：" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
#ifdef DEBUG
    cout << DEBUG_TAG
         << "a = " << a << ", "
         << "b = " << b << ", "
         << "c = " << c << endl;
#endif
    /*skip EOL*/
    skipEOLsequence(cin);

    /*呼叫解方程式*/
    solveQuadraticEquation(a, b, c, root1, root2);
  }


  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /*成功結束*/
  return EXIT_SUCCESS;
}
