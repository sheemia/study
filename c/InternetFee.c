#include<stdio.h>

int main()
{
    int time = 0;
    float fee = 0.0;
    printf("Please enter the time: ");
    scanf("%d",&time);
    if (time < 0)
    {
        printf("Invalid Input\n");
    }
    else if (time <= 10)
    {
        fee = 30;
    }
    else if (time > 10 && time < 50)
    {
        fee = 30 + (time - 10) * 3;
    }
    else if (time >=  50)
    {
        fee = 150 + (time - 50) * 2.5; 
    }
    printf("The fee is %.1f\n", fee);
    return 0;
}