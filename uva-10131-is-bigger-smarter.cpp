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

int wt,iq;

typedef struct obj {
 int w, iq,id;
} block;

bool copr( block a, block b ) {
 if (a.w != b.w) return (a.w<b.w);
 else return (a.iq>b.iq); 
}


vector<block> elephs;
LL dp[1001][2];

int main() {
    
    int id =1;
    while(scanf("%d %d",&wt,&iq)!=EOF)
        {   elephs.pb((block) {wt,iq,id}); id++; }

    sort(elephs.begin(),elephs.end(),copr);

    int len = elephs.size();
    
    FO(i,0,len){
        dp[i][0] = 1;dp[i][1] = -1;
        FO(k,0,i)
        {
            if( elephs[i].w>elephs[k].w && elephs[i].iq<elephs[k].iq ) 
                if(dp[i][0] < dp[k][0]+1)
                    {       dp[i][0] = dp[k][0]+1;
                            dp[i][1] = k;
                    }

        }
    }

    int mx = 0,st=0;
    FO(i,0,len) if(mx<dp[i][0]) {mx=dp[i][0];st=i;}

    printf("%d\n",mx);

    int sol[1000],ind=0;

    while(dp[st][1]!=-1)
        {   sol[ind] =  elephs[st].id; ind++;
            st = dp[st][1];
        }
    
    sol[ind] = elephs[st].id;
    for(int i=ind;i>=0;i--) printf("%d\n",sol[i]);

    return 0;
}
