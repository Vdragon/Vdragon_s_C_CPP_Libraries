#include <stdio.h>
#include <stdlib.h>

void listDirectoryFiles(void)
  {
#if defined(__unix) || defined(_unix__) || defined(unix)
      system("ls --almost-all");
#elif defined(_WIN16) || defined(_WIN32) || defined (_WIN64)
      system("dir");
#else
			system("dir");
#endif
    putchar('\n');
    return;
  }
