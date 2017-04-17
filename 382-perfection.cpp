#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <math.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Case n=1
and
squares ie 4 etc
*/


typedef long long LL;
using namespace std;
int n;

int main()
{   
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n))
    {   
        if(n==0) break;
        int sum=1;
        
        int max =sqrt(n)+1;
        FO(i,2,max)
            if(n%i==0) {
                sum+=i;
                if(n/i!=i)sum+=n/i;

                }

        if(n==1) sum=0;
        //cout<<n<<"::"<<sum<<endl;

        if(n>9999)
            printf("");
        else if(n>999)
            printf(" ");
        else if(n>99)
            printf("  ");
        else if(n>9)
            printf("   ");
        else
            printf("    ");

        printf("%d  ",n);

        if(n==sum)
            printf("PERFECT\n");
        else if(n<sum)
            printf("ABUNDANT\n");
        else
            printf("DEFICIENT\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
