/*
  請見本檔案的標頭(header)檔案以得到更多關於本檔案的說明

  本程式的框架基於「C/C++ 程式範本」專案
  This program's frame is based on "C/C++ program templates" project
    https://github.com/Vdragon/C_CPP_program_templates
  建議編輯器設定
  Recommended editor settings
    Indentation by tab character
    Tab character width = 2 space characters
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要Project_specific_configurations中定義的軟體訊息*/
/* 自己的 header */
#include "showSoftwareInfo.h"

#include "../Project_specific_configurations/Software_info.h"

/*我們需要printf()*/
#include <stdio.h>

/* printSomething librfary */
#include "../printSomething/printSomething.h"

/* GNU gettext library */
#include <libintl.h>
#define _(String) dgettext(MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO, String)

/*////////常數與巨集(Constants & Macros)////////*/
#define LINE_LENGTH 50
/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/
	/* 判斷 gettext 函式庫有無初始化 */
		static short gettext_is_initialized = 0;

/*--------------主要程式碼(Main Code)--------------*/
/* 顯示軟體資訊的函式
   *  印出資訊，將控制交還給主要程式*/
void showSoftwareInfo(const char program_name[])
{
	if(gettext_is_initialized == 0){
		bindtextdomain(MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO, "Translations");
		gettext_is_initialized = 1;
	}

	printLine(
			PRINTSOMETHING_COMPONENT_HYPHEN_MINUS,
			LINE_LENGTH);

  /*顯示程式名稱及著作權宣告*/
  printf("%s\n", program_name);
  printf(_("Copyright %s © %s <%s>\n"), SOFTWARE_RELEASE_YEAR, DEVELOPER_NAME, DEVELOPER_EMAIL);
  putchar('\n');

  /*顯示授權條款*/
  printf(_("%s is part of %s.\n"), program_name, SOFTWARE_NAME);
  printf(_("%s is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or(at your option) any later version.\n"), SOFTWARE_NAME);
  putchar('\n');

  /* 顯示免責條款*/
  printf(_("%s is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.\n"), SOFTWARE_NAME);
  putchar('\n');

  /*顯示附帶說明*/
  printf(_("You should have received a copy of the GNU Lesser General Public License along with %s.  If not, see <http://www.gnu.org/licenses/>.\n"), SOFTWARE_NAME);

	printLine(
			PRINTSOMETHING_COMPONENT_HYPHEN_MINUS,
			LINE_LENGTH);

  /* 結束*/
  return ;
}
