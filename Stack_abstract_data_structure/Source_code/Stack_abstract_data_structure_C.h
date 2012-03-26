/*------堆疊(Stack)-------*/
/*定義堆疊(Stack)最大容量大小*/
#define MAX_STACK_SIZE 100

//堆疊(Stack)元素資料結構
typedef struct stackElement{
    //資料members

}StackElement;

//宣告一個堆疊(Stack)
StackElement stack[MAX_STACK_SIZE];

//指向堆疊top位置指標或註標(subscript)
int stack_top = -1;

//判斷堆疊是否為空函式的function prototype
inline short int stackIsEmpty(int stack_top);

//判斷堆疊是否為空函式
//版本：1.00(0)
inline short int stackIsEmpty(int stack_top)
	{
    return (stack_top == -1) ? 1 : 0;
    }

//判斷堆疊是否已滿函式的function prototype
inline short int stackIsFull(int stack_top);

//判斷堆疊是否已滿函式
//版本：1.00(0)
inline short int stackIsFull(int stack_top)
	{
    return (stack_top == MAX_STACK_SIZE - 1) ? 1 : 0;
    }

//將元素push至堆疊的函式的function prototype
short int stackPush(StackElement item, StackElement stack[], int *stack_top);

//將元素push至堆疊的函式
//版本：1.00(0)
short int stackPush(StackElement item, StackElement stack[], int *stack_top)
    {
    //宣告與定義(Declaration & Definition)
    //－－－－－－－－－－－－－－－－－－－－－
    //如果堆疊已滿就錯誤離開
    if(stackIsFull(*stack_top)){
        return -1;
    }
    //將元素插入堆疊中
    stack[++*stack_top] = item;

    //－－－－－－－－－－－－－－－－－－－－－
    //傳回0
    return 0;
    }

//將元素pop出堆疊的函式的function prototype
StackElement stackPop(StackElement stack[], int *stack_top);

//將元素pop出堆疊的函式
//版本：1.00(0)
StackElement stackPop(StackElement stack[], int *stack_top)
    {
    //宣告與定義(Declaration & Definition)
    //－－－－－－－－－－－－－－－－－－－－－
    //如果堆疊已滿就錯誤離開
    if(stackIsEmpty(*stack_top)){
        //製造表示函式錯誤的元素
        StackElement errorElement;
        //傳回表示函式錯誤的元素
        return errorElement;
    }
    //－－－－－－－－－－－－－－－－－－－－－
    //傳回top位置的元素並遞減top
    return stack[--*stack_top];
    }

