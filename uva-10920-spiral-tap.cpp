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

typedef long long LL;
using namespace std;


int ind =0;
int r[] = {0,1,1,0,-1,-1,-1,0,1};
int c[] = {0,0,-1,-1,-1,0,1,1,1};

int main() {
    LL g,n,mid;

    while(scanf("%lld %lld\n",&g,&n),g>0)
    {   mid = (g+1)/2;

        if(n<=9)
            printf("Line = %lld, column = %lld.\n",mid+r[n-1],mid+c[n-1]);
        else
        {   LL sqno = 3;
            LL rapp,capp;
            while(sqno*sqno<n) sqno = sqno+2;
            LL lt = n - (sqno-2)*(sqno-2);

            if(lt<=sqno) 
                { rapp = sqno;
                  capp = sqno-lt;
                }
            else if(lt <= 2*(sqno-1)) 
                {
                    rapp = 2*(sqno-1)+1-lt;
                    capp = 1;
                }
            else if(lt <= 3*(sqno-1))
                {   rapp = 1;
                    capp = lt+1-(sqno-1)*2;
                }
            else
                {   capp = sqno;
                    rapp = lt + 1 - 3*(sqno-1);
                }   


            LL base = (g-sqno)/2;
            //cout<<sqno <<" : " << lt<< " " <<base << ": "<<rapp<< " "<<capp<<endl;
            printf("Line = %lld, column = %lld.\n",base+rapp,base+capp);

        }
    }

    return 0;
}
