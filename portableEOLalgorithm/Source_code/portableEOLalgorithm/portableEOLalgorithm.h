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

  /*跳過stream中的換行字元序列的函式*/
  short skipEOLsequence(istream& file_stream);

  /*可以處理所有平台換行序列的getline函式
   * 原作者為Stack Overflow上的Nimbo跟user763305
   * http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
   * */
  std::istream& portableGetline(std::istream& is, std::string& t);
#endif /* SKIP_EOL_ALGORITHM_H_ */
