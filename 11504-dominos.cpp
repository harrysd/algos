#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <string>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))
#define ARR0(A) memset((A), 0, sizeof((A)))

/*
Todos
// 
1. took many many hours
Finding SCC with a parent outside SCC
*/


typedef long long LL;

using namespace std;
int v,e,iter,conn;

vector< vector<int> > edges;
vector<int> vis; 

vector<int> revm;
vector<int> dagl;

void init()
{
    edges.clear();

    vis.clear();dagl.clear();
    
    FO(i,0,v+1){
        vector<int> vi;
        edges.push_back(vi);
        vis.push_back(0);
        
    }
}




void dfs1(int i,bool fdg)
{
    vis[i] = 1;

    FO(j,0,edges[i].size())
        if(!vis[edges[i][j]]) dfs1(edges[i][j],fdg);

    if(fdg) dagl.push_back(i);

}

void solvedag()
{
    FO(i,1,v+1) if(!vis[i]) dfs1(i,true);

    FO(i,0,v+1) vis[i]=0;

    int sol=0;
    FO(j,0,dagl.size()) 
        {   int st= dagl.size()-(j+1);
            if(!vis[dagl[st]]) {  sol++; dfs1(dagl[st],false);}
            //cout<<st<<endl;
        }

    cout<<sol<<endl;
}


int main()
{   int f,t,cases;

    scanf("%d",&cases);

    FO(j,0,cases)
    {
        scanf("%d %d",&v,&e);
        if(v==0&&e==0)break;
        //cout<<v<<"::"<<e<<endl;
        init();

        FO(i,0,e)
        {
            scanf("%d %d",&f,&t);
            edges[f].push_back(t);  
            //edges[t].push_back(f);   
        }

        solvedag();
    }


    return 0;
}
