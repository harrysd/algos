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
1. How to handle line input
#include <sstream>
getline(cin,s);
           istringstream is(s);
           is>>vn;
2. iter value issue.. UNVISITED value was set as 0
*/


typedef long long LL;

using namespace std;
int V;
vector< vector<int> > edges;
vector<int> d_n,d_l,d_p,d_ap;

int ittr,root,cs,critical;

void init()
{   edges.clear();
    d_n.clear();d_l.clear();d_p.clear();d_ap.clear();
    FO(i,0,V+1) {
        vector<int> vv;
        edges.push_back(vv);
        d_n.push_back(0);
        d_l.push_back(0);
        d_ap.push_back(0);
        d_p.push_back(-1);
    }
}

void dfs2(int v)
{   d_n[v] = d_l[v] = ittr++;

    FO(i,0,edges[v].size())
    {   int ngb = edges[v][i];
        //cout<<v << "."<<ngb<<"="<<d_n[v]<<"."<<root<<">>"<<cs<<endl;
        if(d_n[ngb]==0)
        {   d_p[ngb]=v;
            if(v==root) {cs++;}

            dfs2(ngb);

            if(d_l[ngb]>=d_n[v]) d_ap[v]=1; 

            d_l[v] = min(d_l[v],d_l[ngb]);

        }
        else if(ngb!=d_p[v])
           d_l[v] = min(d_l[v],d_n[ngb]);
    }

}

void solve()
{   ittr=1;
    
    FO(i,1,V+1) if(d_n[i]==0){
            root=i;cs=0;
            dfs2(i);
            d_ap[i] = cs>1;
        }

    int sol=0;
    FO(i,1,V+1) sol+= d_ap[i];

    printf("%d\n",sol);
}


int main()
{   int vn,ev;
    string s;
    while(scanf("%d\n",&V)!=EOF)
    {   if(V==0) break;
        init();
        
        while(1)
        {  getline(cin,s);
           istringstream is(s);
           
           while(is>>vn)
           {
            
           }
           
        }

        solve();
    }

    return 0;
}
