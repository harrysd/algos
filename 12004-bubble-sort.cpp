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


/*
issue with variable assignent
*/

using namespace std;

int digits[10];
int main() {

    int t,n;scanf("%d",&t);
    FO(i,0,t)
    {   ARR0(digits);
        scanf("%d",&n);
        FO(j,1,n+1)
        {   int an=j;
            while(an>0)
            {
                digits[an%10]++;
                an=(an-an%10)/10;
            }
        }

        FO(j,0,10) {if(j!=0)printf(" ");printf("%d",digits[j]);}
        printf("\n");

    }
    
    return 0;

}


