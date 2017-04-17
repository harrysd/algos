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

int t,n;
int gr[101][101];
int gt[101][101];

void dfs(int fr,int hidden)
{

    FO(i,0,n)
        if(gr[fr][i] && i!=hidden && gt[hidden][i]==-1)
            {   gt[hidden][i] = 1;
                dfs(i,hidden);
            }

}

int main() {
    scanf("%d",&t);

    FO(i,0,t)
    {   ARR0(gr);ARR1m(gt);
        scanf("%d",&n);

        FO(j,0,n) FO(k,0,n) scanf("%d",&gr[j][k]); 
        
        FO(j,0,n)
            dfs(0,j);
        printf("Case %d:\n",i+1);

        FO(j,0,n)
        {   printf("+");
            FO(l,0,2*n-1) printf("-");
            printf("+\n|");
            
            FO(k,0,n)
            {   
                if(j==k && (gt[0][k]==1||k==0)) printf("Y|");
                else if(j==0 && gt[j][k]==1) printf("Y|");
                else if(j==0 && gt[j][k]==-1) printf("N|");
                else if(gt[j][k]==-1 && gt[0][k]==1) printf("Y|");
                else printf("N|");
            }
            printf("\n");
        }

        printf("+");
        FO(l,0,2*n-1) printf("-");
        printf("+\n");
    }
        

}

// MAPS
// for (map<int,int>::iterator it=denoms.begin(); it!=denoms.end(); ++it)
// 
// if (tmap.find(nxtamt) == tmap.end() ) // To find
