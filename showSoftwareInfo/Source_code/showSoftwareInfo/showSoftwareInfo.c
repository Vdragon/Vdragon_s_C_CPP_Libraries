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
  printf(_("智慧財產權生效年 %s © 擁有人：%s <%s>\n"), SOFTWARE_RELEASE_YEAR, DEVELOPER_NAME, DEVELOPER_EMAIL);
  putchar('\n');

  /*顯示授權條款*/
  printf(_("%s 是 %s 的一部份。\n"), program_name, SOFTWARE_NAME);
  printf(_("%s 為自由軟體：您可以在 Free Software Foundation 所出版的 GNU Lesser General Public License 第 3 版或您可任意選擇之其未來版本的條款限制之下重新散佈或修改此軟體。\n"), SOFTWARE_NAME);
  putchar('\n');

  /* 顯示免責條款*/
  printf(_("%s 以其能發揮用途的期望被散佈，但是　並　不　包　含　任　何　保　證　，甚至不包含商業上使用的隱含保證或特定用途的適用性保證。參閱 GNU Lesser General Public License 以了解更多細節。\n"), SOFTWARE_NAME);
  putchar('\n');

  /*顯示附帶說明*/
  printf(_("於 %s 中您應該有收到 GNU Lesser General Public License 的副本。如果沒有，請瀏覽 <http://www.gnu.org/licenses/>。\n"), SOFTWARE_NAME);

	printLine(
			PRINTSOMETHING_COMPONENT_HYPHEN_MINUS,
			LINE_LENGTH);

  /* 結束*/
  return ;
}

void showSoftwareInfoBeforeExit(void){
	printLine("-", 20);
	printf(_(
		"程式運行結束。\n"
		"本軟體的官方網站位於\n"
		"	%s\n"
		"如果發現任何軟體上的缺陷請至下列位址回報。\n"
		"	%s\n"), SOFTWARE_OFFICIAL_SITE, SOFTWARE_ISSUE_REPORT_ADDRESS);
	return;
}
