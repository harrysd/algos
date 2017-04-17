#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <queue>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;


/*
*/

using namespace std;


int main() {
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        LL ln= (n+1)/2;
        LL terms = (1+n)*ln/2;

        LL sol = 3+(terms-3)*2+(terms-2)*2+(terms-1)*2;
        cout<<sol<<endl;
    }
    
    return 0;

}


