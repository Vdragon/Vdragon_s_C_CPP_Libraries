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
		「顯示軟體資訊函式庫」是 Vdragons_C_CPP_Libraries_Collection 的一部份，請參考 Vdragons_C_CPP_Libraries_Collection 說明文件中的授權條款章節。		
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
	enum software_license{
		UNDEFINED, OTHER, GPL, LGPL, PUBLIC_DOMAIN, CC0, WTFPL, MIT, BSD_3_CLAUSE, BSD_2_CLAUSE, MPL, APACHE
	};
	typedef enum software_license Software_license;

	typedef struct software_information{
		/* 保存軟體資訊用的資料結構，未初始化的字元字串請賦值 NULL */
		
		/* 軟體名稱 */
		char *software_name; 
		
		char *software_official_website; 
		char *software_issue_tracker; 
		
		/* 軟體開發者資訊 */
		char *software_developer_name; 
		char *software_developer_email; 
		
		/* 軟體智慧財產權生效年，通常是最後一次修改程式碼的年份 */
		int software_copyright_valid_year; 
		
		/* 軟體所採用的授權條款 */
		Software_license software_license; 
		char *software_license_other_name; 
		char *software_license_version; 
		unsigned short software_license_version_or_later; 
		char *software_license_other_url;
	}Software_information;
	
	/* 一個全軟體範圍共用的軟體資料結構 */
	Software_information global_software_information;

  /* 顯示軟體資訊的函式
   *   印出資訊，將控制交還給主要程式
   * 參數：
   *   program_name:程式名稱（非軟體名稱）的陣列
	 *   */
  void showSoftwareInfo(const char program_name[]);

  /* 在程式結束前顯示軟體資訊（錯誤回報網址等）的子程式
   * 　通常註冊於 atexit();
   */
  void showSoftwareInfoBeforeExit(void);
 
  #ifdef __cplusplus
    }
  #endif
#endif /* MODULE_VC_CPP_LIB_SHOWSHOFTWAREINFO */
