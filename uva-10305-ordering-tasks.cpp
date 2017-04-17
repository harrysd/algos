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
DFS topsort
ERROR
-- m can be 0
*/

#define INF 1000111222
#define eps 1e-5

typedef long long LL;
using namespace std;
int t,c,v1,v2;
//int gr[101][101];
vector<int> edges[101];
int vis[101];
vector<int> odr;

void init()
{
    ARR0(vis);
    odr.clear();
    FO(i,0,101) edges[i].clear();
}

void dfs2(int v)
{   {   vis[v]=1;
        FO(i,0,edges[v].size())
            if(!vis[edges[v][i]])dfs2(edges[v][i]);

        odr.push_back(v);
    }
    
}

void solve()
{   FO(i,1,t+1) if(!vis[i]) dfs2(i);

    for(int i=odr.size()-1;i>=0;i--) 
    {   if(i!=odr.size()-1) cout<< " ";
        cout<<odr[i];
    }
    cout<<endl;
}

int main()
{
    while(scanf("%d %d",&t,&c)&&!(t==0&&c==0))
    {   init();
        FO(i,0,c) 
        {
            scanf("%d %d",&v1,&v2); 
            edges[v1].push_back(v2);
        }

        solve();
    }

    return 0;
}
