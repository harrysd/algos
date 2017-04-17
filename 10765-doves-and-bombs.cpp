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
1. UNVISITED AND FIRST VECTOR both set as 0.
2. Check the vector sorts
3, runtime errors with respect to array sizes
*/


typedef long long LL;

using namespace std;
int n,m;
int dfs_n[10001],dfs_l[10001],av[10001],dfs_p[10001];
int dfsctr,root,rcs;

vector<int> edges[10001];

typedef struct obj {    LL i,ap; 
} apr;

vector<apr> allpairs;

bool comp( apr a, apr b ) {
 if (a.ap != b.ap) return (a.ap>b.ap);
 return (a.i<b.i);
}

void init()
{
    FO(i,0,n) edges[i].clear();
    ARR0(dfs_n);ARR0(dfs_p);
    ARR0(dfs_l);ARR0(av);
    allpairs.clear();
}

void dfs2(int v)
{   dfs_n[v] = dfs_l[v] = dfsctr++;
    
    FO(i,0,edges[v].size())
    {   int ngbr = edges[v][i];
        if(dfs_n[ngbr]==0)
        {
            dfs_p[ngbr] = v;
            if(v==root) rcs++;
            dfs2(ngbr); 

            if(dfs_l[ngbr]>=dfs_n[v]) av[v]++;
            dfs_l[v]=min(dfs_l[v],dfs_l[ngbr]);
      
        }
        else if(ngbr != dfs_p[v])
        {
            dfs_l[v]=min(dfs_l[v],dfs_n[ngbr]);
        }

    }
}

void solve()
{  dfsctr=1; 
   FO(i,0,n) 
    if(dfs_n[i]==0)
        {   root=i;rcs=0;
            dfs2(i);
            av[i]=rcs-1;//(rcs>1);
        }

    FO(i,0,n)
        allpairs.pb((apr) {i,av[i]});
   
    sort(allpairs.begin(), allpairs.end(), comp);

    FO(i,0,m)
        cout << allpairs[i].i << " "<< allpairs[i].ap +1 << endl;

    cout<<endl;
}


int main()
{   int v1,v2;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0) break;

        init();
        while(scanf("%d %d",&v1,&v2))
        {   if(v1==-1&&v2==-1) break;
            edges[v1].push_back(v2); 
            edges[v2].push_back(v1);
        }

        solve();
    }

    return 0;
}
