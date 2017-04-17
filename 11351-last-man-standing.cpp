#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <string>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Todos
// sol(n,k) = (sol(n-1,k)+k)%n

*/


typedef long long LL;

using namespace std;



int main()
{   int t,n,k,sol,soln;

    scanf("%d",&t);

    FO(i,0,t)
    {   scanf("%d %d",&n,&k);
        sol = 0;soln=0;
        FO(j,1,n+1) 
        {   
            soln = (sol+k)%j; 
            sol=soln;

        }

        printf("Case %d: %d\n",i+1,sol+1);
    }


    return 0;
}
