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

char str[21];
int t;
char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
char mirr[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 O";
char c1,c2;

bool ispal()
{   int ln = strlen(str);

    FO(k,0,ln)
        {   c1 = str[k]; c2 = str[ln-(1+k)];
            c1 = c1=='0'?'O':c1;
            c2 = c2=='0'?'O':c2;

            if(c1!=c2)  return false;
        }
    return true;
}

bool ismirr()
{   int ln = strlen(str);
    
    FO(k,0,ln)
    {   c1 = str[k]; c2 = str[ln-(1+k)];
        c1 = c1=='0'?'O':c1;
        c2 = c2=='0'?'O':c2;

        char mc = '-';
        FO(i,0,strlen(alph)) if(alph[i]==c1) mc = mirr[i];
      
        if(c2!=mc) return false;
    }
    return true;
}

int main() {

    while(scanf("%s",str)!=EOF)
    {   bool ism = ismirr(), isp = ispal();

        if(ism && isp)
            printf("%s -- is a mirrored palindrome.\n",str);
        else if(!ism && isp)
            printf("%s -- is a regular palindrome.\n",str);
        else if(ism && !isp)
            printf("%s -- is a mirrored string.\n",str);
        else 
            printf("%s -- is not a palindrome.\n",str);

        printf("\n");
    }

    return 0;
}
