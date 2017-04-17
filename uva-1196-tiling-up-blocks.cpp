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

int nos,n1,n2;
LL l,b,h;


typedef struct obj {
 LL n1, n2;
} block;

bool copr( block a, block b ) {
 if (a.n1 != b.n1) return (a.n1<b.n1);
 else return (a.n2<b.n2); 
}


vector<block> allblks;
LL dp[10001][2];

int main() {
    
    while(scanf("%d",&nos),nos>0)
    {   allblks.clear();
        ARR0(dp);

        FO(i,0,nos)
            {   scanf("%d %d",&n1,&n2); allblks.pb( (block){n1,n2} );   }

        sort(allblks.begin(),allblks.end(),copr);

        int mn,mid,mno=0,mx;LL sol=0;
        dp[0][0] = allblks[0].n1; dp[0][1] = allblks[0].n2;

        for(int i=nos-1;i>=0;i--)
        {   mid = mno/2;mx =mno;mn=0;

            dp[i][0] = 1; dp[i][1] = 1;
            for(int k=nos-1;k>i;k--)
            {
                if(allblks[i].n1 <= allblks[k].n1 && allblks[i].n2 <= allblks[k].n2)
                    { dp[i][0] = max(dp[i][0], dp[k][0] +1 ); }

                if(allblks[i].n1 > allblks[k].n1 && allblks[i].n2 > allblks[k].n2)
                    { dp[i][1] = max(dp[i][1], dp[k][1] +1 ); }
            }
            sol = max(sol,dp[i][0]+dp[i][1]-1);

        }

        printf("%lld\n",sol);
    }

    printf("*\n");
    return 0;
}
