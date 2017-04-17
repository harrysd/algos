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

int b,s;

vector<string> vs;

// use printf over cout always
int main() {
    int n; 
    string card,position;
    while(scanf("%d",&n),n!=0)
    {   vs.clear();

        FO(i,0,n) vs.push_back("*");

        int ind=0;
        FO(i,0,n)
        {   
            cin>>card>>position;
            FO(k,0,position.length())
            {   bool cont =true;
                
                while(cont)
                {   if(ind==n) ind= 0;
                    if(vs[ind]=="*") cont=false;
                    if(!cont && k==position.length()-1) break;
                    ind++;
                 } 
                //cout<<k<<" :: " <<vs[ind] << " " << ind << "****";
            }
            vs[ind] = card;
            //cout<<"    "<<ind << "--->" <<card << endl;
        }

        FO(i,0,n)   
            {   if(i!=0)cout<< " ";
                cout<<vs[i];
            }
        cout<<endl;

    }
    
        
}

    