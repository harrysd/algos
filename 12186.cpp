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

/*
Issues
1. Ages to solve
VVV good one
// 
*/


typedef long long LL;
int n;double m;
using namespace std;
vector< vector<int> > edges;
int sol[100002];


void init()
{  edges.clear();

    FO(i,0,n+1) 
    {   vector<int> vi;
        edges.pb(vi);
    }
    ARR0(sol);
}

int trav(int st)
{   
    vector<int> opts;
    opts.clear();

    if(edges[st].size()==0) return 1;

    FO(i,0,edges[st].size())
        opts.pb(trav(edges[st][i]));

    sort(opts.begin(),opts.end());

    int mon=0;
    FO(j,0,opts.size())
    {   double d=(double) j/opts.size();
        //cout<<d<<" " << m<<endl;
        if(d>=m) break;
        mon+=opts[j];
    }

    //cout<<st << " "<<mon<<endl;
    return mon; 
}   

int main()
{   int fr,to;
    while(scanf("%d %lf",&n,&m))
    {   if(n==0&&m==0) break;
        m=m/100;
        init();
        FO(i,1,n+1)
        {   scanf("%d",&to);
            edges[to].pb(i);
        }

        printf("%d\n",trav(0)); 
        //printf("%lf",m); 
        
       
    }   

    return 0;
}
