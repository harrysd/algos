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
int s,d;

int coords[501][2];
vector< pair<double,pair<int,int> > > edges;


void init()
{   edges.clear();
    ARR0(coords);

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
    UF U = UF(d);

    int ad=0;
    double ans=-1;
    FO(i,0,edges.size())
    {
        pair<double,pair<int,int> > anedge;
        anedge = edges[i];
        if(!U.issame(anedge.second.first,anedge.second.second))
        {   ad++;
            //ans = max(ans,anedge.first);
            U.unionset(anedge.second.first,anedge.second.second);
            if(ad==d-s) {   ans=anedge.first;break;}
        }
    }

    printf("%.2lf\n",ans);

}


int main()
{   
    int t;
    scanf("%d",&t);

    FO(i,0,t)
    {
        init();
        scanf("%d %d",&s,&d);

        FO(j,0,d)
        {   
            scanf("%d %d",&coords[j][0],&coords[j][1]);
            FO(k,0,j)
            {
                double xt = coords[j][0]-coords[k][0];
                double yt = coords[j][1]-coords[k][1];

                double dst = sqrt(xt*xt + yt*yt);
                edges.push_back(make_pair(dst,make_pair(j,k)));
            }
            
        }
        sort(edges.begin(),edges.end());
        solve();
    }

    return 0;
}
