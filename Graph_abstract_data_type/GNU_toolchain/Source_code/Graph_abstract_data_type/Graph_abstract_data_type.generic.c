/*Graph_abstract_data_type.generic.c
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
  Graph_abstract_data_type.generic.c is part of Graph抽象資料類型
  Graph抽象資料類型 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Graph抽象資料類型 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Graph抽象資料類型.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*this*/
#include "Graph_abstract_data_type.generic.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
  /*初始化邊的函式*/
  void initEdge(Edge *target)
  {
    (*target).getUref = getU;
    (*target).getVref = getV;
    (*target).setEdgeRef = setEdge;
    /*done*/
	  return;
  }

  /*設定邊的屬性的函式*/
  void setEdge(Edge *edge, Vertex u, Vertex v, int cost)
  {
    (*edge).u = u;
    (*edge).v = v;
    (*edge).cost = cost;

    return;
  }

  /**/
  Vertex getU(Edge edge)
  {
    return edge.u;
  }
  Vertex getV(Edge edge)
  {
    return edge.v;
  }
