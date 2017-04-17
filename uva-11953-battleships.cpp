#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;
using namespace std;

int t,w;
int grid[101][101];
char row[101];

void dfs(int r,int c,int n)
{   grid[r][c] = n;

    if(r+1<w && ( grid[r+1][c]==1 || grid[r+1][c]==3) ) dfs(r+1,c,n);
    if(r-1>=0 && ( grid[r-1][c]==1 || grid[r-1][c]==3) ) dfs(r-1,c,n);
    if(c+1<w && ( grid[r][c+1]==1 || grid[r][c+1]==3) ) dfs(r,c+1,n);
    if(c-1>=0 && ( grid[r][c-1]==1 || grid[r][c-1]==3) ) dfs(r,c-1,n);

}

int main() {
    scanf("%d",&t);

    FO(i,0,t)
    {   ARR0(grid);

        scanf("%d",&w);
        FO(j,0,w)
        {   scanf("%s",row);
            FO(k,0,strlen(row)) 
                {   if(row[k]=='x')grid[j][k] = 1;
                    else if(row[k]=='.')grid[j][k] = 2;
                    else if(row[k]=='@')grid[j][k] = 3;
                }
        }

        int n=10;
        FO(j,0,w)
            FO(k,0,w)
                if(grid[j][k]==1) { dfs(j,k,n); n++; }

        printf("Case %d: %d\n",i+1,n-10);
    }
  
    
    
}


