#include<stdio.h>

int main()
{
    int an, sn, sum = 0, ansum = 0, i = 1, j = 1;
    printf("Please enter the value of an: ");
    scanf("%d",&an);
    printf("\nPlease enter the value of sn: ");
    scanf("%d",&sn);
    while (i <= sn)
    {
        while (j <= an)
        {
            ansum += j;
            j++;
            sum =+ ansum;
            i++;
        }
    }
    printf("The sum of an:%d and sn:%d is %d\n",an, sn, sum);
    return 0;
}