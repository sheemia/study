#include<iostream>//cout cin endl
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort
#include<cstdlib>//abs

using namespace std;

bool has4(int x)
{
    while(x>0)
    {
        if(x%10==4) return true;
        else x/=10;
    }
    return false;
}

int main() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%4==0) continue;
        if(has4(i)) continue;
        cout<<i<<endl;
    }
    return 0;
}