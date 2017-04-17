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

map<string,string> smap;
vector<string> vs;
map<string,int> ct;
int wm[26];

int main() {
    string t;
    while(1==1)
    {   cin>>t;
        ARR0(wm);
        if(t=="#") break;
        string tt = "";
        FO(i,0,t.length())
            if(t[i]<'a')
                tt += 'a'+t[i]-'A';
            else
                tt += t[i];

        string sort="";
        FO(k,0,tt.length()) wm[tt[k]-'a']++;
        FO(k,0,26) FO(j,0,wm[k]) sort+='a'+k;

        vs.push_back(t);
        smap[t] = sort;
        ct[sort]++;
        
    }

    sort(vs.begin(),vs.end());

    FO(k,0,vs.size())
        if(ct[smap[vs[k]]]==1)
            cout<<vs[k]<<endl;

}

/*
String inputs
string s;
getline(cin,s); // FULL LINE
s.length();
s+= 'a' //APPEND a char
*/

