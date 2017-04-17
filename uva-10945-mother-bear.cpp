#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;

int main() {
   
    while(1==1)
    {   string s;
        getline(cin,s);

        if(s=="DONE")
            break;
        
        int tl = s.length(); 
        string clean;
        FO(i,0,tl)
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                if(s[i]<'a')
                    clean += 'a' + (s[i]-'A');
                else
                    clean += s[i];
            }

        bool ispali = true;        
        int cl = clean.length();
        FO(i,0,cl)
            if(clean[i]!=clean[cl-(1+i)])
                ispali=false;
       
        if(ispali)
            cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;
   
    }
    
}

/*
String inputs
string s;
getline(cin,s); // FULL LINE
s.length();
s+= 'a' //APPEND a char
*/

