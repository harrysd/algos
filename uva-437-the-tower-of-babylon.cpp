#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

typedef long long LL;
using namespace std;

int nos;
LL l,b,h;
LL dp[1000][3];

typedef struct obj {
 LL l, w, h; 
} block;

vector<block> allblks;

bool comp( block a, block b ) {
 if (a.l != b.l) return (a.l<b.l);
 else if (a.w!=b.w) return (a.w<b.w); 
 else return (a.h<b.h);
}

int main() {
    int ts=1;
   
    while(scanf("%d",&nos),nos>0)
    {  ARR0(dp); 
       allblks.clear();
       int ind=0;
       // cout<<nos<< endl;
       FO(i,0,nos)
       {    
            scanf("%lld %lld %lld",&l,&b,&h);
            allblks.pb((block) {l,b,h});
            allblks.pb((block) {l,h,b});
            allblks.pb((block) {h,b,l});
            allblks.pb((block) {b,l,h});
            allblks.pb((block) {h,l,b});
            allblks.pb((block) {b,h,l});
            
        }

        sort(allblks.begin(), allblks.end(), comp);

        LL sol = 0;
        FO(i,0,allblks.size())
        {   dp[i][0] = allblks[i].l;dp[i][1] = allblks[i].w;dp[i][2] = allblks[i].h;
            FO(j,0,i)
            {   if((dp[j][0] < allblks[i].l && dp[j][1] < allblks[i].w) || (dp[j][1] < allblks[i].l && dp[j][0] < allblks[i].w))
                {   if(dp[i][2] <  dp[j][2] + allblks[i].h)
                        {
                            dp[i][2] =  dp[j][2] + allblks[i].h;
                            dp[i][0] =  allblks[i].l;
                            dp[i][1] = allblks[i].w;
                            
                        } 
                }

            }
            sol = max(sol,dp[i][2]);
        }
        printf("Case %d: maximum height = %lld\n",ts,sol);
        ts++;
    }
    
    return 0;
}
