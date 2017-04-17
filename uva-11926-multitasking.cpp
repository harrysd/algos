#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <bitset>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define RO(i,b,a) for (int i = (b); i >= (a); i--)
#define pb push_back
#define ARR0(A) memset((A), 0, sizeof((A)))
#define ARR1m(A) memset((A), -1, sizeof((A)))

typedef long long LL;

using namespace std;

bitset<1000001> bs;
int mp[1000001];
int o,p;

void withint()
{
    while(scanf("%d %d",&o,&p),!(o==0&&p==0))
    {   ARR0(mp);
        bool isok = true;

        int s,d,ct,fq;
        FO(j,0,o)
            {   scanf("%d %d",&s,&d);
                if(isok)
                    FO(k,s,d)
                    {
                        if(k>1000000)
                            break;
                        else
                        {
                            if(mp[k]==1)
                                {   isok=false;break;}
                            
                            mp[k]=1;
                        }

                    }
                

            }

        FO(k,0,p)
            {    scanf("%d %d %d",&s,&d,&fq);
                if(isok)
                {   bool cont=true;
                    for(int pre=0;cont;pre=pre+fq)
                        FO(k,s+pre,pre+d)
                        {    if(k>1000000)
                                {   cont= false;
                                    break;
                                }
                            else
                               {   if(mp[k]==1)
                                        {   isok=false;break;}
                                    mp[k]=1;
                                }
                        }
                }
                

            }

        
        if(isok)
            printf("NO CONFLICT\n");
        else
            printf("CONFLICT\n");

    }
}

void withbmsk()
{
    while(scanf("%d %d",&o,&p),!(o==0&&p==0))
    {   bs.reset();
        bool isok = true;

        int s,d,ct,fq;
        FO(j,0,o)
            {   ct= bs.count();
                int flips=0;
                scanf("%d %d",&s,&d);
                if(isok)
                    FO(k,s,d)
                    {
                        if(k>1000000)
                            break;
                        else
                        {
                            bs.flip(k);
                            flips++;
                        }

                    }
                if(ct+flips!=bs.count())
                    isok= false;

            }

        FO(k,0,p)
            {   ct= bs.count();
                int flips=0;
                scanf("%d %d %d",&s,&d,&fq);
                if(isok)
                {   bool cont=true;
                    for(int pre=0;cont;pre=pre+fq)
                        FO(k,s+pre,pre+d)
                        {    if(k>1000000)
                                {   cont= false;
                                    break;
                                }
                            else
                               {   bs.flip(k);flips++; }
                        }
                }
                if(ct+flips!=bs.count())
                    isok= false;

            }

        
        if(isok)
            printf("NO CONFLICT\n");
        else
            printf("CONFLICT\n");

    }
}
// use printf over cout always
int main() {
    
        //withbmsk();
        withint();
}

    