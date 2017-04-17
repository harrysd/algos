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

#define INF 1000111222
#define eps 1e-5

typedef long long LL;
using namespace std;


int t;

int main() {
    scanf("%d",&t);
    int a,b,c;
    FO(i,0,t)
    {
        scanf("%d %d %d\n",&a,&b,&c);
        bool hassol = false;

        for(int x=-100;x<101&&!hassol;x++)
            for(int y=-100;y<101&&!hassol;y++)
                for(int z=-100;z<101 && !hassol;z++)
                    if(x!=y &&y!=z &&x!=z)
                    {
                        if(x+y+z==a && (x*y*z==b) && x*x+y*y+z*z==c)
                            {       hassol = true;
                                    printf("%d %d %d\n",x,y,z);
                                    break;
                            }
                    }

        if(!hassol) printf("No solution.\n");
    }

    return 0;
}
