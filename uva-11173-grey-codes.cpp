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
int t;


int main() {
    int n,k;
    scanf("%d",&t);

    FO(i,0,t)
    {   scanf("%d %d\n",&n,&k);
        printf("%d\n",k^(k>>1));
    }

    
}


    