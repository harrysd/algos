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


using namespace std;

int w[17000];
int pot[17000];

int main() {
    int n;
    
    while(scanf("%d\n",&n)!=EOF)
    {
        ARR0(w);
        FO(i,0,(1<<n)) scanf("%d\n",&w[i]);

        int mx =0,tmp=0;
        FO(i,0,1<<n)    
        {   
            tmp = 0;
            FO(j,0,n)
                if((i&(1<<j)) == 1<<j)
                    tmp += w[i^(1<<j)];
                else
                    tmp += w[i|(1<<j)];

            pot[i] = tmp;
        }

        FO(i,0,1<<n) 
        {   tmp = pot[i];
            FO(j,0,n)
                if((i&(1<<j)) == 1<<j)
                    mx = max(mx,tmp+pot[i^(1<<j)]);
                else
                    mx = max(mx,tmp+pot[i|(1<<j)]);
        }

        printf("%d\n",mx);

    }




    
}


    