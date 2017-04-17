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

int cases;
LL mxval=0,val;

int main() {

    while(1)
    {   
        mxval=0;
        scanf("%d",&cases);
        if(cases==0) break;

        LL tmp=0;
        FO(j,0,cases)
        {   scanf("%lld",&val);
            
            tmp = (val+tmp)>0?(val+tmp):0;
            mxval = max(mxval,tmp);

        }

        if(mxval==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %lld.\n",mxval);
        
    }
    
}



/*
    char s[10001];
    scanf("%d",&d);
    scanf("%s", s); // For String
*/

