#include<iostream>//cout cin endl resize cin.ignore
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort fill next_permutation
#include<cstdlib>//abs
#include<map>//map
#include<cctype>//tolower toupper
#include<string>//to_string getline
#include<vector>//vector
#include<stack>//stack
#include<queue>//queue
 
using namespace std;

int u[50001];
int v[50001];

int main()
{
    int N,ans=0,j=0;
    cin>>N;

    for(int i=0;i<N;i++) cin>>u[i];
    for(int i=0;i<N;i++) cin>>v[i];

    sort(u,u+N);
    sort(v,v+N);

    for(int i=0;i<N;i++)
    {
        if(u[i]<v[j]) continue;
        else
        {
            ans++;
            j++;
        }
    }

    cout<<ans<<endl;
    return 0;
}