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
int t,nums;
char woken[30];
char lnk[5];
int lw[27],awk[27];
int bmap[27][27];


int main() {
    int zns,lnks;
    
    while(scanf("%d",&zns)!=EOF)
    {   
        ARR0(bmap);ARR0(awk);ARR0(lw);
        scanf("%d",&lnks);scanf("%s",woken);

        FO(i,0,strlen(woken))  awk[woken[i]-'A'] = 1;

        FO(i,0,lnks)    {   scanf("%s",lnk); 
                            bmap[lnk[0]-'A'][lnk[1]-'A'] =1;
                            bmap[lnk[1]-'A'][lnk[0]-'A'] =1;
                        }

        int passes = 0;
        FO(i,0,30)
        {   ARR0(lw);
            
            FO(j,0,27)
                if(!awk[j])
                {   int anow=0;
                    FO(k,0,27) if(bmap[j][k]) anow += awk[k];
                    
                    if(anow>2) lw[j]=1;                
                }

            bool isok =false;
            FO(j,0,27) if(lw[j]) {   isok=true; awk[j]=1; }

            if(!isok) break;
            passes++;
        }

        int tots=0;
        FO(j,0,27) tots+=awk[j];

        if(tots==zns)
            printf("WAKE UP IN, %d, YEARS\n",passes);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
    
    
    
}

// MAPS
// for (map<int,int>::iterator it=denoms.begin(); it!=denoms.end(); ++it)
// 
// if (tmap.find(nxtamt) == tmap.end() ) // To find

