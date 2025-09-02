#include <stdio.h>

int main()
{
    int person[5];
    for(int i=0;i<5,i++)
    {
        scanf("%d",person[i]);
    }
    for(int i=0;i<5;i++)
    {
        eat+=person[i]%3;
        person[i]/=3;
        if(i==0)
        {
            person[4]+=person[0];
            person[1]+=person[0];
        }
        else if(i==4)
        {
            person[3]+=person[4];
            person[0]+=person[4];
        }
        else
        {
            person[i-1]+=person[i];
            person[i+1]+=person[i];
        }
    }
    int person[5];
    for(int i=0;i<5;i++)
    {
        printf("%d ",person[i]);
    }
    printf("\n%d",eat);
    return 0;
}