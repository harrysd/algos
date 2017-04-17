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

int n,q, d,m;
LL nums[201];
LL sol[21][21];

int main() {
        int set = 1;
        while(scanf("%d %d",&n,&q),n>0 && q>0)
        {   ARR0(nums);
            FO(j,0,n) scanf("%lld",&nums[j]);
            printf("SET %d:\n",set);

            FO(j,0,q)
            {   scanf("%d %d",&d,&m);
                ARR0(sol);
                sol[0][0]=1;

                int rem=0;
                
                FO(x,0,n)
                {   LL temp[21][21];
                    ARR0(temp);
                    FO(y,1,m+1)
                    {   rem = nums[x]%d;  
                        rem = rem<0?d+rem:rem; // imp step
                        FO(z,0,d)
                            temp[y][(rem+z)%d] = sol[y-1][z];      
                    }

                    FO(y,1,m+1)
                        FO(z,0,d)
                          sol[y][z] += temp[y][z];
                
                }

                printf("QUERY %d: %lld\n",j+1,sol[m][0]);
            }

            set++;
        }

}
