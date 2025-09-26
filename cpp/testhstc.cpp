#include<iostream>
#include<vector>
 
using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k,u=0,U,v=1,ans=0;
    cin>>n>>k;

    if(n<k)
    {
        cout<<"impossible";
        return 0;
    }

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    while(v<=n)
    {
        if(v!=1)
        {
            u=U;
            U=gcd(u,a[v-1]);
            v+=gcd(u,a[v-1]);
            ans++;
        }
        else
        {
            v+=a[0];
            U=a[0];
            ans++;
        }

        if(v>k)
        {
            cout<<"impossible";
            break;
        }
        else if(v==k)
        {
            cout<<ans<<endl;
            break;
        }
    }
    return 0;
}