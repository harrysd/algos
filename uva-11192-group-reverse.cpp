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
char s[101];
char r[101];

int main() {
    int d,g;

    while(scanf("%d",&d),d!=0)
    {  
      
      scanf("%s\n",s);

      g = strlen(s)/d;
      for(int i=0;i<strlen(s);i=i+g)
      {    FO(j,0,g)
             r[i+g-(1+j)] = s[i+j];
      }
      
      FO(i,0,strlen(s)) printf("%c",r[i]);
      printf("\n");
    
    }      
}

    