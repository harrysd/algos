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

double deps[100];

int main() {
    double dwn,loan;
    int dm,d;

    while(scanf("%d %lf %lf %d",&d,&dwn,&loan,&dm),d>0)
    {   
        int last=0,tod;

        double drt,ldrt=0;
        FO(j,0,dm)
        {   scanf("%d %lf",&tod,&drt);
            FO(k,last,tod)
                deps[k] = (1-ldrt);
            last = tod;
            ldrt = drt;    
        }

        FO(k,last,d+1)
            deps[k] = (1-ldrt);

        double cvalue = loan+dwn;

        int sol=0;
        FO(j,0,d+1)
        {   
            cvalue *= deps[j];
            if( loan*(d-j)/d < cvalue)
            {   sol = j;
                break;
            }

        }

        if(sol==1)
            printf("1 month\n");
        else
            printf("%d months\n",sol);
    }
    
    
    
}
