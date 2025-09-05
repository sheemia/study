#include<stdio.h>
int main()
{
    float a[10]={1.2,7,5,1.8,1.6,0.8,4,1,6,2.2};
    float sum=0;
    float average=0;
    for(int i=0;i<10;i++)
    {
        sum+=a[i];
    }
    average=sum/10;
    printf("The average is:%.1f\n",average);
    for(int i=0;i<10;i++)
    {
        if(a[i]<average)
        {
            printf("%.1f ",a[i]);
        }
    }
    return 0;
}