#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;
using namespace std;


int t, n, fr, to, sendto;
int adj[50002],visit[50002];
int cycle = -1;
vector<int> cvs;

int dfs(int i)
{   
    if(visit[i]==-1) { cycle = i; return 0;}
    if(visit[i]!=0) return visit[i];

    visit[i] = -1;
    visit[i] = 1+dfs(adj[i]);
    
    if(cycle==i) 
        { cycle = -1;
          FO(j,0,cvs.size()) visit[cvs[j]] = visit[i];
        }

    if(cycle!=-1) cvs.pb(i);

    return visit[i];
}

int main() {
    scanf("%d",&t);    

    FO(i,0,t)
    {   ARR0(visit);ARR0(adj);
        
        scanf("%d",&n);

        FO(j,0,n)
            {   scanf("%d %d",&fr,&to);
                adj[fr] = to;
            }

        FO(i,1,n+1)  
            {   cvs.clear();
                dfs(i);
            }

        int max=0,sendto=0;
        FO(i,1,n+1)
            if(visit[i]>max) { max = visit[i]; sendto = i; }

        printf("Case %d: %d\n",i+1,sendto);
    }

    return 0;
}
