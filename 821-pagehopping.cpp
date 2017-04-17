#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <math.h>
#include <queue>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARRINF(A) memset((A), 10000, sizeof((A)))

/*
Issues
1. ISSUES with name vs vertex

// 
*/


typedef long long LL;
using namespace std;
int mp[101][101];
int ump[101];
string s;

int main()
{   int csno=1;
    while(getline(cin,s))
    {   ARRINF(mp);
        ARR0(ump);
        int nos=0;
        istringstream is(s);
        int a,b,mxv=-1;

        int uind=1;
        while(is>>a>>b)
        {
            if(a==0&&b==0)
            {
                if(nos==0) return 0;
                else break;
            }
            nos++;

            int inda = ump[a];
            if(inda==0)  {ump[a]=uind; inda=uind; uind++;}
           
            int indb = ump[b];
            if(indb==0)  {ump[b]=uind; indb=uind; uind++;}
           
            mp[inda][indb]=1; 
            //cout<<inda<< " "<<a<<" - "<<b<<" - "<<indb<<endl;

        }

        FO(i,1,uind)
            FO(j,1,uind)
                FO(k,1,uind)
                    mp[j][k] = min(mp[j][k],mp[j][i]+mp[i][k]);

        double sm = 0;
        FO(i,1,uind)
            FO(j,1,uind) 
                {   if(i!=j&&mp[i][j]<1000) sm += mp[i][j];
                    //cout<<mp[i][j]<< " ";
                }

        int pages = uind-1;
        //cout<<sm << " " << pages<<endl;
        printf("Case %d: average length between pages = %.3lf clicks\n",csno,sm/(pages*(pages-1)));
        csno++;

    }

    return 0;
}
