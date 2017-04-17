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
int e[101][101];
int sum[101][101];
int s,n;

int main() {
    int t; scanf("%d\n",&t);
    int r1,r2,c1,c2;
    FO(i,0,t)
    {   scanf("%d\n",&s);
        scanf("%d\n",&n);
        ARR0(e);

        FO(k,0,n){
            scanf("%d %d %d %d\n",&r1,&c1,&r2,&c2);
            FO(l,r1-1,r2)
                FO(m,c1-1,c2) 
                    e[l][m] = 1;
            
        }

        FO(k,0,s)
            FO(l,0,s) 
            {   sum[k][l] = e[k][l]==1?0:1;
                if(k>0)         sum[k][l]+=sum[k-1][l];
                if(l>0)         sum[k][l]+=sum[k][l-1];
                if(k>0 && l>0)  sum[k][l]-=sum[k-1][l-1];
            }
        int sol = 0;

        FO(a,0,s)
            FO(b,0,s)
                FO(c,a,s)
                    FO(d,b,s)
                        {   int tmp = sum[c][d];
                            if(a>0)         tmp-=sum[a-1][d];
                            if(b>0)         tmp-=sum[c][b-1];
                            if(a>0 && b>0)  tmp+=sum[a-1][b-1];

                            if(tmp==(c+1-a)*(d+1-b) && sol<tmp)
                                    sol = tmp;
                        }
        
        
        printf("%d\n",sol);

    }

    

}

    