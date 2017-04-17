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
Todos
1. Algo issue check for back edge
2. vectors not cleared
3. Segmentation Fault : due to check for non visited vertex
*/


typedef long long LL;

using namespace std;
int V,v,noe,ittr;
vector<int> d_n,d_l,d_p,d_a;

vector< vector<int> > edges;

typedef struct obj {    int f,t; } apr;

vector<apr> allpairs;

bool comp( apr a, apr b ) {
 if (a.f != b.f) return (a.f<b.f);
 return (a.t<b.t);
}

void init()
{
    edges.clear();
    allpairs.clear();
    d_n.clear();d_l.clear();d_p.clear();
    FO(i,0,V+1){
            vector<int> vv;
            edges.push_back(vv);
            d_n.push_back(0);
            d_l.push_back(0);
            d_p.push_back(-1);
        } 
}

void dfs2(int v)
{   d_n[v] = d_l[v] = ittr++;

    FO(i,0,edges[v].size())
    {   int ng = edges[v][i];

        if(d_n[ng]==0)
        {   d_p[ng]=v;
            dfs2(ng);
            
            if(d_l[ng]>d_n[v]) 
                {   int from = ng>v?v:ng;
                    int to = ng>v?ng:v;
                    allpairs.push_back( (apr) {from,to} );
                }  

            d_l[v] = min(d_l[v],d_l[ng]);
        }
        else if(ng!=d_p[v])
            d_l[v] = min(d_l[v],d_n[ng]);
    }

}

void solve()
{   ittr=1;
    FO(i,0,V) if(d_n[i]==0) 
        {   
            dfs2(i);

        }

    sort(allpairs.begin(), allpairs.end(), comp);

    printf("%d critical links\n",(int)allpairs.size());
    FO(i,0,allpairs.size())
        printf("%d - %d\n",allpairs[i].f,allpairs[i].t);
    printf("\n");
}


int main()
{   
    while(scanf("%d",&V)!=EOF)
    {   init();
        FO(i,0,V)
        {
            scanf("%d (%d)",&v,&noe);
            int ev;
            FO(j,0,noe)
            {  scanf("%d",&ev);
               edges[v].push_back(ev);
            }
        }

        solve();

    }

    return 0;
}
