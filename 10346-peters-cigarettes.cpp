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
== issue
*/


typedef long long LL;
using namespace std;
int n,k;

int main()
{   
    
    while(scanf("%d %d",&n,&k)!=EOF)
    {   int sol=0;
        while(n>=k)
        {   sol += k*(n/k);
            n=n%k+n/k;
        }
        sol+=n;
        cout<<sol<<endl;
    }
    
    return 0;
}
