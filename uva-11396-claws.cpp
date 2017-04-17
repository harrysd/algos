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
Edges are bidirectionals
init was not in loop
*/


typedef long long LL;
using namespace std;

int v,v1,v2;
vector<int> edges[301];
int color[301];
bool solvable;

void init()
{
  ARR0(color);
  FO(i,0,301) edges[i].clear();  
}

void dfs(int i,int cl)
{
    color[i] = cl;
    FO(j,0,edges[i].size()) 
    {   if(color[edges[i][j]]==cl)
            { solvable=false;return;}
        else if(color[edges[i][j]]==0)
            dfs(edges[i][j],(cl==1?2:1));
    }
}

void solve()
{   solvable =true;
    FO(i,1,v+1) 
        if(solvable && color[i]==0) dfs(i,1);

    if(solvable)
        printf("YES\n");
    else
        printf("NO\n");

}


int main()
{   
    while(scanf("%d",&v)&&v!=0)
    {   init();
        while(scanf("%d %d",&v1,&v2))
        {
            if(v1==0&&v2==0) break;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        solve();
    }

    return 0;
}
