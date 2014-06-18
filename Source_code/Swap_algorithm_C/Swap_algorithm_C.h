#ifndef VCCL_SWAP_ALGOTITHM_INCLUDED
  #define VCCL_SWAP_ALGOTITHM_INCLUDED
  #ifdef __cplusplus
  extern "C"{
  #endif
	/* Function to swap contents of interger variable_a and variable_b */
		void swapInteger(int *variable_a, int *variable_b);
	/* Function to swap contents of unsigned interger variable_a and variable_b */
		void swapUnsignedInteger(unsigned int *variable_a, unsigned int *variable_b);
	void swapLongInteger(long *variable_a,long *variable_b);
	void swapUnsignedShortInteger(unsigned short *variable_a, unsigned short *variable_b);
	void swapDouble(double *a,double *b);
  #ifdef __cplusplus
  }
  #endif
#endif
