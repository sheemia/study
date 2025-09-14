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
    if(n%2!=0) cout<<3*n+1<<endl;
    else cout<<n/2<<endl;
    return 0;
}