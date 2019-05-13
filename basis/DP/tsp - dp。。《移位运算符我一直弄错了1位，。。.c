#include <stdio.h>
#include <limits.h>
const int N=15, M=1<<N-1, INF=1e8;

int a[N][N] = {
		{0,3,6,7},
		{5,0,2,3},
		{6,4,0,2},
		{3,7,5,0}};
int dp[N][M];//dp[j][i] : 从j开始，经过V（i）中所有城市一次且仅一次。的距离
int main() {
    int n,m, i,j,k;
//	freopen("1.txt", "r", stdin);
	n=4;  //总共4个城市
	m= 1<<n-1; // M：书上p109说的，V’状态总数，1<<N表示2^N，总共有2^(N-1)种状态

	for(i=0; i<n; i++){//display city
		for(j=0; j<n;j++){
			printf("%d ", a[i][j]);
		}puts("");
	}

	for(i=0; i<n; i++){
		dp[i][0]=a[i][0];
	}

	for(j=1; j < m-1; j++){// 枚举V’的所有状态，除了最后一个d(0,{1,2,3})
		printf("%d ", j);
		for(i=1; i<n; i++){//选择下一个加入集合的城市，不算出发城市0
			if(j & (1<<i-1)) continue; //包含了j，跳过。

			int min=INF;
			for(k=1; k<n; k++){
				if(j & (1<<k-1) )//对于每个点
					if(dp[k][j-(1<<k-1)] + a[i][k] < min )//??为啥是j-1
						min = dp[k][j-(1<<(k-1))] + a[i][k] ;
			}
            dp[i][j]=min;
		}
	}
	int min=INF;
    for(k=1;k<n;k++){
        if(dp[k][m-1-(1<<k-1)] + a[0][k] < min){
            min=dp[k][m-1-(1<<k-1)] + a[0][k];
        }
    }
    dp[0][m-1]=min;


	printf("\n%d", dp[0][m-1]);

	return 0;
}
/*
作者：masikkk
来源：CSDN
原文：https://blog.csdn.net/masibuaa/article/details/8236074
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
