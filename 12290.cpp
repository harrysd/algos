#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*

*/


typedef long long LL;
using namespace std;


int main()
{   int n,m,k;

    while(scanf("%d %d %d", &n,&m,&k)!=EOF)
    {
        if(n==0&&m==0&&k==0)break;
        int which=1,found=0,sol=0;
        bool pos=true,success=false;

        FO(i,1,100001)
        {   
            bool isok=false;
            if(i%7==0)
                isok=true;
            else
            {   int j=i;
                while(j>0)
                {    int rm = j%10;
                     if(rm==7) {    isok=true; break;   }
                     j=j/10;
                }
            }

            if(isok&&which==m)
                found++;

            if(found==k) { sol=i;success=true;break;}

            if(which==n) pos=false;
            else if(which==1) pos=true;

            if(pos)
                which++;
            else
                which--;
        }
        

        if(success)
            printf("%d\n",sol);
        else
            printf("-1\n");
    }
    

    return 0;
}
