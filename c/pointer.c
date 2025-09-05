#include<stdio.h>

int main()
{
    int arr[]={1,2,3,4};
    int len=sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++)
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}