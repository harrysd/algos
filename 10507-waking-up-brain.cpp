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

/*
Input conditions ... handling blank line

Case of all areas awake from start not handled.
*/

typedef long long LL;
using namespace std;

int areas,conn;
char s[3];
int arr[26][26];
int mp[26];
int isactive[26];

vector<int> newact;

int addtomp(char c)
{   int last = 0;
    FO(i,0,26) 
        if(mp[i]==0) 
            {   last=i;
                break;
            }
        else{
                if(mp[i]==(int)c) return i;
            }
    mp[last]=(int)c;
    return last;
}

void init()
{
    ARR0(mp);
    ARR0(arr);
    ARR0(isactive);
    newact.clear();
}

void solve()
{
    bool doit =true;
    int yrs=0;
    while(doit)
    {
        FO(k,0,26)
        if(!isactive[k])
            { int tactive=0;
                FO(j,0,26)
                    if(arr[k][j]&&isactive[j]) 
                        tactive++;

                if(tactive>2)newact.push_back(k);

            }

        if(newact.size()==0)
            break;
        yrs++;

        FO(k,0,newact.size()) 
        {   isactive[newact[k]]=1;
        }

        newact.clear();
    }

    bool iswoken =true;

    FO(k,0,areas) if(!isactive[k]) iswoken=false;

    if(!iswoken)
        printf("THIS BRAIN NEVER WAKES UP\n");
    else
        printf("WAKE UP IN, %d, YEARS\n",yrs);


}

int main() {

    while (scanf(" %d %d ", &areas, &conn)!=EOF) 
    {

        init();
        scanf("%s",s);

        FO(i,0,strlen(s)) {
            int f1 = addtomp(s[i]);
            isactive[f1]=1;

            }

        FO(j,0,conn)
        {   scanf("%s",s);
            int f1 = addtomp(s[0]);
            int f2 = addtomp(s[1]);
            arr[f1][f2] = 1;
            arr[f2][f1] = 1;
        }

        solve();
    }

    
    return 0;

}
