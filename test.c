#include<stdio.h>

#define BOARD_SIZE 3

int main()
{
    printf("\n  ");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("   %d",i+1);
    }
    printf("\n   ");
    for(int j=0;j<BOARD_SIZE;j++)
    {
        printf("+---");
    }
    printf("+\n");
    for(int k=0;k<BOARD_SIZE;k++)
    {
        printf(" %c",'A'+k);
        for(int m=0;m<BOARD_SIZE;m++)
        {
            printf(" |  ");
        }
        printf(" |\n");
        printf("   ");
        for(int n=0;n<BOARD_SIZE;n++)
        {
            printf("+---");
        }
    printf("+\n");
    }
    return 0;
}