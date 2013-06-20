/* include guard：避免同一個 header 檔案被 include 第二次 */
	#ifndef VCCL_FILE_SYSTEM
		/*程式名稱
			Program name */
			#define VCCL_FILE_SYSTEM "tw.org.vsdg.lib.vccl.file_system"
			#define VCCL_FILE_SYSTEM_READABLE "File system related library"
		/*更新紀錄
			Changelog
				Changelog is now stored on GitHub(http://www.github.com)
			已知問題
			Known issues
				Known issues is now stored on GitHub(http://www.github.com)
			待辦事項
			Todos
				Todo is now stored on GitHub(http://www.github.com)
			著作權宣告
			Copyright declaration
				Copyright RELEASE_YEAR © 未定義作者<undefined@mail.address>
			智慧財產授權條款
			Intellectual property license
				File system related library is part of Vdragons_C_CPP_Libraries_Collection
				Vdragons_C_CPP_Libraries_Collection is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
				
				Vdragons_C_CPP_Libraries_Collection is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
				
				You should have received a copy of the GNU Lesser General Public License along with Vdragons_C_CPP_Libraries_Collection.  If not, see <http://www.gnu.org/licenses/>.
			本程式的框架基於「C/C++ program templates」專案
			This program's frame is based on "C/C++ program templates" project
				https://github.com/Vdragon/C_CPP_program_templates
			建議編輯器設定
			Recommended editor settings
				Indentation by tab character
				Tab character width = 2 space characters
		*/

			/* Forward declarations */

			/* 程式所 include 之函式庫的標頭檔
			   Included Library Headers */
				/* 標準Ｃ＋＋函式庫 */
					#include <string>

#if defined(__unix__) || defined(__unix)
				/* POSIX API */
					/* for mode_t */
						#include <sys/types.h>
#endif //Unix system only
			/* 常數與巨集的定義
			 * Definition of constants & macros */

			/* 資料類型、enumeration、資料結構與物件類別的定義
			 *  Definition of data type, enumeration, data structure and class */
				/* 輸出訊息的格式 */
					typedef enum print_format{
						/* 縮寫 */
							SHORT,
						/* 全稱（文字） */
							LONG,
						/* 八進位數字 */
							OCTAL,
						/* 十進位數字 */
							DECIMAL
					}Print_format;

				/* 權限設定套用的對象 */
					typedef enum permission_target{
						OWNER, GROUP, OTHER
					}Permission_target;

				/* 時間的類型 */
					typedef enum time_type{
						CREATE_TIME, MODIFY_TIME, ACCESS_TIME
					}Time_type;
				/* 時間的格式 */
					typedef enum time_format{
						DEFAULT
					}Time_format;

				/* 目錄的格式 */
					typedef enum path_format{
						RELATIVE, ABSOLUTE
					}Path_format;

			/* 函式雛型
				 Function prototypes */
#if defined(__unix__) || defined(__unix)
				bool isDirectory(std::string entry_path);

				/* 印出路徑的資訊的子程式 */
					void showPathInfo(std::string path);

				/* 檔案系統項目相關子程式 */
					void printItemType(Print_format format, mode_t mode);

					void printItemPermission(Print_format format, mode_t mode);
					void printWhoPermission(Print_format format, Permission_target who, mode_t mode);

					void printItemOwnership(Print_format format, uid_t uid, gid_t gid);
					void printUID(Print_format format, uid_t uid);
					void printGID(Print_format format, gid_t gid);

					void printTime(Time_format format, time_t time);

					void printItemPath(Path_format format, const char *item_path);
#ifdef UNIMPLEMENTED

#endif

#endif
			/* 全域變數
				 Global variables */

			/* Inline 子程式的實作
			   Inline procedure implementations
			     限制
			     Limitations
			       C89 規範中不可用
			     參考資料
			     Reference resources
			       How do you tell the compiler to make a member function inline?, C++ FAQ
			       http://www.parashift.com/c++-faq-lite/inline-member-fns.html */

	#endif/* VCCL_FILE_SYSTEM */
