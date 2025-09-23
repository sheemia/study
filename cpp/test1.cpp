#include<iostream>
#include<algorithm>

using namespace std;

int main()
{   
    int x,y,z,maxv;
    cin>>x>>y>>z;
    maxv=max({x,y,z});
    while((maxv*3-(x+y+z))%2!=0) maxv++;
    cout<<(maxv*3-(x+y+z))/2<<endl;
    return 0;
}