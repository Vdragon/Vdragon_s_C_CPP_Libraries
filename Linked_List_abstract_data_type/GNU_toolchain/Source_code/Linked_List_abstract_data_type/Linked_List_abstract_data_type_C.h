/*list element*/
typedef int List_element;

/*單向Linked list節點資料結構*/
typedef struct uniListNode{
	/*資料宣告*/
  List_element data;
	/*指向下一節點的指標*/
	struct uniListNode * nextRef;
}UniListNode;

/*單向Linked list抽象資料類型*/
typedef struct uniList{
  UniListNode head;
  short (*uniListInitRef)(UniListNode first, unsigned size);
  void (*uniListDestroyRef)(UniListNode first);

}UniList;

/*Linked list初始化函式*/
short uniListInit(UniListNode first, unsigned size);

/*Linked list清理函式*/
void uniListDestroy(UniListNode first);

/*雙向Linked list節點資料結構*/
typedef struct biListNode{
	/*指向前一節點的指標*/
	struct biListNode * before_node;
	/*資料宣告*/
  List_element data;
	/*指向下一節點的指標*/
	struct biListNode * nextRef;
}BiListNode;

/*雙向Linked list資料結構*/
typedef struct BiList{
  BiListNode head;
  short (*biListInitRef)(BiListNode first, unsigned size);
  void (*biListDestroyRef)(BiListNode first);
}BiList;

/*雙向Linked list初始化函式*/
short biListInit(BiListNode first, unsigned size);

/*Linked list清理函式*/
void biListDestroy(BiListNode first);

