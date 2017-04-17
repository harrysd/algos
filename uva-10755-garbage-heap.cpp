#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;

int cases,x,y,z;
LL pp[21][21][21];

int main() {
    scanf("%d",&cases);
    LL sc,tmp;
    FO(i,0,cases)
    {   LL mxs = 0,mxcell=0;
        ARR0(pp);
        scanf("%d %d %d",&x,&y,&z);


        FO(a,0,x)
            FO(b,0,y)
                FO(c,0,z)
                {   
                    scanf("%lld",&tmp);
                    if(a==0&&b==0&&c==0)
                        mxcell =  tmp;
                    pp[a][b][c]=tmp;
                    mxcell = mxcell<tmp?tmp:mxcell;
                    if(b>0) pp[a][b][c] += pp[a][b-1][c];
                    if(c>0) pp[a][b][c] += pp[a][b][c-1];
                    if(b>0&&c>0) pp[a][b][c] -= pp[a][b-1][c-1];
                }

        FO(j,0,y)
            FO(k,0,z)
                FO(l,j,y)
                    FO(m,k,z)
                        {   
                            LL mxin=0,tmp;
                            FO(n,0,x)
                            {
                                tmp = pp[n][l][m];
                                if(j>0) tmp -= pp[n][j-1][m]; 
                                if(k>0) tmp -= pp[n][l][k-1]; 
                                if(k>0&&j>0) tmp += pp[n][j-1][k-1];  
                                
                                mxin = (tmp+mxin>0)?tmp+mxin:0;
                                mxs = mxs<mxin?mxin:mxs;
                            }
                         }

        if(mxs==0)
            mxs = mxcell;
        if(i!=0)
            printf("\n");
        printf("%lld\n",mxs);
    }
    
    
}



/*
    char s[10001];
    scanf("%d",&d);
    scanf("%s", s); // For String
*/

