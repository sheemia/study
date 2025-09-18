#include<iostream>//cout cin endl
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort fill
#include<cstdlib>//abs
 
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;

    if(s1=="elephant"&&s2=="tiger"||
    s1=="tiger"&&s2=="cat"||
    s1=="cat"&&s2=="mouse"||
    s1=="mouse"&&s2=="elephant")
    {
        cout<<"win";
    }
    else if(s2=="elephant"&&s1=="tiger"||
    s2=="tiger"&&s1=="cat"||
    s2=="cat"&&s1=="mouse"||
    s2=="mouse"&&s1=="elephant")
    {
        cout<<"lose";
    }
    else cout<<"tie";
    return 0;
}