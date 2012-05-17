/* ====標準C函式庫==== */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* this */
#include "Tree_abstract_data_type_C.h"

/* Vdragon's Library Collection */
#include "../Messages_templates/zh_TW.h"

/* 初始化二元樹物件的函式 */
void binaryTreeCreate(BinaryTree *self)
{
  self->root = NULL;
  self->destroy = binaryTreeDestroy;
  self->unitTest = binaryTreeUnitTest;
  self->inorder = binaryTreeInorder;
  self->preorder = binaryTreePreorder;
  self->postorder = binaryTreePostorder;
  return;
}

/* 清除二元樹物件的函式 */
void binaryTreeDestroy(BinaryTree *self)
{
  destroyBinaryTreeChild(self->root);
  free(self->root);
  return;
}

/* 元件測試函式 */
short binaryTreeUnitTest(struct binaryTree *self)
{

  /* 測試通過 */
  fprintf(stdout, TREE_ADT_TAG "元件測試全部通過！\n");
  return 0;
}

/* 遞迴地釋放樹佔用的記憶體的函式
 * 運行完後只剩下最上層的root還存在 */
void destroyBinaryTreeChild(BinaryTreeNode *root)
  {
  /*1.直到到達leaf節點即停止呼叫自己*/
  if(root != NULL){
    /*1.1.先呼叫自己拜訪左子樹*/
    destroyBinaryTreeChild(root->leftChild);
    /*1.2.清除左子樹節點*/
    free(root->leftChild);
    /*1.3.再呼叫自己拜訪右子樹*/
    destroyBinaryTreeChild(root->rightChild);
    /*1.4.清除右子樹節點*/
    free(root->rightChild);
  }
  return ;
  }

/* 中序Traversal演算法函式 */
void binaryTreeInorder(BinaryTree *self)
{

  inorder(self->root);
  return;
}

/*中序Traversal演算法函式 */
void inorder(BinaryTreeNode *root)
	{
  /*1.直到到達leaf節點即停止呼叫自己*/
  if(root != NULL){
      /*1.1.先呼叫自己拜訪左子樹*/
      inorder(root->leftChild);
      /*1.2.讀出值*/
      fprintf(stdout, "%d ", root->data);
      /*1.3.再呼叫自己拜訪右子樹*/
      inorder(root->rightChild);
  }
  return ;
	}

/* 前序Traversal演算法函式 */
void binaryTreePreorder(BinaryTree *self)
{
  preorder(self->root);
  return;
}

/* 前序Traversal演算法函式 */
void preorder(BinaryTreeNode *root)
{

  /* 1.直到到達leaf節點即停止呼叫自己 */
  if(root != NULL){
    /* 1.1.先讀出值 */
    fprintf(stdout, "%d ", root->data);
    /* 1.2.再呼叫自己拜訪左子樹 */
    preorder(root->leftChild);
    /* 1.3.再呼叫自己拜訪右子樹 */
    preorder(root->rightChild);
  }
  return ;
}

/* 後序Traversal演算法函式 */
void binaryTreePostorder(BinaryTree *self)
{
  postorder(self->root);
  return;
}

/* 後序Traversal演算法函式 */
void postorder(BinaryTreeNode * treeNodePtr)
{
  /*1.直到到達leaf節點即停止呼叫自己*/
  if(treeNodePtr != NULL){
    /*1.1.先呼叫自己拜訪左子樹*/
    postorder(treeNodePtr->leftChild);
    /*1.2.再呼叫自己拜訪右子樹*/
    postorder(treeNodePtr->rightChild);
    /*1.3.再讀出值*/

  }
  return ;
}

void binaryTreeDataToTree(BinaryTree *self, const char *input)
{
  dataToBinaryTree(&(self->root), input);
  return;
}

/* 將3-tuple資料寫入樹中函式 */
BinaryTreeNode * dataToBinaryTree(BinaryTreeNode * *target_root, const char *input)
	{
		//宣告與定義(Declaration & Definition)

		//－－－－－－－－－－－－－－－－－－－－－
		/*test 01
		printf("%d\t%d\n", '0', '9');
    *///test 01->48, 57

    //malloc current root node
    *target_root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

    //如果得到的string中間項是一個數字表示該為leaf節點
    if(input[0] >= 48 && input[0] <= 57){
        //將target_root值設為該數字，其左右子設NULL
        (*target_root)->data = atoi(input);
        (*target_root)->leftChild = NULL;
        (*target_root)->rightChild = NULL;
    }
    else{//得到的string非數字（左括號）
        //第二個字元為運算子
        (*target_root)->data = input[1];
        //第三個字元之後（第四個字元開始）的字串是左算式
        (*target_root)->leftChild = dataToBinaryTree(&(*target_root)->leftChild, input + 3);

        //呼叫findRightFormula尋找右運算式位置
        (*target_root)->rightChild = dataToBinaryTree(&(*target_root)->rightChild, input + findRightFormula(input));
    }
		//－－－－－－－－－－－－－－－－－－－－－
		//傳回內容
		return *target_root;
	}


/* 判斷右算式位置的函式 */
short findRightFormula(const char * input_string)
    {
    //宣告與定義(Declaration & Definition)
    //左括弧、右括弧、讀取字串計數器
    unsigned left_brace_count = 0, right_brace_count = 0,
                read_string_count = 0, comma_count = 0;

    //－－－－－－－－－－－－－－－－－－－－－
    //當還沒讀到字串結尾時
    while(input_string[read_string_count] != '\0'){
      switch(input_string[read_string_count]){
      case '(':
          left_brace_count++;
          break;
      case ')':
          right_brace_count++;
          break;
      case ',':
          comma_count++;
          break;
      default:
          break;
      };
      read_string_count++;
    }

    //判斷formula類型
    //如果為最簡單formula
    if(left_brace_count == 1){
        //右formula為第二個逗號後面一字元開始
        comma_count = 0;
        for(read_string_count = 0 ; comma_count != 2; read_string_count++){
            if(input_string[read_string_count] == ','){
                comma_count++;
            }
        }
        return read_string_count;
    }
    //如果非最簡單formula
    else{
        //reset
        left_brace_count = right_brace_count = 0;
        comma_count = 1;

        //在第一個逗號之後開始計算左右括號數量，當左括號數量
        //同右括號數量時遇到的逗號方為右表達式前的第二個逗號
        for(read_string_count = 3; comma_count != 2 ; read_string_count++){
            switch(input_string[read_string_count]){
            case '(':
                left_brace_count++;
                break;
            case ')':
                right_brace_count++;
                break;
            case ',':
                if(left_brace_count == right_brace_count){
                    comma_count = 2;
                }
            default:
                break;
            };
        }//迴圈結束時read_string_count會指向第二個表達式
        return read_string_count;
    }////如果非最簡單formula
    //－－－－－－－－－－－－－－－－－－－－－
    //傳回錯誤
    return -1;
    }

/* ====heap 抽象資料類型==== */
/* 建構並初始化heap物件的函式 */
short heapCreate(Heap *self, unsigned size, HeapType type)
{
  /* 初始化各個函式指標 */
  self->destroy = heapDestroy;
  self->isEmpty = heapIsEmpty;
  self->isFull = heapIsFull;
  self->levelPrint = heapLevelPrint;

  /* 要求size大小記憶體給heap */
  self->heap = (HeapElement *)malloc(sizeof(HeapElement) * size);
  if(self->heap == NULL){
    fprintf(stderr, ERROR_TAG ERROR_MEMORY_ALLOCATION_FAIL);
    return -1;
  }

  /* 初始化屬性 */
  self->length = 0;
  self->size = size;
  self->type = type;

  /* 完成create操作 */
  return 0;
}

/* 清除heap物件的函式 */
void heapDestroy(Heap *self)
{
  /* 釋放記憶體空間 */
  free(self->heap);
  self->size = self->length = 0;

  /* 完成destroy操作 */
  return;
}

/* 判斷heap是否為空的函式 */
short heapIsEmpty(Heap *self)
{
  if(self->length == 0){
    return 1;
  }else{
    return 0;
  }
}

/* 判斷heap是否為滿的函式 */
short heapIsFull(Heap *self)
{
  if(self->length == self->size){
    return 1;
  }else{
    return 0;
  }
}

/* 用level order形式印出heap中的資料的函式 */
void heapLevelPrint(Heap *self)
    {
    /*如果heap中無資料則直接退出*/
    if(heapIsEmpty(self)){
        printf("目前heap中無資料。\n"
               "There are currently no data in the heap.\n");
        return;
    }
    else{
      /*現在處理的元素計數器*/
      register unsigned curr_print;

      /*用for迴圈從第一個元素輸出到最後一個元素*/
      for(curr_print = 1; curr_print <= self->size; ++curr_print){
          printf("%d[%d] ", curr_print, (self->heap[curr_print]).key);
      }
    }
    /*斷行*/
    putchar('\n');

    return ;
    }


/* Add元素至Heap中的函式
   時間複雜度：O(log(2,n)) */
short HeapAdd(Heap *self, HeapElement item)
    {
    /*宣告與定義(Declaration & Definition)*/
    /* 元素的寫入位置 */
    unsigned insert_position;

    /*如果heap已滿就異常退出*/
    if(self->length == self->size){
      fprintf(stderr, ERROR_TAG "無法新增元素於已滿的heap！");
      return -1;
    }

    /* 將length遞增一並將同時是item可能
     * 之存放位置之heap_size值存進insert_position
     * 進行判斷 */
    insert_position = ++(self->length);

    /* 當insert_position不是根節點且item的key比其父節點的key還要大時 */
    while((insert_position != 1) &&
        (item.key > (self->heap[insert_position / 2]).key)){
      /* 將item bubble up至item的父節點位置（將父節點位置拉至insert_position當前的位置
         然後將insert_position設成父節點以前的位置） */
      self->heap[insert_position] = self->heap[insert_position / 2];
      insert_position /= 2;
    }
    /* 將item元素寫入insert_position位置中 */
    self->heap[insert_position] = item;
    return 0;
    }

#if 0
/* 自Max Heap中delete出元素的函式 */
HeapElement maxHeapDelete(HeapElement max_heap[], unsigned *heap_size)
  {
    //用來判斷要插入的位置的兩個變數
    unsigned int parent_insert, child_compare;

    //pop出來的元素跟用來暫時存放的元素
    HeapElement popped_item, temp;

    //如果max heap沒有資料則回傳表示出錯的元素
    if(HEAP_IS_EMPTY(*heap_size)){
    //函式異常退出
    printf("函式欲從沒有資料的max heap中取出資料，函式必須異常退出。\n"
           "The function attempt to acquire data from an empty max heap, function must be errorly exited.\n");
        popped_item.key = -999999;
        return popped_item;
    }

    //讀出含有最大鍵的元素
    popped_item = max_heap[1];

    //把最後一個元素提取出來尋找插入的位置
    temp = max_heap[(*heap_size)--];

    //將parent預設為根結點（被ＰＯＰ掉了），child設為第一個子節點
    parent_insert = 1;
    child_compare = 2;

    //當還沒有判斷完全部的child之前
    while(child_compare <= *heap_size){
      //如果child位置還沒到最後一個元素且當前parent的右邊child的key比左邊child的key還要大
      if((child_compare < *heap_size) && (max_heap[child_compare].key < max_heap[child_compare + 1].key)){
          //將child_compare設成兩個child中比較大者
          child_compare++;
      }

      //如果temp的key比兩個child中比較大的child的key還要大表示temp應該插入至這個位置
      if(temp.key >= max_heap[child_compare].key){
          //離開while迴圈
          break;
      }

      //將兩個child中比較大的child swap至其parent（當前因為被pop掉了所以無值）的位置
      max_heap[parent_insert] = max_heap[child_compare];
      parent_insert = child_compare;

      //換成兩個child中比較大的child的child節點繼續跟temp做key的比較
      child_compare *= 2;
    }//結束while判斷迴圈

    //將temp插入至當前無值的位置
    max_heap[parent_insert] = temp;

  //－－－－－－－－－－－－－－－－－－－－－
  //傳回pop出的元素
  return popped_item;
  }
#endif
