/* include guard：避免同一個header檔案被include第二次。*/
#ifndef MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO
/*程式名稱
	Program name */
	#define MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO "tw.idv.Vdragon.Vdragons_C_CPP_Libraries_Collection.showSoftwareInfo"
	#define MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO_READABLE "Show software's information library"
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
		Copyright 2013 林博仁<pika1021@gmail.com>
	智慧財產授權條款
	Intellectual property license
		顯示軟體資訊函式庫 is part of Vdragons_C_CPP_Libraries_Collection
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
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif

  /* 顯示軟體資訊的函式
   *   印出資訊，將控制交還給主要程式
   * 參數：
   *   program_name:程式名稱（非軟體名稱）的陣列*/
  void showSoftwareInfo(const char program_name[]);
  /* 在程式結束前顯示軟體資訊（錯誤回報網址等）的子程式
   * 　通常註冊於 atexit();
   */
  void showSoftwareInfoBeforeExit(void);
  #ifdef __cplusplus
    }
  #endif
#endif /* MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO */
