#include <stdio.h>

#include "List_directory_files/listDirectoryFiles.h"

int main(void)
  {
    /*提示訊息*/
    printf("目前console的工作目錄如下：\n");
    listDirectoryFiles();

    /*done*/
    return 0;
  }
