#include<bits/stdc++.h>

using namespace std;

struct Applicant
{
    int registration_number,score;

    Applicant(int rn,int s)
    {
        registration_number=rn;
        score=s;
    }

    Applicant() {}

    bool operator<(const Applicant&a,const Applicant&b)
    {
        if(a.score!=b.score) return a.score>b.score;
        else return a.registration_number<b.registration_number;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,n,m,cnt,line;
    cin>>n>>m;
    cnt=(int)(1.5*m);
    vector<Applicant> v1(n);
    vector<Applicant> v2;
    
    for(int i=0;i<n;i++) cin>>v1[i].registration_number>>v1[i].score;

    sort(v1.begin(),v1.end());
    line=v1[cnt-1].score;

    for(int i=0;i<n;i++)
    {
        if(v1[i].score>=line) v2.push_back(v1[i]);
    }
    
    cnt=v2.size();
    cout<<line<<' '<<cnt<<endl;

    for(int i=0;i<cnt;i++) cout<<v2[i].registration_number<<' '<<v2[i].score<<endl;
    return 0;
}