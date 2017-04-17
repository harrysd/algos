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

typedef long long LL;
using namespace std;

int l,n;
int np[51];
int dp[51][51];


int main() {

    while(scanf("%d",&l),l!=0)
    {   scanf("%d",&n);
        FO(i,1,n+1) scanf("%d",&np[i]);
        np[0]=0; np[n+1] = l;

        ARR0(dp);

        FO(i,2,n+2) 
            FO(j,0,n+2-i)
                {   
                    FO(k,1,i)
                    {   if(dp[j][j+i]==0)
                            dp[j][j+i] = dp[j][j+k]+dp[j+k][j+i];
                        else if(dp[j][j+i]> dp[j][j+k]+dp[j+k][j+i])
                            dp[j][j+i] = dp[j][j+k]+dp[j+k][j+i];
                    }
                    
                    dp[j][j+i] += (np[j+i] - np[j]);
                }

        printf("The minimum cutting is %d.\n",dp[0][n+1]);

    }

    return 0;
}
