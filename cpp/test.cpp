#include<iostream>//cout cin endl resize
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort fill
#include<cstdlib>//abs
#include<map>//map
 
using namespace std;

int main()
{
    string N,ans;
    cin>>N;
    for(int i=0;i<N.size();i++)
    {
        if(i!=0&&(N.size()-i)%3==0) cout<<',';
        cout<<N[i];
    }
    
    cout<<endl;
    return 0;
}