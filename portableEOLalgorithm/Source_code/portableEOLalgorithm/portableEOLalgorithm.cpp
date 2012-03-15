/*Skip_EOL_algorithm.cpp
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
/*we need io functions*/
#include <fstream>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*我們需要std namespace*/
using namespace std;

/*跳過stream中的換行字元序列的函式*/
short skipEOLsequence(istream& file_stream)
{
  /*用來測試的字元*/
  char test;

  /*guess first character, may be '\r'(MS-DOS later or MAC) or '\n'(Unix)*/
  test = file_stream.peek();

  switch(test){
  case '\n':
    /*if is Unix...eat it and done*/
    file_stream.ignore(1);
    /*return Unix*/
    return 1;

  case '\r':
    /*maybe MS-DOS or Mac...ignore it and peek next*/
    file_stream.ignore(1);
    test = file_stream.peek();
    if(test == '\n'){
      file_stream.ignore(1);
      /*return Windows*/
      return 2;
    }
    /*return Mac*/
    return 3;
  default:
    /*shouldn't be EOL else...*/
    return -1;
  }

  /*不應該跑到這邊來，當作錯誤吧！*/
  return -1;
}

/*portable getline function*/
std::istream& portableGetline(std::istream& is, std::string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
        case '\r':
            c = sb->sgetc();
            if(c == '\n')
                sb->sbumpc();
            return is;
        case '\n':
        case EOF:
            return is;
        default:
            t += (char)c;
        }
    }
}
