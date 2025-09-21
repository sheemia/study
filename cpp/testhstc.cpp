#include<bits/stdc++.h>
 
using namespace std;

int main()
{
    int T,n;
    string str;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        int idx=0;
        cin>>n>>str;

        for(int j=0;j<n;j++)
        {
            if(str[j]=='w'&&str[j+1]=='o'&&str[j+2]=='c'&&str[j+3]=='h'&&str[j+4]=='a'&&str[j+5]=='o'&&str[j+6]=='y'&&str[j+7]=='u'&&str[j+8]=='a'&&str[j+9]=='n')
            {
                idx=1;
                break;
            }
        }

        if(idx==1) cout<<"yuanzenni?"<<endl;
        else cout<<"yuanshenqidong!"<<endl;
    }
    return 0;
}