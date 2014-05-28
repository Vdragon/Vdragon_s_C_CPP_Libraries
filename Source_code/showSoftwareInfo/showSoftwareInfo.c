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

/* for definition of printf() */
#include <stdio.h>

/* printSomething library */
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
	void showSoftwareInfo_checkGettext(void);
/*////////全域變數(Global Variables)////////*/

	/* 判斷 gettext 函式庫有無初始化 */
		static short gettext_is_initialized = 0;

	char *software_license_names[12] = {
		"*** report issue if you see this***", 
		"*** report issue if you see this***", 
		"The GNU General Public License", 
		"GNU Lesser General Public License", 
		"Public domain", 
		"Creative Commons CC0", 
		"Do What the Fuck You Want to Public License(WTFPL)", 
		"The MIT License", 
		"The BSD 3-Clause License", 
		"The BSD 2-Clause License", 
		"Mozilla Public License", 
		"Apache License"};
	char *software_license_site_urls[12] = {
		"*** report issue if you see this***", 
		"*** report issue if you see this***", 
		"http://www.gnu.org/licenses/gpl.html", 
		"http://www.gnu.org/licenses/lgpl.html", 
		"https://creativecommons.org/about/pdm", 
		"https://creativecommons.org/about/cc0", 
		"http://www.wtfpl.net/about/", 
		"http://opensource.org/licenses/MIT", 
		"http://opensource.org/licenses/BSD-3-Clause", 
		"http://opensource.org/licenses/BSD-2-Clause", 
		"http://www.mozilla.org/MPL/", 
		"http://www.apache.org/licenses/"};
		
/*--------------主要程式碼(Main Code)--------------*/

void showSoftwareInfo_checkGettext(void){
	if(gettext_is_initialized == 0){
		bindtextdomain(MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO, "Translations");
		gettext_is_initialized = 1;
	}
	return;
}

/* 顯示軟體資訊的函式
   *  印出資訊，將控制交還給主要程式*/
void showSoftwareInfo(const char program_name[]){

	showSoftwareInfo_checkGettext();

	printLine(
			PRINTSOMETHING_COMPONENT_HYPHEN_MINUS,
			LINE_LENGTH);

  /*顯示程式名稱及著作權宣告*/
  printf(_("%s\n"), program_name);
	if(global_software_information.software_developer_name != NULL){
		printf(_("本軟體的智慧財產擁有者：%s"), 
			global_software_information.software_developer_name);
		if(global_software_information.software_developer_email != NULL){
			printf(" <%s>", 
				global_software_information.software_developer_email);
		}
		putchar('\n');
	}
	if(global_software_information.software_copyright_valid_year >= 0){
		printf(_(
			"本軟體的智慧財產權自 %d 年起生效\n"), 
			global_software_information.software_copyright_valid_year);
	}
  putchar('\n');

  /*顯示授權條款*/
	if(global_software_information.software_name != NULL){
		printf(_("「%s」是「%s」軟體的一部份。\n"),
			program_name, global_software_information.software_name);
	}
	if(global_software_information.software_license != UNDEFINED){
		if(global_software_information.software_license != OTHER){
			if(global_software_information.software_license_version != NULL){
				if(global_software_information.software_license_version_or_later){
					printf(_(
						"「%s」軟體採用「%s」授權條款 %s 或其任一更新版本釋出，詳情請參考：\n"
						"%s\n"), 
						(global_software_information.software_name != NULL) ? 
							global_software_information.software_name : program_name, 
						_(software_license_names[global_software_information.software_license]), 
						global_software_information.software_license_version, 
						software_license_site_urls[global_software_information.software_license]);
				}else{
					printf(_(
						"「%s」軟體採用「%s」授權條款 %s 版本釋出，詳情請參考：\n"
						"%s\n"), 
						(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
						_(software_license_names[global_software_information.software_license]),  
						global_software_information.software_license_version, 
						software_license_site_urls[global_software_information.software_license]);
				}
			}else{
				printf(_(
					"「%s」軟體採用「%s」授權條款釋出，詳情請參考：\n"
					"%s\n"), 
					(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
					_(software_license_names[global_software_information.software_license]), 
					software_license_site_urls[global_software_information.software_license]);
			}
		}else{ 
			if(global_software_information.software_license_other_name != NULL){
				if(global_software_information.software_license_version != NULL){
					if(global_software_information.software_license_version_or_later){
						if(global_software_information.software_license_other_url != NULL){
							printf(_(
								"「%s」軟體採用「%s」授權條款 %s 或其任一更新版本釋出，詳情請參考：\n"
								"%s\n"), 
								(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
								global_software_information.software_license_other_name, 
								global_software_information.software_license_version, 
								global_software_information.software_license_other_url);
						}else{
							printf(_(
								"「%s」軟體採用「%s」授權條款 %s 或其任一更新版本釋出\n"), 
								(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
								global_software_information.software_license_other_name, 
								global_software_information.software_license_version);
						}
					}else{
						if(global_software_information.software_license_other_url != NULL){
							printf(_(
								"「%s」軟體採用「%s」授權條款 %s 版本釋出，詳情請參考：\n"
								"%s\n"), 
								(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
								global_software_information.software_license_other_name, 
								global_software_information.software_license_version, 
								global_software_information.software_license_other_url);
						}else{
							printf(_(
								"「%s」軟體採用「%s」授權條款 %s 版本釋出\n"), 
								(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
								global_software_information.software_license_other_name, 
								global_software_information.software_license_version);
						}
					}
				}else{
					if(global_software_information.software_license_other_url != NULL){
						printf(_(
							"「%s」軟體採用「%s」授權條款釋出，詳情請參考：\n"
							"%s\n"), 
							(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
							global_software_information.software_license_other_name, 
							global_software_information.software_license_other_url);
					}else{
						printf(_(
							"「%s」軟體採用「%s」授權條款釋出\n"), 
							(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
							global_software_information.software_license_other_name);
					}
				}
				printf(_("「%s」軟體採用「%s」授權條款釋出"), 
					(global_software_information.software_name != NULL) ?  global_software_information.software_name : program_name, 
					global_software_information.software_license_other_name);
			}
		}
	}
	printLine(
			PRINTSOMETHING_COMPONENT_HYPHEN_MINUS,
			LINE_LENGTH);

  return ;
}

void showSoftwareInfoBeforeExit(void){
#if 0
	showSoftwareInfo_checkGettext();
#endif
	printLine("-", 20);
	printf(_(
		"程式運行結束。\n"
		"本軟體的官方網站位於\n"
		"	%s\n"
		"如果發現任何軟體上的缺陷請至下列位址回報。\n"
		"	%s\n"), 
		global_software_information.software_official_website, 
		global_software_information.software_issue_tracker);
	return;
}
