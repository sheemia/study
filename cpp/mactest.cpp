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
#include<set>//set
 
using namespace std;

int A[10005];
int B[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    for(int i=0;i<2*n;i++)
    {
        if(i<n) cin>>A[i];
        else cin>>B[i-n];
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]<=B[i]) sum+=A[i];
        else sum+=B[i];
    }

    long long ans=sum<=x?sum:x;
    cout<<ans<<endl;
    return 0;
}