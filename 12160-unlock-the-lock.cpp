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
1. ERROR comparing int as s2=='0'
*/

using namespace std;
//(n-1)*2
//
int st,en,tno;
vector<int> rs;
int taken[10000];

void init()
{
  rs.clear();
  ARR0(taken);

}

void solve()
{

  queue<int> q;
  q.push(st);
  taken[st]=1;
  bool found=false;

  if(st==en) found=true;


  while(!q.empty()&&!found)
  {   
      int cur = q.front(); q.pop();

      FO(i,0,rs.size())
      {   int newn = (cur+rs[i])%10000;

          //cout<<cur<< " " << rs[i]<<endl;
          if(!taken[newn])
          { taken[newn] = taken[cur]+1;
            q.push(newn);
            if(newn==en) {found=true;break;}
          }
      }
  }



  if(!found)
    printf("Case %d: Permanently Locked\n",tno);
  else
    printf("Case %d: %d\n",tno,taken[en]-1);


}

int main() {
    string s,sx,s1,s2,r;int s3;
    tno=0;
    while(getline(cin,s))
    {   istringstream is(s);
        tno++;
        is>>s1>>s2>>s3;
        init();

        if(s1.length()==1&&s2.length()==1&&s1[0]=='0'&&s2[0]=='0'&&s3==0)
            return 0;

        st= 1000*(s1[0]-'0')+100*(s1[1]-'0')+10*(s1[2]-'0')+(s1[3]-'0');
        en= 1000*(s2[0]-'0')+100*(s2[1]-'0')+10*(s2[2]-'0')+(s2[3]-'0');
        //cout<<st<<"-"<<en<<endl;

        getline(cin,sx);
        istringstream is2(sx);
        FO(i,0,s3) 
          { is2>>r;
            int rn = 1000*(r[0]-'0')+100*(r[1]-'0')+10*(r[2]-'0')+(r[3]-'0');
            rs.push_back(rn);
            //cout<<rn<<endl;
          }
        solve();
        


    }
    
    return 0;

}


