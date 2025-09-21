#include<iostream>
 
using namespace std;

int main()
{
    string s;
    cin>>s;

    cout<<s<<", I thought it was ";

    for(int i=s.size()-1;i>=0;i--) cout<<s[i];

    cout<<'.';
    return 0;
}