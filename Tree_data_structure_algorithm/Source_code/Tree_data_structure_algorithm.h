#ifndef TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #define TREE_DATA_STRUCTURE_ALGORITHM_H_INCLUDED
  #ifdef __cplusplus
    extern "C"{
  #endif
    /*典型二元樹資料結構
     *  版本：1.00(0)*/
    typedef struct treeNode{
      /*資料項*/

      /*指向左右子節點的指標*/
      struct treeNode * leftChild, * rightChild;

    }TreeNode;

    /*中序Traversal演算法函式的function prototype*/
    void inorder(TreeNode * treeNodePtr);

    /*前序Traversal演算法函式的function prototype*/
    void preorder(TreeNode * treeNodePtr);

    //後序Traversal演算法函式的function prototype
    void postorder(TreeNode * treeNodePtr);

    //階層順序走訪(Level Order Traversal)演算法函式的function prototype
    void levelOrder(TreeNode * treeNodePtr);

    //用level order形式印出heap中的資料的函式的function prototype
    void levelPrintHeap(HeapElement heap[], unsigned int heap_size);

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

    //Push元素至Max Heap中的函式的function prototype
    short int maxHeapPush(HeapElement item, HeapElement max_heap[], unsigned int *heap_size);

    //自Max Heap中pop出元素的函式的function prototype
    HeapElement maxHeapPop(HeapElement max_heap[], int *heap_size);

    //將3-tuple資料寫入樹中函式的function prototype
    TreeNode * dataToTree(TreeNode * * target_root, const char * input_string);

    //判斷右算式位置的函式
    inline short int findRightFormula(const char * input_string);

    //清除樹的記憶體配置函式
    TreeNode * destroyTree(TreeNode * treeNodePtr);

  #ifdef __cplusplus
    }
  #endif
#endif