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

using namespace std;

int n,m,s;
char moves[50001];
char grid[101][101];
int pos[3]; //N S L O

int main() {
    
    while(scanf("%d %d %d",&n,&m,&s),(n!=0&&m!=0&&s!=0))
    {   ARR0(pos);
        int total=0;
        FO(i,0,n)
            scanf("%s",grid[i]);

        scanf("%s",moves);

        FO(i,0,n) FO(j,0,m) 
            if(grid[i][j]=='N'||grid[i][j]=='S'||grid[i][j]=='L'||grid[i][j]=='O')
                {   pos[0]=i;pos[1]=j;
                    if(grid[i][j]=='N') pos[2] = 0;
                    else if(grid[i][j]=='L') pos[2] = 1;
                    else if(grid[i][j]=='S') pos[2] = 2;
                    else if(grid[i][j]=='O') pos[2] = 3;
                    grid[i][j] = '.';
                }

        FO(i,0,s)
        {   if(moves[i]=='D')
                pos[2]++;
            else if(moves[i]=='E')
                pos[2]--;

            pos[2] = pos[2]<0?3:pos[2];
            pos[2] = pos[2]%4;

            //cout<<i<<". "<<pos[0]<< " " <<pos[1]<< " " << pos[2]<<" ";
            if(moves[i]=='F')
            {   int nr = pos[0],nc = pos[1];
                if(pos[2]==0) nr--;
                else if(pos[2]==1) nc++;
                else if(pos[2]==2) nr++;
                else if(pos[2]==3) nc--;

                nr = nr>=n?n-1:nr;
                nr = nr<0?0:nr;
                nc = nc>=m?m-1:nc;
                nc = nc<0?0:nc;

                if(grid[nr][nc]=='.'||grid[nr][nc]=='*')
                {   if(grid[nr][nc]=='*')
                        {   total++;
                            grid[nr][nc] = '.';
                        }
                    pos[0] = nr; pos[1] = nc;
                }

            }

            //cout<<moves[i]<< " --->" << pos[0]<< " " <<pos[1]<< " " << pos[2]<< " * "<<total <<endl;

        }

        printf("%d\n",total);

    }

}

// MAPS
// for (map<int,int>::iterator it=denoms.begin(); it!=denoms.end(); ++it)
// 
// if (tmap.find(nxtamt) == tmap.end() ) // To find
