#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <string>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Todos
// 
1. seg fault .. bvcas of FO(i,1,v+1) instead of FO(i,0,v+1)
2. tarjan : no check to change visited.. and 
FO(i,1,v+1) if(!vis[i]) tarjan(i); 
Instead of
FO(i,1,v+1) if(dn[i]==-1) tarjan(i); 
*/


typedef long long LL;

using namespace std;
int v,e,iter,conn;

vector< vector<int> > edges;
vector<int> vis,dn,dl,order; 


void init()
{
    edges.clear();
    vis.clear();dn.clear();dl.clear();
    
    FO(i,0,v+1){
        vector<int> vi;
        edges.push_back(vi);
        dn.push_back(-1);dl.push_back(-1);
        vis.push_back(0);
    }
}

void tarjan(int f)
{   
    //cout<<f;
    dn[f]=dl[f]=iter++;
    vis[f]=1;
    order.push_back(f);

    FO(i,0,edges[f].size())
    {   int to = edges[f][i];
        
        if(dn[to]==-1) tarjan(to);
        if(vis[to]) dl[f]= min(dl[f],dl[to]);
    }

    //cout<<f << " - "<<dn[f]<<" "<<dl[f]<<endl;
    if(dn[f]==dl[f]) 
    {   conn++;
        while(1)
        {
            int a=order.back();order.pop_back();vis[a]=0;
            //cout<<a << " ";
            if(f==a) break;
        }
        //cout<<endl;
    }

}

void solve()
{   iter=1;
    conn=0;
    FO(i,1,v+1) if(dn[i]==-1) tarjan(i);
        
    if(conn>1)
        printf("0\n");
    else
        printf("1\n");
}

int main()
{   int f,t,w;
    while(scanf("%d %d",&v,&e))
    {
        if(v==0&&e==0)break;

        init();

        FO(i,0,e)
        {
            scanf("%d %d %d",&f,&t,&w);
            //cout<<f<<" " <<t<<endl;
            edges[f].push_back(t);
            if(w==2) edges[t].push_back(f);
        }

        solve();
    }


    return 0;
}
