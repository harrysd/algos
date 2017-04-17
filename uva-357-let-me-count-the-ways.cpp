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

int n;
LL ways[300001];
LL recur[300001][5];
int denoms[] = {1,5,10,25,50};

void prefill()
{   n = 300000;
    ARR0(ways);
    ways[0]=1;
    FO(i,0,5)
        FO(j,0,n+1)
            if(ways[j]&&j+denoms[i]<=n)
                ways[j+denoms[i]] += ways[j];
            
}

int main() {
        
        prefill();
        while(scanf("%d",&n)!=EOF)
        {               
            if(ways[n]==1)
                printf("There is only 1 way to produce %d cents change.\n",n);
            else
                printf("There are %lld ways to produce %d cents change.\n",ways[n],n);
        }

}
