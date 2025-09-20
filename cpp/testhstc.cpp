#include<iostream>
 
using namespace std;

long long factorial(int n)//阶乘
{
    long long result=1;

    for(int i=2;i<=n;i++)
    {
        result*=i;
    }

    return result;
}

long long C(int n,int m)//组合数
{
    return factorial(n)/(factorial(m)*factorial(n-m));
}

int main()
{
    int N,M;
    cin>>N>>M;
    int n=N*M/2;
    long long ans=1;

    if(N*M%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            ans+=C(n,i);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            ans+=C(n,i);
        }
        ans*=N*M;
    }

    cout<<ans<<endl;
    return 0;
}