#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

extern int add(int,int);

int main(int argc, char *argv[]) 
{
	int a=10;
	int b=20;
	int c=0;
	c=add(a,b);
	printf("%d\n",c);
	return 0;
}
