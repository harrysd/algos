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

LL dp[10005];
LL coins[25];
int ind =0;

void fillcoins()
{   ARR0(coins);   
    FO(i,0,25) if(i*i*i<10000) { coins[ind] = i*i*i; ind++;}
}

int main() {
    int amt;

    fillcoins();
    
    ARR0(dp);
    dp[0]=1;
        
    FO(i,0,ind)
        FO(j,0,10000)
            if(dp[j]>0 && j + coins[i] < 10001)
                dp[j+coins[i]] += dp[j];
    dp[0] = 0;
    
    while(scanf("%d",&amt)!=EOF)  
        printf("%lld\n",dp[amt]/2);
        
    return 0;
}
