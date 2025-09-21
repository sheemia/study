#include<iostream>
 
using namespace std;

struct Student
{
    string name;
    int chinese,math,english,total_score;

    Student(string n,int c,int m,int e)//结构体构造函数
    {
        name=n,chinese=c,math=m,english=e,total_score=c+m+e;
    }

    Student()=default;//初始化

    bool operator>(const Student&x)const//结构体符号重载
    {
        if(total_score!=x.total_score) return total_score>x.total_score;
        else if(chinese!=x.chinese) return chinese>x.chinese;
        else if(math!=x.math) return math>x.math;
        else return name<x.name;
    }
}a[1000];

int main()
{
    string n;
    int c,m,e;

    int x;
    cin>>x;

    for(int i=0;i<x;i++)
    {
        cin>>n>>c>>m>>e;
        a[i]=Student(n,c,m,e);
    }

    Student ans=a[0];

    for(int i=1;i<x;i++)
    {
        if(a[i]>ans) ans=a[i];
    }

    cout<<ans.name<<' '<<ans.chinese<<' '<<ans.math<<' '<<ans.english<<' '<<ans.total_score<<endl;
    return 0;
}
