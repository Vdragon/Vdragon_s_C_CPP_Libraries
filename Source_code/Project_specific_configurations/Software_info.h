/* include guard：避免同一個 header 檔案被 include 第二次 */
	#ifndef LIB_VCCL_PRJ_SPECIFIC_CONFIG_SW_INFO
		/*程式名稱
			Program name */
			#define LIB_VCCL_PRJ_SPECIFIC_CONFIG_SW_INFO "org.vsdg.lib.vccl.project_specific_configurations.sw_info"
			#define LIB_VCCL_PRJ_SPECIFIC_CONFIG_SW_INFO_READABLE "Software info configurations"
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
				「程式名稱 | Program name」 is part of 「軟體名稱 | Software name」
				「軟體名稱 | Software name」 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
				
				「軟體名稱 | Software name」 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
				
				You should have received a copy of the GNU Lesser General Public License along with 「軟體名稱 | Software name」.  If not, see <http://www.gnu.org/licenses/>.
			本程式的框架基於「C/C++ program templates」專案
			This program's frame is based on "C/C++ program templates" project
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
				/*軟體名稱*/
					#define SOFTWARE_NAME "未命名軟體"
				/*軟體開發者名稱*/
					#define DEVELOPER_NAME "未命名開發者"
				/*軟體開發者的電子郵件地址*/
					#define DEVELOPER_EMAIL "（尚未設定電子郵件地址）"
				/*用在著作權宣告的軟體釋出年份*/
					#define SOFTWARE_RELEASE_YEAR "2013"
				/* 用在軟體所使用的授權條款版本（目前尚未實作）
				 * 有效值："「數字」（+）" "NONE"
					#define SOFTWARE_LICENSE_VERSION "3+"*/
				/* 軟體的官方網站 */
					#define SOFTWARE_OFFICIAL_SITE "SOFTWARE_OFFICIAL_SITE undefined"
				/* 軟體的問題回報地址 */
					#define SOFTWARE_ISSUE_REPORT_ADDRESS "SOFTWARE_ISSUE_REPORT_ADDRESS undefined"
					
			/* 程式所 include 之函式庫的標頭檔
			   Included Library Headers */

			/* 資料類型、enumeration、資料結構與物件類別的定義
			 *  Definition of data type, enumeration, data structure and class */
				/* 用在軟體所使用的授權條款 */
					typedef enum software_license{
						LICENSE_UNDEFINDED = 0, 
						LICENSE_LGPL, 
						LICENSE_GPL, 
						LICENSE_MPL
					}Software_license;
					
			/* 函式雛型
				 Function prototypes */
				
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
	#endif/* LIB_VCCL_PRJ_SPECIFIC_CONFIG_SW_INFO */
