/*錯誤訊息*/

/*錯誤訊息標籤*/
#define ERROR_TAG "【錯誤】"

/* 檔案開啟失敗
 * FIXME:換行會造成下一行沒有ERROR_TAG...*/
#define ERROR_FILE_OPEN_FAIL "檔案開啟失敗！\n" << ERROR_TAG << "請確定要開啟的檔案是否存在於作用中的目錄下，或是您是否有權限讀取它。\n"

/*divide by zero fail*/
#define ERROR_DIVIDE_BY_ZERO "偵測到沒有被定義正確之運算結果之「除數為零的除法運算」！\n"

/* MEMORY ALLOCATION FAIL */
#define ERROR_MEMORY_ALLOCATION_FAIL "向作業系統要求配置記憶體空間失敗！請確定作業系統是否有足夠的可用記憶體空間。\n"

