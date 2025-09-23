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

multiset<int> s;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int n;
        cin>>n;

        switch(n)
        {
            case 1:
            {
                int x;
                cin>>x;
                s.insert(x);
                break;
            }

            case 2:
            {
                int x;
                cin>>x;
                if(s.count(x)!=0) s.erase(s.find(x));
                break;
            }

            case 3:
            {
                int x;
                cin>>x;
                cout<<s.count(x)<<endl;
                break;
            }

            case 4:
            cout<<s.size()<<endl;
            break;

            case 5:
            {
                int x;
                cin>>x;
                auto it=s.lower_bound(x);
                if(it==s.begin()) cout<<-1<<endl;
                else{
                    it--;
                    cout<<*it<<endl;
                }
                break;
            }

            case 6:
            {
                int x;
                cin>>x;
                auto it=s.upper_bound(x);
                if(it==s.end()) cout<<-1<<endl;
                else{
                    cout<<*it<<endl;
                }
                break;
            }
        }
    }
    return 0;
}