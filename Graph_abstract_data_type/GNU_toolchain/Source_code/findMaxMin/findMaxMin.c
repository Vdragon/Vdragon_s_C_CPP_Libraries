

/*整數陣列求最大值函數
  版本：1.01(1)*/
int intArrayMax(int target[], unsigned array_size)
	{
		/*宣告與定義(Declaration & Definition)*/
		/*current max value*/
        int maxCurrent = target[0];
		/*counter for loop*/
        unsigned countA;
		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*read 2~last space*/
        /*for loop from second space to last*/
            for(countA = 1; countA < array_size; countA++)
                {
                /*if second space smaller than maxCurr*/
                if(target[countA] > maxCurrent)
                    {
                    /*then assign it as *new* maxCurr*/
                    maxCurrent = target[countA];
                    }
                }
		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*傳回最大值*/
		return maxCurrent;
	}

/*整數陣列求最小值intArrayMin函式
  版本：1.02(2)*/
int intArrayMin(int input[], unsigned short int arraySize)
	{
		/*宣告與定義(Declaration & Definition)*/
		/*minCurrent*/
			int minCurrent = input[0];
		/*counter for loop*/
			short int countA;
		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*read 2~last space*/
			/*for loop from second space to last*/
            for(countA = 1; countA < arraySize; countA++){
                    /*if second space smaller than minCurr*/
                    if(input[countA] < minCurrent){
                            /*then assign it as *new* minCurr*/
                                minCurrent = input[countA];
                    }
            }

		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*傳回最小值*/
		return minCurrent;
	}
