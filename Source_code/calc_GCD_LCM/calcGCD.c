#include <stdio.h>
#include "../Swap_algorithm_C/Swap_algorithm_C.h"

/* 計算最大公因數函式 */
unsigned int calcGcd(unsigned int number_A, unsigned int number_B){
	/*最大公因數演算法？
		輾轉相除法：
			a   b
			30  10
	*/
	/*宣告與定義(Declaration & Definition)*/

	/*－－－－－－－－－－－－－－－－－－－－－*/
	#ifndef NDEBUG
		printf("Call function to find %u, %u 's G.C.D.\n", number_A, number_B);
	#endif

	if(number_A < number_B){
		swapUnsignedInteger(&number_A, &number_B);
	}

	/*特殊情況：如果b直接整除a則b為最大公因數*/
	if(number_A % number_B == 0) {
		return number_B;
	}else{
		/*若不整除則取餘數跟b取最大公因數？*/
		return calcGcd(number_A % number_B , number_B);
	}
	/*－－－－－－－－－－－－－－－－－－－－－*/
}
