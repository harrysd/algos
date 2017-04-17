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

char c;
int t;

int main() {
    scanf("%d",&t);    
    scanf("%c", &c);

    FO(i,0,t)
    {  char clean[10001];
       int ind = 0;
       while (scanf("%c", &c), c != '\n') 
       {    if(c>='a'&&c<='z') 
                {   clean[ind] = c;ind++; }
       }

       int isvalid =0;
       FO(k,0,101) if(k*k==ind) { isvalid=k;break; }

       int LC = isvalid;
       int LI = isvalid-1;

       if(isvalid)
       {    
            FO(j,0,isvalid)
                if(isvalid)
                FO(k,0,isvalid)
                {   // g[j][k] == g[L-j][L-k]
                    if(clean[j*LC+k]!=clean[LC*(LI-j)+(LI-k)]) isvalid= 0;
                    // g[k][j] == g[L-k][L-j]
                    if(clean[k*LC+j]!=clean[(LI-k)*LC+(LI-j)]) isvalid= 0;
                }
       }

       
       if(isvalid)
            printf("Case #%d:\n%d\n",i+1,LC);
       else
            printf("Case #%d:\nNo magic :(\n",i+1);
       //FO(i,0,ind) printf("%c",clean[i]);
       //printf("\n");

    }

    return 0;
}
