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


int ind =0;
LL pr[500];
char ln[10005];

int main() {
    int t,cn;
    scanf("%d",&t);

    FO(i,0,t)
    {   ARR0(pr);
        char c;
        scanf("%d\n",&cn);
        double amt;

        FO(j,0,cn) 
            { scanf("%c %lf\n",&c,&amt);
              pr[(int) c] = amt;
            }

        amt=0;
        scanf("%d\n",&cn);
        FO(j,0,cn)
            {   
                while(scanf("%c",&c),c!='\n')
                    amt+= pr[(int) c];
                //cout<< ln<< amt <<endl;
            }

        printf("%0.2lf$\n", amt/100);        
    
    }    
    return 0;
}
