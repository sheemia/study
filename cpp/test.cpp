#include<iostream>//cout cin endl
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort
#include<cstdlib>//abs

using namespace std;

int a[11][11];
int b[11][11];

int main() 
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[j][i]=a[i][j];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<b[i][j]<<' ';
        }
        
        cout<<endl;
    }
    return 0;
}