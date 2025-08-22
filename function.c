#include<stdio.h>
int is_prime(int number)
{
    if(number<=1)
    {
        return 0;
    }
    for (int i=2;i<number;i++)
    {
        if(number%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int number;
    printf("Please enter a number: ");
    scanf("%d",&number);
    int ret=is_prime(number);
    if (ret==1)
    {
        printf("%d is a prime number.",number);
    }
    else
    {
        printf("%d is not a prime number.",number);
    }
    return 0;
}