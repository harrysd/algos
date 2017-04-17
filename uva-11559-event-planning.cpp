#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;

int n,b,h,w;

int main() {
    int rent,vacancy;
    while(scanf("%d %d %d %d",&n,&b,&h,&w)!= EOF)
    {   
        int mincost = 1000004;
        FO(i,0,h)
        {
            scanf("%d",&rent);
            
            FO(k,0,w)
            {   scanf("%d",&vacancy);
                if(vacancy>=n)
                    mincost = min(mincost,rent*n);
            }

        }
        
        if(mincost<=b)
            printf("%d\n",mincost);
        else
            printf("stay home\n");
    }
    
}
