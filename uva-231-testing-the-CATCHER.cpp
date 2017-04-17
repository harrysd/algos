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

int dp[33000];
int in[33000];
int bsrch[33000] ;
int ms;

int binsearch(int els,int val)
{
    int mid = els/2,mx=els,mn=0;

    while(1==1)
    {
        if(bsrch[mid]<val) { mx=mid,mid=(mid+mn)/2; }
        else { mn=mid,mid=(mid+mx)/2; }
        
        if( mx-mn<2 )
            {   if(bsrch[mid]<val) return mn;
                else return mx;
            }
    }
}

int main() {
    int t=1,ind,num;

    while(1==1)
    {   ind=0;
        ARR0(dp);ARR0(in);ARR1m(bsrch);
        while(scanf("%d",&in[ind]),in[ind]!=-1) ind++;

        if(ind==0) break;
        int srch = 0,sind=0;

        FO(i,0,ind+1)
            {
                srch= binsearch(sind,in[i]);

                if(srch==sind && in[i]<= bsrch[srch]) { bsrch[sind+1] = in[i];sind++;}
                else if(in[i]> bsrch[srch]) bsrch[srch] = in[i];

            }

        if(t!=1) printf("\n");
        printf("Test #%d:\n",t);
        printf("  maximum possible interceptions: %d\n",sind);
        t++;
    }
    
    return 0;
}
