/*
 * Skip_EOL_algorithm.h
 *
 *  Created on: 2012/3/15
 *      Author: vdragon
 */
/*we need io functions*/
#include <fstream>

#ifndef SKIP_EOL_ALGORITHM_H_
  #define SKIP_EOL_ALGORITHM_H_
  using namespace std;

  /* 標示目前執行位置的標籤*/
  #define SKIP_EOL_SEQUENCE_TAG "【跳過EOL序列模組】"

  /* 跳過 stream 中的列結尾字元序列的函式
   * 參數：
   *   input stream
   * 回傳值：
   *   1  跳過 UNIX 列結尾字元序列("\n")
   *   2  跳過 DOS/WINDOWS 列結尾字元序列("\r\n")
   *   3  跳過舊版本 MAC 列結尾字元序列("\r")
   *   -1 並非已知的列結尾字元序列，不跳過任何字元 */
  short skipEOLsequence(istream& file_stream);

  /*可以處理所有平台換行序列的getline函式
   * 感謝Stack Overflow上的Nimbo跟user763305
   * http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
   * */
  std::istream& portableGetline(std::istream& is, std::string& t);

  /*印出stream中所有內容，突顯出不可見字元的函式
   * 引數：input - 輸入的字串*/
  void dumpInvisibleContent(string& input);


#endif /* SKIP_EOL_ALGORITHM_H_ */
