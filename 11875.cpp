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
{   int t; scanf("%d\n",&t);

    FO(i,0,t)
    {
        int n,tmp; scanf("%d\n",&n);
        vector<int> ls;

        FO(j,0,n)
        {   scanf("%d\n",&tmp);
            ls.pb(tmp);
        }

        sort(ls.begin(),ls.end());

        printf("Case %d: %d\n",i+1,ls[(ls.size()-1)/2]);
    }
    

    return 0;
}
