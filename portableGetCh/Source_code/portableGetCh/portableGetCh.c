/*Unix only*/
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

/*getch()（相容於Standard C(POSIX)的getch()替代方案）*/
int portableGetCh(void)
	{
		/*宣告與定義(Declaration & Definition)*/
		struct termios oldt, newt;
		int ch;

		/*－－－－－－－－－－－－－－－－－－－－－*/

		tcgetattr( STDIN_FILENO, &oldt );
		newt = oldt;
		newt.c_lflag &= ~( ICANON | ECHO );
		tcsetattr( STDIN_FILENO, TCSANOW, &newt );
		ch = getchar();
		tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

		/*－－－－－－－－－－－－－－－－－－－－－*/
		/*傳回內容*/
		return ch;
	}