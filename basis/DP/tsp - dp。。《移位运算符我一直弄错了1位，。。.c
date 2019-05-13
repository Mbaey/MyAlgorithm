#include <stdio.h>
#include <limits.h>
const int N=15, M=1<<N-1, INF=1e8;

int a[N][N] = {
		{0,3,6,7},
		{5,0,2,3},
		{6,4,0,2},
		{3,7,5,0}};
int dp[N][M];//dp[j][i] : ��j��ʼ������V��i�������г���һ���ҽ�һ�Ρ��ľ���
int main() {
    int n,m, i,j,k;
//	freopen("1.txt", "r", stdin);
	n=4;  //�ܹ�4������
	m= 1<<n-1; // M������p109˵�ģ�V��״̬������1<<N��ʾ2^N���ܹ���2^(N-1)��״̬

	for(i=0; i<n; i++){//display city
		for(j=0; j<n;j++){
			printf("%d ", a[i][j]);
		}puts("");
	}

	for(i=0; i<n; i++){
		dp[i][0]=a[i][0];
	}

	for(j=1; j < m-1; j++){// ö��V��������״̬���������һ��d(0,{1,2,3})
		printf("%d ", j);
		for(i=1; i<n; i++){//ѡ����һ�����뼯�ϵĳ��У������������0
			if(j & (1<<i-1)) continue; //������j��������

			int min=INF;
			for(k=1; k<n; k++){
				if(j & (1<<k-1) )//����ÿ����
					if(dp[k][j-(1<<k-1)] + a[i][k] < min )//??Ϊɶ��j-1
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
���ߣ�masikkk
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/masibuaa/article/details/8236074
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
*/
