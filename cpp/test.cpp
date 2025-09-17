#include<iostream>//cout cin endl
#include<cmath>//sqrt fabs
#include<iomanip>//fix setprecision
#include<algorithm>//max sort
#include<cstdlib>//abs

using namespace std;

int a[100002];

int main() 
{
    int n,m,range;
    double average;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        double variance=0;
        cin>>m;
        for(int j=1;j<=m;j++)
        {
            cin>>a[j];
        }

        int maxV=a[1];
        int minV=a[1];
        for(int k=2;k<=m;k++)
        {
            if(a[k]>maxV) maxV=a[k];
            if(a[k]<minV) minV=a[k];
        }
        range=maxV-minV;

        for(int k=1;k<=m;k++)
        {
            sum+=a[k];
        }
        average=sum*1.0/m;

        for(int k=1;k<=m;k++)
        {
            variance+=fabs(a[k]-average)*fabs(a[k]-average);
        }
        variance/=m;

        cout<<range<<' ';
        cout<<fixed<<setprecision(3)<<variance<<endl;
    }
    return 0;
}