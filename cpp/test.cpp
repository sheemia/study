#include<iostream>//cout cin endl resize
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort fill
#include<cstdlib>//abs
#include<map>//map
#include<cctype>//tolower
#include<string>//to_string
 
using namespace std;

int main()
{
    int n;
    string S;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        S+=to_string(i);
    }

    cout<<S[n-1];
    return 0;
}
