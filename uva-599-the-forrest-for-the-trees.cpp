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
int e[26][26];
int v[26];
int vis[26];
char aln[100];
int trees,acorns;
int acycle = 0,depth;


void dfs(int i)
{
    if(vis[i]==1) {acycle=1;return;}
    vis[i]++;

    depth++;
    FO(k,0,26) if(e[i][k]) { e[k][i]=0;dfs(k);}
}

int main() {
    int t; scanf("%d\n",&t);
    
    FO(i,0,t)
    {   
        ARR0(e);ARR0(v);ARR0(vis);
        trees=0,acorns=0;
        while(gets(aln) && aln[0] != '*') 
        {   e[aln[1]-'A'][aln[3]-'A'] = 1;
            e[aln[3]-'A'][aln[1]-'A'] = 1;
        }

        gets(aln);
        FO(j,0,strlen(aln)) {v[aln[j]-'A']=1;j++;}

        FO(j,0,26)
            if(v[j] && vis[j]==0) 
                {   acycle = 0,depth=0;
                    dfs(j);
                    if(!acycle) 
                    { if(depth==1)
                            acorns++;
                      else
                            trees++;
                    }
                }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
    }

    

}

    