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
int bks[10003];
int moves[10003];

int main() {
    int n,t;
    while(scanf("%d\n",&n),n>0)
    {  
        FO(i,0,n) { 
                    scanf("%d",&bks[i]); 
                    if(i>0) moves[i] = bks[i]>bks[i-1]; 
                  }

        moves[n] = bks[0]>bks[n-1];
        moves[n+1] = bks[1]>bks[0];

        int cycles=0;
        
        FO(i,2,n+2) 
            if(moves[i]!=moves[i-1]) cycles++;

        printf("%d\n",cycles);
    
    }

    return 0;
}
