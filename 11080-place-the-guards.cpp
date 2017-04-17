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
Bicoloring for each FOREST - yay
*/


typedef long long LL;
using namespace std;

int v,e;
vector<int> edges[201];
int color[201];
bool solvable;

void init()
{
  FO(i,0,201) edges[i].clear();
  ARR0(color);
  solvable=true;
}

void dfsbp(int i,int cl)
{   color[i] = cl;

    FO(j,0,edges[i].size())
    {
        if(color[edges[i][j]]==cl)
            {   solvable=false;return;}
        else if(color[edges[i][j]]==0)
            {
                dfsbp(edges[i][j],(cl==1)?2:1);
            }
    }
    
}

void solve()
{   
    int sol=0;
    FO(i,0,v) 
        if(color[i]==0) 
            {   dfsbp(i,1);

                int tc1=0,tc2=0;
                FO(i,0,v) 
                    if(color[i]==1) 
                        {tc1++; color[i]=3;}
                    else if(color[i]==2)  {tc2++;color[i]=3;}

                int tsol=tc1;
                if(tc2!=0) tsol=min(tsol,tc2);
                sol+=tsol;
            }

    if(solvable)
        printf("%d\n",sol);
    else
        printf("-1\n");
}


int main()
{   int t,v1,v2;
    scanf("%d",&t);

    FO(i,0,t)
    {   init();
        scanf("%d %d",&v,&e);
        FO(j,0,e)
            {   scanf("%d %d",&v1,&v2);
                edges[v1].push_back(v2);
                edges[v2].push_back(v1);
            }
        solve();
    }

    return 0;
}
