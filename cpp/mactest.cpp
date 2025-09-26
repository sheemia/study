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

priority_queue<int> pq;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int op;
        cin>>op;

        switch(op)
        {
            case 1:
            {
                int x;
                cin>>x;
                pq.push(-x);
                break;
            }

            case 2:
            cout<<-pq.top()<<endl;
            break;

            case 3:
            pq.pop();
            break;
        }
    }
    return 0;
}