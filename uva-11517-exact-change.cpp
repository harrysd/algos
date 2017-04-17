#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;

int t,amt,cnos,denom;
int coins[101];
int dp[20001][2];

int main() {
    scanf("%d",&t);

    FO(i,0,t)
    {   ARR0(dp);
        scanf("%d %d",&amt,&cnos);

        FO(j,0,cnos) scanf("%d",&coins[j]); 
        sort(coins,coins+cnos);

        int maxamt = 0;
        FO(j,0,cnos) { maxamt = maxamt+coins[j]; if(maxamt>=amt) break; }
        
        dp[0][0]=1;dp[0][1]=-1;
        FO(j,0,cnos)
            FO(k,0,maxamt)
                if(dp[k][0]!=0 && dp[k][1]!=j && k+coins[j]<= maxamt)
                    if(dp[k+coins[j]][0]==0||dp[k+coins[j]][0]>dp[k][0]+1)
                        { dp[k+coins[j]][0] = dp[k][0]+1; dp[k+coins[j]][1] = j;}

        FO(j,amt,maxamt+1)
            if(dp[j][0]!=0)
                {   printf("%d %d\n",j,dp[j][0]-1); break; }
                
        

    }
        

}

// MAPS
// for (map<int,int>::iterator it=denoms.begin(); it!=denoms.end(); ++it)
// 
// if (tmap.find(nxtamt) == tmap.end() ) // To find
