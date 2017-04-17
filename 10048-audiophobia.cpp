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

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Issues
1. ufs init
2. Finding minmax .. i.e. DFS and finding all paths in MST
Made quite a few mistakes
// 
*/


typedef long long LL;

using namespace std;
vector< pair<int, pair<int,int> > > elist;
vector< pair<int,int> > edges[101];
int taken[101];
int c,s,q,csno;
int sol = -1;
bool found;


void init()
{   elist.clear();
    ARR0(taken);
    FO(i,0,101) edges[i].clear();
}

class UF
{
    private: vector<int> p,rank;
    public:
        UF(int N) {
                p.clear();rank.clear();
                rank.assign(N+1,0); 
                p.assign(N+1,0); 
                FO(i,0,N+1) p[i]=i;   
                }
        int find(int i) { return p[i]==i?i:(p[i]= find(p[i]));}
        int issame(int i, int j) { return find(i)==find(j);}
        void unionset(int i, int j)
        {   int pi = find(i),pj = find(j);
            if(pi==pj) return;
            if(rank[pi]>rank[pj]) { p[pj]=pi;}
            else { p[pi]=pj; if(rank[pi]==rank[pj]) rank[pj]++; }
        }
        
};

void dfs(int fr,int final,int tsol)
{   
       taken[fr]=1;

        FO(i,0,edges[fr].size())
        {   int toe =edges[fr][i].first; 
            if(!taken[toe])
                {   tsol = max(tsol,edges[fr][i].second);
                    if(toe==final)
                        {sol=tsol;found=true;return;}
                    else
                        dfs(toe,final,tsol);
                }
        }
    
}

void solve(int cs)
{   
    UF uf(c);
    int st=1;double rl=0.0,tl=0.0;
    FO(i,0,elist.size()){
        pair< double,pair<int,int> > a = elist[i];
        //cout<<a.second.first<< " "<<a.second.second<<endl;

        if(!uf.issame(a.second.first,a.second.second))
        {  
            edges[a.second.first].push_back(make_pair(a.second.second,a.first));
            edges[a.second.second].push_back(make_pair(a.second.first,a.first));
            //cout<<a.second.first<< " "<<a.second.second<<":"<<a.first<<endl;
            uf.unionset(a.second.first,a.second.second);
            
        }
    }

    if(cs>1)printf("\n");
    printf("Case #%d\n",cs);
    ARR0(taken);

    FO(i,0,q)
    {   sol = -1;found=false;
        int from,to;
        scanf("%d %d",&from,&to);
        ARR0(taken);
        dfs(from,to,-1);
        if(found)
            printf("%d\n",sol);
        else
            printf("no path\n");
    }
    
    

}

int main()
{   
    int c1,c2,d;
    while(scanf("%d %d %d",&c,&s,&q))
    {   csno++;
        if(c==0&&s==0&&q==0) break;
        init();

        FO(i,0,s)
        {
            scanf("%d %d %d",&c1,&c2,&d);
            elist.push_back(make_pair(d,make_pair(c1,c2)));

        }

        sort(elist.begin(),elist.end());
        solve(csno);
    }

    return 0;
}
