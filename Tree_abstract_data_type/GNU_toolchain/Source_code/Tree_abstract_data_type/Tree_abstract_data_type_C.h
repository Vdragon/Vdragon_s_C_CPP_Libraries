#ifndef TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #define TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif

  /* 訊息 */
  #define TREE_ADT_TAG "【樹(Tree)抽象資料類型】"

  /* 樹節點的定義 */
  typedef struct binaryTreeNode{
    /*資料項*/
    int data;
    /*指向左右子節點的指標*/
    struct binaryTreeNode *leftChild, *rightChild;
  }BinaryTreeNode;

  /* 典型二元樹抽象資料類型 */
  typedef struct binaryTree{
    /* ==屬性== */
    /* 二元樹的根節點 */
    BinaryTreeNode *root;

    /* ==介面== */
    /* 初始化二元樹物件的函式 */
    void (*create)(struct binaryTree *self);
    /* 清除二元樹物件的函式 */
    void (*destroy)(struct binaryTree *self);
    /* 中序Traversal演算法函式 */
    void (*inorder)(struct binaryTree *self);
    /* 前序Traversal演算法函式 */
    void (*preorder)(struct binaryTree *self);
    /* 後序Traversal演算法函式 */
    void (*postorder)(struct binaryTree *self);
    /* 將3-tuple資料寫入樹中的函式 */
    BinaryTreeNode * (*dataToTree)(struct binaryTree *self, const char *input);
    /* 元件測試函式 */
    short (*unitTest)(struct binaryTree *self);

  }BinaryTree;
  /* ====public member functions==== */
  short binaryTreeUnitTest(BinaryTree *self);
  void binaryTreeCreate(BinaryTree *self);
  void binaryTreeDestroy(BinaryTree *self);
  void binaryTreeInorder(BinaryTree *self);
  void binaryTreePreorder(BinaryTree *self);
  void binaryTreePostorder(BinaryTree *self);
  void binaryTreeDataToTree(BinaryTree *self, const char *input);

  /* ====private member functions==== */
  /* 遞迴地釋放樹佔用的記憶體的函式
   * 運行完後只剩下最上層的root還存在 */
  void destroyBinaryTreeChild(BinaryTreeNode *root);
  void inorder(BinaryTreeNode *root);
  void preorder(BinaryTreeNode *root);
  void postorder(BinaryTreeNode * treeNodePtr);
  BinaryTreeNode * dataToBinaryTree(BinaryTreeNode * *target_root, const char *input);
  /* 判斷右算式位置的函式 */
  short findRightFormula(const char * input);

/*
//測試Heap是否已滿的巨集(Macro)
#define HEAP_IS_FULL(n) (n == MAX_HEAP_ELEMENTS - 1)
//測試Heap是否為空的巨集(Macro)
#define HEAP_IS_EMPTY(n) (!(n == 1))*/


/* heap元素的定義 */
typedef struct heapElement{
  /* 用來元素之間比較大小的數值 */
  int key;

  /* 其他資料欄位 */

}HeapElement;

/* Heap的類型定義 */
typedef enum heapType{
  MAX_HEAP, MIN_HEAP
}HeapType;

/* Heap的抽象資料類型定義 */
typedef struct heap{
  /* ====屬性==== */
  /* heap的類型(max-heap/min-heap) */
  HeapType type;
  /* heap陣列
   * 由heap[1]至heap[size] */
  HeapElement *heap;
  /* heap陣列的總大小（不包括下標(subscript)為零者） */
  unsigned size;
  /* 目前heap使用的元素數（不包括下標(subscript)為零者） */
  unsigned length;

  /* ====介面==== */
  /* 建構並初始化heap物件的函式
   * 參數
   * 　*self
   * 　　物件本身
   * 　size
   * 　　heap大小
   * 回傳數值
   * 　-1
   * 　　系統可用記憶體空間不足*/
  short (*create)(struct heap *self, unsigned size, HeapType type);
  /* 清除heap物件的函式 */
  void (*destroy)(struct heap *self);
  /* 判斷heap是否為空的函式 */
  short (*isEmpty)(struct heap *self);
  /* 判斷heap是否為滿的函式 */
  short (*isFull)(struct heap *self);
  /* 用level order形式印出heap中的資料的函式 */
  void (*levelPrint)(struct heap *self);
  /* Push元素至Max Heap中的函式 */

}Heap;
/* ==public 成員函式== */
short heapCreate(Heap *self, unsigned size, HeapType type);
void heapDestroy(Heap *self);
short heapIsEmpty(Heap *self);
short heapIsFull(Heap *self);
void heapLevelPrint(Heap *self);
short heapAdd(Heap *self, HeapElement item);

#if 0
//自Max Heap中pop出元素的函式的function prototype
HeapElement maxHeapDelete(HeapElement max_heap[], unsigned *heap_size);
#endif
  #ifdef __cplusplus
    }
  #endif
#endif
