#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Bicoloring for each FOREST - yay
*/


typedef long long LL;
using namespace std;

int sol[30002];
void init()
{
    sol[1]=0;
    int tsol;
    FO(i,1,30000)
        sol[i+1] = (sol[i]+2)%(i+1);
}

int main()
{   int t,n;
    scanf("%d",&t);
    init();
    
    FO(i,0,t)
    {   
        scanf("%d",&n);
        
        int turns=0;
        while(1==1)
        {  
            if(sol[n]+1==n) break;
            n = sol[n]+1;
            turns++;
        }
        printf("Case %d: %d %d\n",i+1,turns,sol[n]+1);

    }

    return 0;
}
