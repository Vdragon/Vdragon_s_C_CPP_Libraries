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

	/* we need iostream to output debug message*/
		#include <iostream>

	/*我們需要專案的設定值*/
		#include "../../Project_specific_configurations/Debug.h"

	/*我們需要一些defined訊息*/
		#include "../../Messages_templates/zh_TW.h"

	/*我們需要標示當前模組的字串*/
		#include "portableEOLalgorithm.hpp"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/* 我們需要std namespace */
	using namespace std;

/* 跳過stream中的換行字元序列的函式 */
	short skipEOLsequence(istream& file_stream){
		char check;

		/* guess first character, may be '\r'(MS-DOS later or MAC) or '\n'(Unix)*/
			check = file_stream.peek();

		/* if is Unix...eat it and reply Unix */
			if(check == '\n'){
				file_stream.ignore(1);
#ifndef NDEBUG
				cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
						 << "吃掉了[LF]" << endl;
#endif
				return 1;
			}else if(check == '\r'){
				/* maybe MS-DOS or old Mac...ignore it and peek next to see which is which */
					file_stream.ignore(1);
#ifndef NDEBUG
					cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
							 << "吃掉了[CR]";
#endif
					check = file_stream.peek();
					if(check == '\n'){
						/* It's MSDOS or Windows! */
							file_stream.ignore(1);
#ifndef NDEBUG
							cout << "[LF]" << endl;
#endif
							return 2;
					}else{
						/* It's old Mac!  Leave the peeked non-EOL alone and return */
							cout << endl;
							return 3;
					}
			}else{
				/* not a known EOL character sequence, good bye! */
#ifndef NDEBUG
					cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
							 << "吃列結尾以外的東西會拉肚子的……" << endl;
#endif
					return -1;
			}
	}

/* portable getline function */
	std::istream& portableGetline(std::istream& is, std::string& target){
		target.clear();

		// The characters in the stream are read one-by-one using a std::streambuf.
		// That is faster than reading theim one-by-one using the std::istream.
		// Code that uses streambuf this way must be guarded by a sentry object.
		// The sentry object performs various tasks,
		// such as thread synchronization and updating the stream state.

		std::istream::sentry se(is, true);
		std::streambuf* sb = is.rdbuf();

		while(true) {
			int c = sb->sbumpc();

			switch (c) {
			case '\r':
				c = sb->sgetc();
				if(c == '\n')
					sb->sbumpc();
				return is;
				break;
			case '\n': case EOF:
				return is;
				break;
			default:
				target += (char)c;
				break;
			}
		}

		// A workaround to prevent G++ from complaining
		// Warning - No return, in function returning non-void
		// 實際上前方的 while 迴圈最終一定會回傳，所以不需要這一行
			return is;
	}

void dumpInvisibleContent(string& input){
  /*counter*/
  unsigned i;
  char buffer;

  /*從第一個到最後一個字串字元*/
  for(i = 0; i < input.length(); ++i){
    buffer = input[i];
    switch(buffer){
    case '\n':
      cout << "[LF]";
      break;
    case '\r':
      cout << "[CR]";
      break;
    default:
      cout << buffer;
      break;
    }
  }
  /*完成*/
  return;
}
