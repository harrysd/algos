#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <queue>

#define Immmm 2147483647
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;


/*
ISSUE
- Took ages to parse properly
- Case with - ie negative numbers
*/

#define pb push_back
#define mp make_pair

using namespace std;

char c;
LL sum=0;
bool isok;

bool read(LL v)
{   LL nm=0,sgn=1;
    while(scanf("%c",&c)!=EOF)
    {   if(c=='(') break;
        else if(c==')') return false;
        else if(c=='-') sgn=-1;
        else if(c>='0'&&c<='9') nm= nm*10 + (c-'0');
    }

    v+=nm*sgn;
    bool ln,rn;
    ln = read(v);

    while(scanf("%c",&c)!=EOF)
        if(c=='(') {rn=read(v);break;}

    if(!ln&&!rn&&sum==v) isok=true;

    while(scanf("%c",&c)!=EOF) if(c==')') break;

    return true;

}

int main() {
    
    while(scanf("%lld",&sum)!=EOF)
    {   isok=false;
        while(scanf("%c",&c)!=EOF)
            if(c=='(')  {read(0);break;}

        if(isok) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;

}


