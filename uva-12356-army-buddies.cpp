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

int sl[100005][2];
int main() {
    int l,b;

    while(scanf("%d %d",&l,&b),l>0&&b>0)
    {   ARR0(sl);
        FO(i,1,l+1) { sl[i][0] = i-1; sl[i][1] = i+1;}
        sl[1][0] = -1; sl[l][1] = -1;

        int lsol=0,rsol=0,ts,te;
        FO(i,0,b)
        {   scanf("%d %d",&ts,&te);

            sl[sl[te][1]][0] = sl[ts][0];
            sl[sl[ts][0]][1] = sl[te][1];

            if(sl[ts][0]!=-1) printf("%d ",sl[ts][0]);
            else printf("* ");

            if(sl[te][1]!=-1) printf("%d\n",sl[te][1]);
            else printf("*\n");
            
        }
        printf("-\n"); 
    }


        
    return 0;
}
