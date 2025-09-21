#include<iostream>//cout cin endl resize cin.ignore
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort fill
#include<cstdlib>//abs
#include<map>//map
#include<cctype>//tolower toupper
#include<string>//to_string getline
#include<vector>//vector
#include<stack>//stack
#include<queue>//queue
 
using namespace std;

int main()
{
    int a[5];

    for(int i=0;i<5;i++)
    {
        cin>>a[i];
        
        if(a[i]==1)
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}