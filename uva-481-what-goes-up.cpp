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

int n,k;
LL seq[500000];
LL sol[500000];
LL slist[500000][2];
LL res[500000];

int binsearch(int ind,int slmax)
{
    int mid,mn=0, mx =slmax;
    mid = (mn+mx)/2;

   
    while(1==1)
    {   if(slist[mid][0]==seq[ind]) return mid;
    
        if(slist[mid][0]>seq[ind]) { mx=mid; mid = (mn + mid)/2;  }
        else  { mn=mid; mid = (mx + mid)/2;  }

        if(mx-mn<2) 
            {
                if(slist[mx][0]<=seq[ind]) return mx;
                return mn;
            }

    }

}

int main() {

    int ind =0 ;
    ARR0(seq);ARR1m(res);
    while(scanf("%lld", &seq[ind]) !=EOF)
        ind++;

    slist[0][0] = seq[0]; slist[0][1] = 0;
    int sli = 1,anind;

    FO(i,1,ind)
    {  
        anind = binsearch(i,sli-1);

        bool added=false;

        if(seq[i]==slist[anind][0] && anind==sli-1)
            {   slist[anind][0] = seq[i]; 
                slist[anind][1] = i;
                added =true; 
            }
        else if(seq[i]<slist[anind][0])
        {
            slist[anind][0] = seq[i]; 
            slist[anind][1] = i; 
            added = true;
        }
        else if(seq[i]!=slist[anind][0])
            {
                slist[anind+1][0] = seq[i]; 
                slist[anind+1][1] = i; 
                added = true;
                anind++;

                if(anind==sli) sli++;
                
            }
        
        if(added && anind>0)
            res[i] = slist[anind-1][1];
        
    }

    int maxind = -1;

    FO(i,0,ind)
        if(slist[sli-1][0] == seq[ind-(1+i)])   {maxind = ind-(1+i); break;}

   
    int solind = 0;
    while(1==1)
    {   
        sol[solind] = seq[maxind]; 
        solind++;
        if(res[maxind]==-1) break;
        
        maxind = res[maxind];
    }

    printf("%d\n-\n",solind);
    FO(i,0,solind)
        printf("%lld\n",sol[solind-(1+i)]);
       
    return 0;
}
