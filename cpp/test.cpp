#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    if(n%2!=0) cout<<3*n+1<<endl;
    else cout<<n/2<<endl;
    return 0;
}