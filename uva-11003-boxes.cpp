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

int b,s;

int bs[1001][2];
int dp[7001];

// use printf over cout always
int main() {
    int n,bw,bn;

    while(scanf("%d",&n),n>0)
    {   ARR0(bs);ARR0(dp);
        
        FO(i,0,n) scanf("%d %d",&bs[i][0],&bs[i][1]); 

        for(int i=n-1;i>=0;i--)
        {   
            for(int j=3000;j>=0;j--)
                if(dp[j] && j <= bs[i][1] && j+bs[i][0]<7001)
                    if(dp[j] + 1 > dp[j+bs[i][0]])
                        dp[j+bs[i][0]] = dp[j] + 1;

            dp[bs[i][0]] = max(dp[bs[i][0]],1);

        }
    
        //FO(j,0,6001) if(dp[j]) cout << j << " " << dp[j] << endl;

        int sol = 0;
        FO(j,0,6001) sol = max(sol,dp[j]);

        printf("%d\n",sol);
        
    }
    
        
}

    