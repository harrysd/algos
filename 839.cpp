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
1. first line : input parsing ..
scanf("%d\n",&t); instead of scanf("%d",&t); 
2 RTE
    ind++;
    if(ind>=aa.size()) 
            {    //sol=false;
                 return 0;
            }
3. If w=0 for both and no successive trees its ok too!
// 
*/


typedef long long LL;
int n;double m;
using namespace std;
vector<int> aa,ba,ca,da;
bool sol;
int ind;

int solve()
{   if(!sol) return 0;
    ind++;
    if(ind>=aa.size()) 
            {    //sol=false;
                 return 0;
            }

    int ci=ind;
    int w1=aa[ci],w2=ca[ci];
    
    if(aa[ci]==0) w1 = solve();
    if(ca[ci]==0) w2 = solve();

    if(w1*ba[ci]!=w2*da[ci]) sol=false;

    return w1+w2;
}

int main()
{   int fr,to;
    int a,b,c,d;
    int t; scanf("%d\n",&t);
    string str; getline(cin,str);

    FO(i,0,t)
    {   sol=true;
        aa.clear();
        ba.clear();
        ca.clear();
        da.clear();

        while(getline(cin,str))
        {
            if(str.length()==0) break;
            istringstream is(str);
            is>>a>>b>>c>>d;
            
            aa.pb(a);ba.pb(b);ca.pb(c);da.pb(d);
        }

        ind=-1;
        
        if(i!=0) printf("\n");

        solve();
        if(sol)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
