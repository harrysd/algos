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


int main() {
    int pg,pgf;
    while(scanf("%d",&pg),pg>0)
    {   int fpgs = pg/4;
        pgf = pg%4;

        printf("Printing order for %d pages:\n",pg);

        if(pgf!=0) fpgs++;
        int st = 1;
        FO(j,0,fpgs)
        {   

            if(j==0&&pgf!=0)
            {
                if(pgf==1)
                {    printf("Sheet 1, front: Blank, 1\n");
                     st=1;
                     
                     if(pg>3)
                     {
                        printf("Sheet 1, back : 2, Blank\n");
                        printf("Sheet 2, front: Blank, 3\n");
                        printf("Sheet 2, back : 4, %d\n",pg);
                        st=5;j=1;pg--;
                     }
                }
                else if(pgf==2)
                {    printf("Sheet 1, front: Blank, 1\n");
                     printf("Sheet 1, back : 2, Blank\n");
                     st=3;
                }
                else if(pgf==3)
                {    printf("Sheet 1, front: Blank, 1\n");
                     printf("Sheet 1, back : 2, %d\n",pg);
                     st=3;pg--;
                }

            }
            else
            {   
                printf("Sheet %d, front: %d, %d\n",j+1,pg,st);
                printf("Sheet %d, back : %d, %d\n",j+1,st+1,pg-1);
                st = st+2;
                pg = pg-2;
            }

        }

    }

}
