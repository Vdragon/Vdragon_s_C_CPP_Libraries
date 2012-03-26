#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "findMaxMin/findMaxMin.h"

#define MAX_RANDOM_DATA_SIZE 5

/*function for printing all integers in an array*/
void printArrayInt(int input[], unsigned arraySize);


int main(void)
  {
    int * random_input  = (int *)malloc(sizeof(int) * MAX_RANDOM_DATA_SIZE);
    unsigned i;

    /*seed random number generator*/
    srand(time(NULL));
    for(i = 0; i < MAX_RANDOM_DATA_SIZE; ++i){
      random_input[i] = rand() % 25 + 1;
    }

    printf("陣列原有的資料為：\n");
    printArrayInt(random_input, MAX_RANDOM_DATA_SIZE);

    putchar('\n');
    printf("呼叫intArrayMax()，陣列中最大的資料為：%d\n", intArrayMax(random_input, MAX_RANDOM_DATA_SIZE));
    printf("呼叫intArrayMin()，陣列中最小的資料為：%d\n", intArrayMin(random_input, MAX_RANDOM_DATA_SIZE));

    {
      double small = -3, big = 16;
      assert(MIN_OF_2(small, big) == small);
      assert(MIN_OF_2(big, small) == small);
      assert(MAX_OF_2(small, big) == big);
      assert(MAX_OF_2(big, small) == big);
      printf("MIN_OF_2()、MAX_OF_2()測試通過。\n");
    }

    return 0;
  }

void printArrayInt(int input[], unsigned arraySize)
{
  unsigned i;

  for(i = 0; i < arraySize; ++i){
    printf("%3d ", input[i]);

  }
  putchar('\n');
  return;
}
