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
1. scheap value not initialized
2. wrong variable used
3. incremented indes used amap[first[ind][1]][first[ind][0]]=1; instead of amap[first[j][1]][first[j][0]]=1;
4. IMP CHECK FOR CONNS MST conns = v-1
5. BIG BUG !! edges can be directed** i.e 1-2 and 2-1 can have different weights
// 
*/


typedef long long LL;

using namespace std;
int n,m;

int amap[101][101];
int first[101][3];
vector< pair<double,pair<int,int> > > edges;


void init()
{   edges.clear();
     ARR0(amap);
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
    double ans=-1;
    int ind=0,cheapest=0,scheap=0;
    FO(i,0,edges.size())
    {
        pair<double,pair<int,int> > anedge;
        anedge = edges[i];
        if(!U.issame(anedge.second.first,anedge.second.second))
        {   U.unionset(anedge.second.first,anedge.second.second);
            first[ind][0]=anedge.second.first;
            first[ind][1]=anedge.second.second;
            first[ind][2]=i;
            cheapest+=anedge.first;
            ind++;
       
        }
    }

    int scheapsol=999999,conns=0;
    FO(j,0,ind)
    {   ARR0(amap);
        amap[first[j][0]][first[j][1]]=1;
        //amap[first[j][1]][first[j][0]]=1;
        //cout<<amap[first[j][0]][first[j][1]] << " " <<amap[first[j][1]][first[j][0]] <<endl;
        U = UF(n);
        scheap=0,conns=0;
        FO(i,0,edges.size())
        {
            pair<double,pair<int,int> > anedge;
            anedge = edges[i];
            if(amap[anedge.second.first][anedge.second.second]==0)
            //if(first[j][2]!=i)
            if(!U.issame(anedge.second.first,anedge.second.second))
            {   U.unionset(anedge.second.first,anedge.second.second);
                scheap+=anedge.first;
                conns++;
            }
        }

        //cout<<first[j][0]<<","<<first[j][1]<< " "<<ind << "---"<<conns<< " " << scheap<<endl;
        if(conns==n-1) //important check
            scheapsol =min(scheapsol,scheap);

    }


    printf("%d %d\n",cheapest,scheapsol);

}


int main()
{   
    int t;
    int fr,to,cost;
    scanf("%d",&t);

    FO(i,0,t)
    {
        init();
        scanf("%d %d",&n,&m);
        
        FO(j,0,m)
        {   
            scanf("%d %d %d",&fr,&to,&cost);
            edges.push_back(make_pair(cost,make_pair(fr,to)));
                   
        }
        sort(edges.begin(),edges.end());
        solve();
    }

    return 0;
}
