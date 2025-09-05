#include <stdio.h>

int main()
{
    int person[5];
    int eat=0;

    for(int i=0;i<5;i++)
    {
        scanf("%d",&person[i]);
    }

    for(int i=0;i<5;i++)
    {
        eat+=person[i]%3;
        person[i]/=3;
        person[(i-1+5)%5]+=person[i];
        person[(i+1)%5]+=person[i];
    }

    for(int i=0;i<5;i++)
    {
        printf("%d ",person[i]);
    }

    printf("\n%d",eat);
    return 0;
}