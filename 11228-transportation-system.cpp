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
// 
1. vectors not cleared in init
2. Study UF and Krushals again
3. state calculation... still not to evident.
4. Rounding off done on individual distances and not the sum
*/


typedef long long LL;

using namespace std;
int freec[1001];
int cities[1001][2];
vector< pair<double, pair<int,int> > > elist;

int n,t,r,caseno;


void init()
{   ARR0(cities);
    ARR0(freec);
    elist.clear();
}

class UF
{
    private: vector<int> p,rank;
    public:
        UF(int N) {
                p.clear();rank.clear();
                rank.assign(N,0); 
                p.assign(N,0); 
                FO(i,0,N) p[i]=i;   
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


void solve(int cs)
{   
    UF uf(n);
    int st=1;double rl=0.0,tl=0.0;
    FO(i,0,elist.size()){
        pair< double,pair<int,int> > a = elist[i];
        
        if(!uf.issame(a.second.first,a.second.second))
        {   if(a.first<(double)r)
                rl+= a.first;
            else
                {
                    tl+= a.first;
                    st++;
                }
            
            uf.unionset(a.second.first,a.second.second);
        }
    }

    printf("Case #%d: %d %.0lf %.0lf\n",cs+1,st,rl,tl);
    
}

int main()
{   scanf("%d",&caseno);
    FO(i,0,caseno)
    {   init();
        scanf("%d %d",&n,&r);
        if(n==0&&r==0) break;

        FO(j,0,n)
        {
            scanf("%d %d",&cities[j][0],&cities[j][1]);
            FO(k,0,j)
            {   double xd= cities[j][0] - cities[k][0];
                double yd= cities[j][1] - cities[k][1];
                double wgt= sqrt(xd*xd+yd*yd);
                elist.push_back(make_pair(wgt,make_pair(j,k)));
            }
 
        }
        sort(elist.begin(),elist.end());
        solve(i);
    }


    return 0;
}
