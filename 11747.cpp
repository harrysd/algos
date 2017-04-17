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
- Good Observation .. All Edges - MST = removed edges of highest weight from cy
- ISSUE : there can be cycles in a connected graph
// 
*/


typedef long long LL;



using namespace std;
int n,m;
LL total;

int first[25001];
vector< pair<LL,pair<int,int> > > edges;


void init()
{   edges.clear();
    ARR0(first);

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

void solve()
{
    UF U = UF(n);

    int ad=0;
    LL summst=0;
    int ind=0;
    FO(i,0,edges.size())
    {
        pair<double,pair<int,int> > anedge;
        anedge = edges[i];
        if(!U.issame(anedge.second.first,anedge.second.second))
        {   U.unionset(anedge.second.first,anedge.second.second);
            summst+=anedge.first;
            first[i]=1;
            ind++;
        
        }
    }

    

    bool has1=true;
    FO(i,0,edges.size())
    {   if(!first[i])
        {       
              if(!has1)printf(" ");
              printf("%lld",edges[i].first);
              has1=false; 
        }

    }
    
    if(!has1)
        printf("\n");
    else
        printf("forest\n");

}


int main()
{   
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)break;
        init();

        LL w;int fr,to;
        total=0;
        FO(i,0,m)
        {
            scanf("%d %d %lld",&fr,&to,&w);
            total+=w;
            edges.push_back(make_pair(w,make_pair(fr,to)));
        }

        sort(edges.begin(),edges.end());
        solve();
    }

    return 0;
}
