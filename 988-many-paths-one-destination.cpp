#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <math.h>
#include <queue>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARRINF(A) memset((A), 10000, sizeof((A)))

/*
Issues
1. Understanding issue on how to model the end
2. LL issue as > 2^32
3. Input reading issues
4. Topological sort + simple DP
*/

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;

string s;

void dfs2(int i,const VVI &edges, VI &ans, VL &vis)
{   if(vis[i]) return;
    vis[i]=1;
    FO(j,0,edges[i].size())
    {
        //cout<<i<< " "<<edges[i][j];
        if(!vis[edges[i][j]])
        {   dfs2(edges[i][j],edges,ans,vis);
        }
    }

    ans.pb(i);
    
}   

int main()
{   int t,nxt,cs; 
    string str;
    bool isfirst=true;
    while(scanf("%d\n",&t)!=EOF)
    {
        VVI edges;
        
        FO(i,0,t)
        {   edges.pb(VI());

            scanf("%d",&cs);
            FO(j,0,cs)
                {   int ed; scanf("%d",&ed);
                    edges[i].pb(ed);
                }
                                                           
        }

       
        VI ans; VL vis;
        FO(i,0,t) vis.pb(0);

        FO(i,0,t)
            dfs2(i,edges,ans,vis);

        reverse(ans.begin(),ans.end());
        
        vis.clear();
        FO(i,0,t) vis.pb(0);
        
        vis[0]=1;
        FO(i,0,ans.size())
            FO(j,0,edges[i].size())
            {   //cout<<i << " " << edges[i][j] << " " <<vis[i] << " + " << vis[edges[i][j]] << " " ;
                vis[edges[i][j]] += vis[i];
                //cout<<vis[edges[i][j]]<<endl;
            }

       // FO(i,0,ans.size())
        //    cout<<i << " " << vis[i] << " " << edges[i].size()<< endl;
        LL sol=0;

        FO(i,0,t)
            if(edges[i].size()==0) sol+=vis[i];

        if(!isfirst) printf("\n");
        printf("%lld\n",sol);

        isfirst= false;
        

        
    }

    return 0;
}
