#include <stdio.h>
#include <stdlib.h>
#include "../Project_specific_configuration/System_category.h"


void listDirectoryFiles(void)
  {
    if(SYSTEM_CATEGORY == 1){
      system("ls -a");
    }else{
      system("dir");
    }
    putchar('\n');
    return;
  }
