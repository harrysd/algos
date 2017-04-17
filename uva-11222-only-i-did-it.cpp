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

int arr[10001];

// use printf over cout always
int main() {
    int n,q,qno;
    scanf("%d",&n);

    FO(i,0,n)
    {   ARR0(arr);

        FO(j,0,3)
        {   scanf("%d",&q);
            FO(k,0,q) 
              { 
                  scanf("%d",&qno);
                  arr[qno] |= (1<<j);

              }
        }
          
        int f1=0,f2=0,f3=0;
        FO(j,0,10001)
          {    if( arr[j] == 1) f1++;
               if( arr[j] == 2) f2++;
               if( arr[j] == 4) f3++;
          }

        //FO(j,0,10001) if(arr[j]!=0) cout<<j << " "<< arr[j] <<endl;
        //cout<<f1<<"::"<<f2<<":"<<f3<<endl;
        printf("Case #%d:\n",i+1);
        if(f1>=f2 && f1>=f3)
        {  printf("1 %d",f1);
           FO(j,0,10001) if(arr[j]==1) printf(" %d",j); 
           printf("\n");
        }

        if(f2>=f1&&f2>=f3)
        {  printf("2 %d",f2);
           FO(j,0,10001) if(arr[j]==2) printf(" %d",j);
           printf("\n");
        }

        if(f3>=f1&&f3>=f2)
        {  printf("3 %d",f3);
           FO(j,0,10001) if(arr[j]==4) printf(" %d",j);
           printf("\n");
        }


        
    }

    
        
}

    