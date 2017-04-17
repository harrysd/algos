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

int xw,yw,gl,ind,t;
char l[100];
char gd[102][102];
int prc[102][102];
int ans =0;
char w ;

void dfs(int x,int y)
{   if(x<0 || x >ind-1) return;
    if(y<0 || y >gl-1) return;

    if(prc[x][y] || gd[x][y] != w) return;
    
    ans++;
    prc[x][y] = 1;

    dfs(x+1,y); dfs(x-1,y);
    dfs(x,y+1); dfs(x,y-1);
}

int main() {
    scanf("%d",&t);
   
    FO(i,0,t)
    {   gl = 0;ans = 0;
        ARR0(prc);
        scanf("%d %d\n", &xw, &yw);
        ind=0;
        while(gets(l) && strlen(l) > 0)
            {   gl = strlen(l);
                FO(j,0,gl)
                    gd[ind][j] = l[j];
                ind++;
            }

        w = gd[xw-1][yw-1];
        dfs(xw-1,yw-1);

        if(i!=0)printf("\n");
        printf("%d\n",ans);
        
    }
    
    return 0;
}
