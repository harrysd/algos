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
LL pr[500];
char ln[10005];
int evs[51][3];

int main() {
    int t,cn;
    double d,d1;
    char s[20];

    bool moretests=true;
    while(moretests)
    {
        ARR0(evs);
        bool isok=true;int ind=0;
        double mincap = 1000000;
        double cap = 0,lk=0, pd=0,avg=0;;
        while(isok)
        {
            scanf("%lf %s",&d,s);
            d1=-1;

            cap -= lk*(d-pd);
            cap -= (d-pd)*avg/100;
            
            //cout<< d << " " << pd << " " <<cap << " : " << mincap<< ":" <<avg<<endl;
            if(s[0]=='F')                   {  scanf("%s %lf\n",s,&d1); avg=d1;}
            else if(s[0]=='G' && s[1]=='a') {  scanf("%s\n",s); mincap = min(mincap,cap); cap=0;}
            else if(s[0]=='L')              {  scanf("\n"); lk++; }
            else if(s[0]=='M')              {  scanf("\n"); lk=0;}
            else if(s[0]=='G' && s[1]=='o') {  scanf("\n"); break; }
            

            if(d1==0) {  moretests = false;break;  }

            pd = d;
        }

        mincap = min(mincap,cap);
        if(moretests) printf("%0.3lf\n", mincap*-1);   

    }

    return 0;
}
