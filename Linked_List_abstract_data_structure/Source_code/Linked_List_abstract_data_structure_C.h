/*單向Linked list節點資料結構*/
typedef struct uniListNode{
	/*資料宣告*/

	/*指向下一節點的指標*/
	struct uniListNode * next_node;
}UniListNode;

/*雙向Linked list節點資料結構*/
typedef struct biListNode{
	/*指向前一節點的指標*/
	struct biListNode * before_node;
	/*資料宣告*/

	/*指向下一節點的指標*/
	struct biListNode * next_node;
}BiListNode;
