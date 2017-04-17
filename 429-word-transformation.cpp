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

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;


/*
1. input parsing issue
2. init for each query
3. lots of edge cases
a. both fr and to same
b. one of fr and to from outside
*/

using namespace std;

vector<string> dict;
map<string,int> stmap;
int amap[201][201];
int sol[201];
string s;
string src,dst;

void init()
{   ARR0(amap);
    dict.clear();
    stmap.clear();
    
}

void bfs(int s1,int f1)
{   
    ARR0(sol);
    queue<int> q;
    q.push(s1);
    sol[s1]=1;
    bool found=false;
    //cout<<s1<<"::"<<f1<<endl;

    while(!q.empty()&&!found)
    {   int sr=q.front();
        q.pop();

        FO(i,0,dict.size()+1)
            if(amap[sr][i] && sol[i]==0)
            {   sol[i]=sol[sr]+1;
                q.push(i);
                if(i==f1) {found=true;break;}
            }
    }


    int ans=sol[f1];
    if(!found&&s1!=f1) ans=0;
    cout<<src<<" "<<dst<<" "<<(ans-1)<<endl;

}

void acase()
{   
    init();
    int i=0;
    string s;
    while(1==1)
     {   getline(cin,s);
         if(s[0]=='*') break;
         if(s.length()==0) continue;
         dict.push_back(s);
         stmap[s]=i;

         FO(j,0,i)
         {  if(s.length()==dict[j].length())
            {   int abss=0;
                FO(k,0,s.length())
                    if(s[k]!=dict[j][k]) abss++;

                if(abss==1)
                {
                    amap[i][j]=1;
                    amap[j][i]=1;
                    //cout<<s<<endl;
                }
            }
         }
         i++;
     }

    
    
}

int main() {

    int t;
    scanf("%d",&t);
    int fr,to;
    bool isfirst=true;
    map<string,int>::iterator it;

    while(getline(cin,s))
    {   
        if(s.length()==0)
        {
           if(!isfirst)cout<<endl;
           acase();isfirst=false;
        }
        else
        {   istringstream is(s);
            is>>src>>dst;

            it = stmap.find(src);
            if (it == stmap.end())
                fr=-1;
            else 
                fr=it->second;


            it = stmap.find(dst);
            if (it == stmap.end())
                to=-1;
            else 
                to=it->second;
                
            if(fr==-1||to==-1)
            {   
                bool equal=true;
                if(src.length()!=dst.length()) equal=false;
                int abss=0;
                if(equal)
                    FO(k,0,src.length())
                        if(src[k]!=dst[k]) abss++;

                //cout<<abss<<":";
                if(abss!=0) equal=false;

                if(equal)
                    cout<<src<<" "<<dst<<" "<<0<<endl;
                else
                    cout<<src<<" "<<dst<<" "<<-1<<endl;
            }
            else
                bfs(fr,to);
        }

    }
    
    return 0;

}


