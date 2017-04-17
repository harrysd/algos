#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;
int td[150][150];

// o(n^4) -- Need to make it O(n^3)
int main() {
    int c,s,t; scanf("%d",&c);   
    
    FO(i,0,c){ 
        ARR0(td);
        scanf("%d",&s);

        FO(j,0,s)
            FO(k,0,s)
                {   scanf("%d",&t);   
                    td[j][k] = t; td[j+s][k+s] = t;
                    td[j][k+s] = t;
                    td[j+s][k] = t;
                }

        FO(j,0,s*2)
            FO(k,0,s*2)
            {    if(j>0) td[j][k] += td[j-1][k];
                 if(k>0) td[j][k] += td[j][k-1];
                 if(j>0&&k>0) td[j][k] -= td[j-1][k-1];
            }

        int maxs = -99999999;


        FO(j,0,s)
            FO(k,0,s)
                FO(l,j,j+s)
                    if(l-j<s)
                        FO(m,k,k+s)
                            if(m-k<s)
                            {   int tsum = -99999999;
                                {
                                    tsum = td[l][m];
                                    if(j>0) tsum-= td[j-1][m];
                                    if(k>0) tsum-= td[l][k-1];
                                    if(j>0&&k>0) tsum+= td[j-1][k-1];
                                }
                                maxs= max(maxs,tsum);
                            }

        
        cout<<maxs<<endl;
    }
}

/*
String inputs
string s;
getline(cin,s); // FULL LINE
s.length();
s+= 'a' //APPEND a char
*/

