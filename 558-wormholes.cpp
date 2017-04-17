#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <queue>

#define Immmm 2147483647
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;


/*
ISSUE
- both solutions : check for edge end conditions
if(ex[j][k]&&vs[j]+adm[j][k]<vs[k])
instead of 
if(ex[j][k]&&vs[j]+adm[j][k]<vs[k]&&vs[j]!=20000000)
similarly other one

RTE
FO(i,0,n+1) vs[i] = Immmm;

*/

#define pb push_back
#define mp make_pair

using namespace std;

int st,en,tno;
int vs[1001];
vector< pair<int,pair<int,int> > > edg;
const int INF = 2000000;

int n,m;

int solve()
{  
    FO(i,0,n+1) vs[i] = Immmm;
    vs[0]=0;

    bool another =true;
    FO(i,0,n-1)
        FO(k,0,edg.size())
          if(vs[edg[k].second.first]!=Immmm)
            vs[edg[k].second.second] = min(vs[edg[k].second.second],edg[k].first+vs[edg[k].second.first]);
          
    
    FO(k,0,edg.size())
       if(vs[edg[k].second.first]!=Immmm&&vs[edg[k].second.second]> edg[k].first+vs[edg[k].second.first])
          {
            cout<<"possible"<<endl;
            return 0;
          }
  

    cout<<"not possible"<<endl;
    return 0;
}


int main() {
    int c; scanf("%d",&c);
    
    int f,t,yr;

    FO(i,0,c)
    {   scanf("%d %d",&n,&m);
        edg.clear();

        FO(j,0,m)
        {
            scanf("%d %d %d",&f,&t,&yr);
            edg.pb(mp(yr,mp(f,t)));
        }
        solve();
    }
    
    return 0;

}


