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


int main()
{   int r,n,t=0;
    while(scanf("%d %d",&r,&n))
    {   t++;
        if(r==0&&n==0) break;

        int q = r/n;
        if(r%n==0) q--;
        
        q = q<0?0:q;

        if(q==27&&r%n!=0) q++;

        if(q>27)
            printf("Case %d: impossible\n",t);
        else
            printf("Case %d: %d\n",t,q);
        

    }

    return 0;
}
