#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*

Topological sort
- BFS modified
- Kahans algorithm


*/

#define INF 1000111222
#define eps 1e-5

typedef long long LL;
using namespace std;
int ds;
string d1,d2;
map<string, int> dmap;
map<int,string> nmap;
vector<int> edges[100];
int in[100];

void init()
{
    dmap.clear();
    ARR0(in);
    FO(k,0,100) edges[k].clear();
}

int main()
{   int conns,Case=1;

    while(scanf("%d",&ds)!=EOF)
    {   
        init();
        FO(i,0,ds) 
        {   cin>>d1; dmap[d1] = i;nmap[i] = d1;
        }

        scanf("%d",&conns);

        FO(i,0,conns)
        {
            cin>>d1>>d2;
            in[dmap[d2]]++;
            edges[dmap[d1]].push_back(dmap[d2]);
        } 

        cout << "Case #" << Case++ << ": Dilbert should drink beverages in this order:";
        FO(i,0,ds)
        {   int pos=0;
            while(in[pos]!=0)pos++;

            in[pos]=-1;
            cout<<" "<<nmap[pos];

            FO(k,0,edges[pos].size()) in[edges[pos][k]]--;
        }

        cout<<"."<<endl<<endl;

    }
    return 0;
}