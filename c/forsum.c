#include<stdio.h>

int main()
{
    int an, sn, sum = 0, ansum = 0;
    printf("Please enter the value of an: ");
    scanf("%d",&an);
    printf("\nPlease enter the value of sn: ");
    scanf("%d",&sn);
    for (int i = 1; i <= sn; i++)
    {
        for(int j = 1; j <= an; j++)
        {
            ansum += j;
        }
        sum += ansum;
    }
    printf("The sum of an:%d and sn:%d is %d\n",an, sn, sum);
    return 0;
}