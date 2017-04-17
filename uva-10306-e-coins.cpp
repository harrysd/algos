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
int t,m,s,tp,td;
int coins[41][2];
int dp[301][301];

int main() {
    scanf("%d",&t);
    FO(i,0,t)
    {   ARR0(dp);
        scanf("%d %d",&m,&s);

        FO(j,0,m) { scanf("%d %d",&tp,&td); coins[j][0]=tp; coins[j][1]=td;}
        
        dp[0][0] = 1;
        FO(j,0,m)
            FO(k,0,s+1)
                FO(l,0,s+1)
                    {
                        if(dp[k][l]!=0)
                            {   int newc1 = k+coins[j][0], newc2 =l+coins[j][1];
                                if( newc1<=s && newc2<=s )
                                    if(dp[newc1][newc2]==0  || (dp[newc1][newc2] > dp[k][l] + 1))
                                         dp[newc1][newc2] = dp[k][l] + 1;
                                    
                            }
                    }

        int min = 1000000;
        FO(k,0,s+1)
        {   FO(l,0,s+1)
                   if(k*k+l*l==s*s && dp[k][l]!=0)
                        min = min>(dp[k][l]-1)?(dp[k][l]-1):min;  
        }

        if(min==1000000)
            printf("not possible\n");
        else
            printf("%d\n",min); 
    }


}
