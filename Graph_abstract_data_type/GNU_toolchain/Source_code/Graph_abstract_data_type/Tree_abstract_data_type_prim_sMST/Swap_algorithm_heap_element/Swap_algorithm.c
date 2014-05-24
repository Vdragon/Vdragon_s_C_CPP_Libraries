/* swap演算法
 * -----------------------------------
 * 程式框架版本(program framework version)：A
 * 程式框架修訂號(program framework revision number)：201109251624
 * 更新紀錄(changelog)：
 *  Changelog is now stored on github
 * 已知問題(known issues)：
 *  Known issues is now stored on github
 * 待辦事項(todo)：
 *  Todo is now stored on github
 * 智慧財產授權條款：
 *//* Copyright (C) 2012 林博仁(Henry Lin)
   *
   * This library is free software; you can redistribute it and/or
   * modify it under the terms of the GNU Lesser General Public
   * License as published by the Free Software Foundation version 2.1
   * of the License.
   *
   * This library is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   * Lesser General Public License for more details.
   *
   * You should have received a copy of the GNU Lesser General Public
   * License along with this library; if not, write to the Free Software
   * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
   */
/*||||| Forward declarations |||||*/

/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
#include "../Tree_abstract_data_type_C.h"

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/* swapHeapElement function */
void swapHeapElement(HeapElement *a, HeapElement *b)
{
  HeapElement temp;

  /* ====swap==== */
  /*backup a*/
  temp = *a;
  /*assign a with *b*/
  *a = *b;
  /*assign *b with backuped a*/
  *b = temp;
  return;
}
