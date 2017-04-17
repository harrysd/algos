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
#define ARR0(A) memset((A), 0, sizeof((A)))

typedef long long LL;
using namespace std;

int lic[2001];
int ldc[2001];
int nums[2001];
int t,n;

int main() {
    scanf("%d",&t);
    
    FO(i,0,t)
    {  scanf("%d",&n);
       ARR0(nums); ARR0(lic); ARR0(ldc);

       FO(j,0,n) scanf("%d",&nums[j]);

       int ans = 0;
       int j,k;
       FO(a,0,n)
       {  j = n-(1+a);
          lic[j]=1; ldc[j]=1;
          FO(b,0,a)
            {  k = n-(1+b);
               if(nums[k]<=nums[j])
                    lic[j] = max(lic[k]+1,lic[j]);
               
               if(nums[k]>=nums[j]) 
                    ldc[j] = max(ldc[k]+1,ldc[j]);  
               
            }    
          //cout<< j << " "<<nums[j] << " " <<ldc[j] << " "<<lic[j] <<endl; 
          ans = max(ans,lic[j]+ldc[j]-1);
       } 

       
       printf("%d\n",ans);
    }
    
    return 0;
}
