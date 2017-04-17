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

int t;
int al[26][26];
int dt[26];
char path[1000];

int main() {
    
    scanf("%d",&t);

    FO(i,0,t)
    {   
        scanf("%s",path);
        ARR0(al);ARR0(dt);
        int ind =0;
        int nb = 0;
        dt[ind] = path[0]-'A';
        FO(j,1,strlen(path)-1)
        {   nb = path[j]-'A';

            if(dt[ind]==nb)
                {    
                    ind--;  al[dt[ind]][nb] = 1; al[nb][dt[ind]] = 1;
                }
            else if(path[j]==path[j+1])  
                {  
                    al[dt[ind]][nb] = 1; al[nb][dt[ind]] = 1; 
                    j++;
                }
            else
                {   ind++; dt[ind]=nb;
                }


        }

        printf("Case %d\n",i+1);

        FO(j,0,26)
        {
            int ct =0;
            FO(k,0,26)  
                ct+= al[j][k];

            if(ct>0)
                printf("%c = %d\n",'A'+j,ct);
            
        }


    
    }


}
