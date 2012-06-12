/* Test_program.cpp
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
  Test_program.cpp is part of 亂數姓名產生器
  亂數姓名產生器 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  亂數姓名產生器 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with 亂數姓名產生器.  If not, see <http://www.gnu.org/licenses/>.
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
#include "Random_name_generator/Random_name_generator.h"

/* for string printing */
#include <iostream>
using namespace std;

/* for random generator */
#include <stdlib.h>
#include <time.h>

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
int main()
{
  char name[11];

  srand(time(NULL));
  for(int i = 0; i < 5; ++i){
    generateRandomChineseName(name);
    cout << name << endl;
  }

  return 0;
}
