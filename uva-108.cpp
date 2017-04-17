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

int n,num,rowsum,colsum,sqsum;
int sums[100][100];

int main() {
    
    scanf("%d",&n);  
    ARR0(sums);

    FO(i,0,n)
        FO(j,0,n)
        {
            scanf("%d",&sums[i][j]);         
            if(i>0) sums[i][j] += sums[i-1][j];
            if(j>0) sums[i][j] += sums[i][j-1];
            if(i>0&&j>0) sums[i][j] -= sums[i-1][j-1];

        }
    
    int maxsum = -19900000;
    int tempsum = 0;
    FO(i,0,n)
        FO(j,0,n)
            FO(k,i,n)
                FO(l,j,n)
                    {   tempsum = sums[k][l];
                        if(j>0) tempsum -= sums[k][j-1];
                        if(i>0) tempsum -= sums[i-1][l];
                        if(i>0&&j>0) tempsum += sums[i-1][j-1];

                        maxsum = maxsum>tempsum?maxsum:tempsum;
                        

                    }

    cout<<maxsum<<endl;

}


