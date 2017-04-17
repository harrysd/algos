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

typedef long long LL;

using namespace std;
int t,d;
vector<int> vi;

int main() {
    
    while(scanf("%d\n",&t),t!=0)
    {   vi.clear();
        FO(i,0,t) { scanf("%d\n",&d); 
                    vi.pb(d); 
                    vi.pb(1422+(1422-d));
                  }

        sort(vi.begin(),vi.end());
 
        int td = 200;
        FO(i,0,t*2) 
            if(vi[i]<=td) 
                td = vi[i]+200;
            else if(vi[i]>td)
                break;

        if(td>=1422*2)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
            
    }
}

    