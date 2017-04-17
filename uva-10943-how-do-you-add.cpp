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

int n,k;
LL dp[101][101];


int main() {

    while(scanf("%d %d",&n,&k),n!=0 && k!=0)
    {   
        ARR0(dp);
        
        FO(a,0,n+1) dp[a][1] = 1;

        FO(a,2,k+1)
            FO(b,0,n+1)
                FO(d,0,b+1)
                    dp[b][a] = ( dp[b][a] + dp[b-d][a-1] )%1000000;
                       

        printf("%lld\n",dp[n][k]);

    }

    return 0;
}
