#ifndef TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #define TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif

  /* 訊息 */
  #define TREE_ADT_TAG "【樹(Tree)抽象資料類型】"

  /* 樹節點的定義 */
  typedef struct treeNode{
    /*資料項*/
    int data;
    /*指向左右子節點的指標*/
    struct treeNode *leftChild, *rightChild;
  }TreeNode;

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
    /* public */
    /* 初始化二元樹物件的函式 */
    void (*create) (struct binaryTree *self);
    /* 清除二元樹物件的函式 */
    void (*destroy)(struct binaryTree *self);
    /* 中序Traversal演算法函式 */
    void (*inorder)(struct binaryTree *self);
    /* 前序Traversal演算法函式 */
    void (*preorder)(struct binaryTree *self);
    /* 元件測試函式 */
    short (*unitTest)(struct binaryTree *self);
    /* private */

  }BinaryTree;
  /* 元件測試函式 */
  short binaryTreeUnitTest(struct binaryTree *self);
  void binaryTreeCreate(BinaryTree *self);
  void binaryTreeDestroy(BinaryTree *self);
  /* 遞迴地釋放樹佔用的記憶體的函式
   * 運行完後只剩下最上層的root還存在 */
  void destroyBinaryTreeChild(BinaryTreeNode *root);
  void binaryTreeInorder(BinaryTree *self);
  void inorder(BinaryTreeNode *root);
  void binaryTreePreorder(BinaryTree *self);
  /*前序Traversal演算法函式的function prototype*/
  void preorder(BinaryTreeNode *root);
  //後序Traversal演算法函式的function prototype
  void postorder(TreeNode * treeNodePtr);
  //階層順序走訪(Level Order Traversal)演算法函式的function prototype
  void levelOrder(TreeNode * treeNodePtr);
  //將3-tuple資料寫入樹中函式的function prototype
  TreeNode * dataToTree(TreeNode * * target_root, const char * input_string);
  //判斷右算式位置的函式
  inline short int findRightFormula(const char * input_string);


  //Max Heap資料結構
//定義Heap中最多允許之元素數量
#define MAX_HEAP_ELEMENTS 100
//測試Heap是否已滿的巨集(Macro)
#define HEAP_IS_FULL(n) (n == MAX_HEAP_ELEMENTS - 1)
//測試Heap是否為空的巨集(Macro)
#define HEAP_IS_EMPTY(n) (!(n == 1))

////Max Heap資料結構

//Max Heap的資料結構定義
typedef struct HeapElement{
  int key;

}HeapElement;
//用level order形式印出heap中的資料的函式的function prototype
void levelPrintHeap(HeapElement heap[], unsigned int heap_size);

//Push元素至Max Heap中的函式的function prototype
short int maxHeapPush(HeapElement item, HeapElement max_heap[], unsigned int *heap_size);

//自Max Heap中pop出元素的函式的function prototype
HeapElement maxHeapPop(HeapElement max_heap[], unsigned *heap_size);

  #ifdef __cplusplus
    }
  #endif
#endif
