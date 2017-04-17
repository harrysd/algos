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
#define ARR0(A) memset((A), 0, sizeof((A)))

#define INF 1000111222
#define eps 1e-5

typedef long long LL;
using namespace std;

int fs[21][3];

int main() {
    int m, n = 8, p[8] = {0, 1, 2, 3, 4, 5, 6, 7}; 
    n = 3;
    
    while(scanf("%d %d",&n,&m),!(n==0&&m==0))
    {
        FO(i,0,m) scanf("%d %d %d\n",&fs[i][0],&fs[i][1],&fs[i][2]);
        int sol = 0;
        do{
            //FO(i,0,n) cout<<p[i]<< " "; 
            //  cout<<endl;
            int pf,ps;
            bool isvalid = true;
            FO(i,0,m)
            {
                FO(j,0,8)
                {
                    if(p[j]==fs[i][0]) pf = j;
                    if(p[j]==fs[i][1]) ps = j;
                }

                if(fs[i][2]<0 && abs(pf-ps)<abs(fs[i][2]))  isvalid  =false;
                if(fs[i][2]>0 && abs(pf-ps)>abs(fs[i][2]))  isvalid  =false;
                //if(fs[i][2]==0) isvalid = false; 

                if(!isvalid) break;
            }

            if(isvalid) sol++;
            
          
        }  
        while (next_permutation(p, p + n));

        printf("%d\n",sol);
    }

    return 0;
}
