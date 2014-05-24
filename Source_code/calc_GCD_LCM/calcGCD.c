    #include <stdio.h>
    #include "Swap_algorithm.h"
    #include "Project_specific_configuration/Show_debug_message.h"

/*計算最大公因數函式
  版本：1.00(2)
  returnType functionName(auguments)
*/
unsigned int calcGcd(unsigned int number_A, unsigned int number_B)
	{
        /*最大公因數演算法？
            輾轉相除法：
                a   b
                30  10
        */
		/*宣告與定義(Declaration & Definition)*/


		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*print mess.*/
		if(SHOW_DEBUG_MESSAGE == 1)
            {
            printf("Call function to find %u, %u 's G.C.D.\n", number_A, number_B);
            }

            if(number_A < number_B)
                {
                    swapUnsignedInt(&number_A, &number_B);
                }
        /*特殊情況：如果b直接整除a則b為最大公因數*/
            if(number_A % number_B == 0)
                {
                    return number_B;
                }
        /*若不整除則取餘數跟b取最大公因數？*/
            else
                {
                    return calcGcd(number_A % number_B , number_B);
                }
		/*－－－－－－－－－－－－－－－－－－－－－*/

	}
