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

int mt[10001][10001];
int tr[10001][10001];
int cols[10001];
using namespace std;
int r,c,e;


int main() {
    while(scanf("%d %d",&r,&c)!=EOF)
    {       ARR0(mt);ARR0(tr);ARR0(cols);

            FO(j,0,r)
            {   scanf("%d ",&e);
                if(e==0) scanf("\n\n");
                else{
                    FO(k,0,e) scanf("%d ",&cols[k]);
                    scanf("\n");
                    FO(k,0,e) scanf("%d ",&mt[j][cols[k]-1]);              
                }
                
            }

            FO(i,0,r) FO(j,0,c) tr[j][i] = mt[i][j];

            printf("%d %d\n",c,r);

            FO(k,0,c)
                {   int ct=0;
                    FO(l,0,r) if(tr[k][l]!=0) ct++;

                    if(ct==0)
                        printf("0\n\n");
                    else
                    {   printf("%d",ct);
                        FO(l,0,r) if(tr[k][l]!=0) printf(" %d",l+1);
                            
                        printf("\n");
                        bool isfirst=true;
                        FO(l,0,r)  if(tr[k][l]!=0) {  if(!isfirst)printf(" ");  isfirst=false; printf("%d",tr[k][l]);}
                             
                        printf("\n");
                    }
                        
                }
    }
    
}

    