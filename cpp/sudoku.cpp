#include<iostream>
 
using namespace std;

int a[9][9];
int center[9][2]={{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
int dir[9][2]={{0,0},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};//方向数组（牛客上刷过类似的题）

bool check_row()
{
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            for(int l=0;l<9;l++)
            {
                if(l!=k&&a[j][k]==a[j][l]) return false;
            }
        }
    }
    return true;
}

bool check_col()
{
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            for(int l=0;l<9;l++)
            {
                if(l!=k&&a[k][j]==a[l][j]) return false;
            }
        }
    }
    return true;
}

bool check_square()
{
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            for(int l=0;l<9;l++)
            {
                int x1=center[j][0]+dir[k][0];
                int y1=center[j][1]+dir[k][1];
                int x2=center[j][0]+dir[l][0];
                int y2=center[j][1]+dir[l][1];
                if(k!=l&&a[x1][y1]==a[x2][y2]) return false;
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                cin>>a[j][k];
            }
        }

        if(check_row()&&check_col()&&check_square())
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}