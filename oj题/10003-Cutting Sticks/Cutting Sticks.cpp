#include<stdio.h>
#include<string.h>
const int INF=99999999;
const int MN=60;
int dp[MN][MN];
int num[MN];

int main()
{
    int n,m,i,j,L,p,k,tmp;
    int MIN;
    while(scanf("%d",&L) && L)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&num[i]);
        num[0]=0;
        num[n+1]=L;
        memset(dp,0,sizeof(dp));
        for(p=1;p<=n+1;p++)
           for(i=0;i<=n+1;i++)
           {
               j=i+p;
               MIN=INF;
               if(j>n+1) break;//这个很重要
               for(k=i+1;k<j;k++)//这里是i+1，原先令k=i是错的，因为dp[i][i]=0，这必然导致找到的值小于正常的
               {
                   tmp=dp[i][k]+dp[k][j]+num[j]-num[i];
                   if(MIN>tmp) MIN=tmp;
               }
               if(MIN!=INF)dp[i][j]=MIN;
           }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);

    }
    return 0;
}