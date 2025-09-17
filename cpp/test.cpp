#include<iostream>//cout cin endl
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort
#include<cstdlib>//abs

using namespace std;

int main() 
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='5') cout<<'*';
        else cout<<str[i];
    }
    return 0;
}