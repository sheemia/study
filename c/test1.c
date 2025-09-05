#include <stdio.h>

int main()
{
    int weight;
    int money=8;
    char urgent;
    
    scanf("%d %c",&weight,&urgent);
    
    if(weight>1000)
    {
        if(weight%500==0)
        {
            money+=(weight-1000)/500*4;
        }
        else
        {
            money+=((weight-1000)/500+1)*4;
        }
    }
    
    if(urgent=='y')
    {
        money+=5;
    }

    printf("%d",money);
    
    return 0;
}