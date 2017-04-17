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

/*
Issues
1. Ages to solve
VVV good one
// 
*/


typedef long long LL;
int n,m;
using namespace std;

int mp[500][500];
int sol[500][500];
queue<int> qq;
int mi;

void init()
{  ARR0(mp);ARR0(sol);
}

int bfs(int st)
{   qq.empty();
    qq.push(st);
    sol[st][st]=1;
    int top;
    while(qq.size()!=0)
    {   top = qq.front(); qq.pop();
        
        FO(i,0,mi)
            if(mp[top][i]==1&&sol[st][i]==0)
            {    
                sol[st][i]=sol[st][top]+1;
                qq.push(i);
                //cout<<st<<" : "<<sol[st][i]<<endl;
            }
    }
    //cout<<"bfs "<< st << "--" << sol[st]<< " " <<sol[top] <<endl;
    //cout<<endl;
    return top;
}   

int main()
{   
    int t,fr,to;scanf("%d",&t);
    
    FO(i,0,t)
    {   scanf("%d %d",&n,&m);
        init();

        mi=n;
        FO(j,0,m)
        {   scanf("%d %d",&fr,&to);
            if(mp[fr][to]==0&&fr!=to)
            {
                mp[fr][mi]=1;
                mp[mi][fr]=1;
                mp[to][mi]=1;
                mp[mi][to]=1;
                mp[fr][to] = -1;
                mp[to][fr] = -1;
                mi++;
            }
        }

        
        FO(k,0,mi) bfs(k);
        int ans=99999;

        /*
        FO(j,0,mi)
            {   
            FO(k,0,mi)
                {
                    cout<<sol[j][k]<< " ";
                }
                cout<<endl;
            }
        */

        FO(j,0,mi)
        {   int a=0,b=0;
            FO(k,0,n)
            {   if(sol[j][k]>=a)
                    {   b=a;
                        a=sol[j][k]; 
                    }
                else if(sol[j][k]>b) 
                    b= sol[j][k];
            }
            
            //cout<<j<<":"<< "->"<<a<< " "<<b <<endl;
            ans = min(ans,a+b);
        }   
        
        printf("Case #%d:\n%d\n\n",i+1,ans/2 -1);
       
    }   

    return 0;
}
