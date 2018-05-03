#include <iostream>
#include <cstdio>
#include <vector>
//华为机试：购物单 https://blog.csdn.net/wly_2014/article/details/51223592

using namespace std;
const int N=3205, M=65;
int n, m;
int v[N]= {0}, w[N]= {0}, f[N]= {0};
/*
def:
dp[i][j]: 在还剩余j钱，之后[i,M]个物品中 所能凑出的最大v*w;


第i件物品不要 或者要
    普通：dp[i][j]= max{dp[i-1][j], dp[i-1][j-v[j]]+ w[i] }

*/
int dp[M][N]= {0};
bool vis[M][N]={0};
void KnapSack();
int main()
{
    freopen("1.txt", "r", stdin);
    cin >>n>>m;
    n/=10;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d %d", v+i, w+i, f+i);
        v[i]/=10;
    }

    for(int i=1; i<=m; i++){
        vis[i][0]=1;
        for(int j=1; j<=n; j++){
            dp[i][j]=dp[i-1][j];
            if(vis[f[i]][j]){
                if(j>=v[i] && dp[i-1][j-v[i]]+w[i]*v[i]>dp[i-1][j]){
                    vis[i][j]=1;
                    dp[i][j]=dp[i-1][j-v[i]]+w[i]*v[i];
                }
            }
            else{
                int fa =f[i];
                if(j>=v[i]+v[fa] && dp[i-1][j-v[i]-v[fa]]+w[i]*v[i]+w[fa]*v[fa] >dp[i-1][j]){
                    vis[i][j]=1;
                    vis[fa][j]=1;
                    dp[i][j]=dp[i-1][j-v[i]-v[fa]]+w[i]*v[i]+w[fa]*v[fa];
                }
            }
        }
    }
    cout << dp[m][n]*10 << endl;


    return 0;
}
void KnapSack(){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i] && dp[i-1][j-v[i]]+w[i]>dp[i-1][j]){
                dp[i][j]=dp[i-1][j-v[i]]+w[i];
            }
        }
    }
    bool vis[M]={0};
    for(int j=n, i=m; i>0; i--){
        if(j==0)
            break;
        if(dp[i][j] > dp[i-1][j]){
            vis[i]=1; j-=v[i];
        }
    }

    cout << dp[m][n] << endl;
    for(int i=1; i<=m; i++){
        printf("%d ", vis[i]);
    }
}
