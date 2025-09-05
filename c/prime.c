#include<stdio.h>

int main()
{
    int flg = 1;
    for(int i = 1; i <=1000; i++)
    {
        flg = 1;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flg = 0;
                break;
            }
        }
        if(flg == 1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}