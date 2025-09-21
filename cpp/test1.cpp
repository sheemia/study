#include<bits/stdc++.h>

using namespace std;

int a[100001];

int main()
{
    int N,X;
    long long ans=0,price=0;
    cin>>N>>X;

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    sort(a,a+N);

    for(int i=0;i<N;i++)
    {
        if(a[i]-i*X<0) price=0;
        else price=a[i]-i*X;
        ans+=price;
    }

    cout<<ans<<endl;

    return 0;
}