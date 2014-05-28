/* include guard：避免同一個 header 檔案被 include 第二次 */
	#ifndef PROGRAM_NAME
		/*程式名稱
			Program name */
			#define PROGRAM_NAME "org.vsdg.lib.vccl.Messages_templates"
			#define PROGRAM_NAME_READABLE "Messages_templates library"
		/*變更紀錄
			Changelog
				Changelog is now stored in the Git repository log containing this file
			已知問題
			Known issues
				Known issues is now stored in this project's issue tracker
			待辦事項
			Todos
				Todos is now stored in this project's issue tracker
			著作權宣告
			Copyright declaration
				Copyright RELEASE_YEAR © 未定義作者<undefined@mail.address>
			智慧財產授權條款
			Intellectual property license
				Messages_templates is part of VCCL, please checkout this software's official site for the license this software apply.
			本程式的框架基於「C/C++ program templates」專案
			This program's framework is based on "C/C++ program templates" project
				https://github.com/Vdragon/C_CPP_program_templates
			建議編輯器設定
			Recommended editor settings
				Indentation by tab character
				Tab character width = 2 space characters
		*/

		/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
			#ifdef __cplusplus
				extern "C"{
			#endif /* __cplusplus */

			/* Forward declarations */

			/* 常數與巨集的定義
			 * Definition of constants & macros */

			/* 程式所 include 之函式庫的標頭檔
			   Included Library Headers */

			/* 資料類型、enumeration、資料結構與物件類別的定義
			 *  Definition of data type, enumeration, data structure and class */

			/* 函式雛型
				 Function prototypes */
				void message(const char tag[], const char module[], const char message[]);
				
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
		
			#ifdef __cplusplus
				}
			#endif /* __cplusplus */
	#endif/* PROGRAM_NAME */
