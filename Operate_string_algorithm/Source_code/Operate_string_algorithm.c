
/*翻轉字串函式
  版本：1.00(1)
  適用範圍：純ASCII字串。
  參數target_strPtr：指向要轉換的字串的指標
  回傳值：無*/
void reverseString(char * const target_strPtr)
	{
		/*宣告與定義(declaration & definition)*/
		unsigned int endCtr;/*用來指向字串結尾的計數器*/
    unsigned int frontCtr;/*用來指向字串開頭的計數器*/
    char bufferChar;

		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*找到該字串的結尾*/
        /*endCtr will point at '\0' after loop*/
        for(endCtr = 0; *(target_strPtr + endCtr) != '\0'; endCtr++);
        /*讓endCtr指向null字元以外的最後一個字元*/
        endCtr--;

		/*依序前後交換字元*/
        for(frontCtr = 0; frontCtr < endCtr; frontCtr++, endCtr--){
            bufferChar = *(target_strPtr + frontCtr);/*hold front char*/
            /*assign front char with back char*/
            *(target_strPtr + frontCtr) = *(target_strPtr + endCtr);
            /*assign back char with buffered char*/
            *(target_strPtr + endCtr) = bufferChar;
        }
		/*－－－－－－－－－－－－－－－－－－－－－*/
		return ;
	}
