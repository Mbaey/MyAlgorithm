#include <iostream>
#include <cstdio>
#include <vector>
//1092 回文字符串  https://blog.csdn.net/f_zyj/article/details/52091745

using namespace std;
const int N=1005;
/*
    最长公共字串
    def:dp[i][j] is str1[0,i) 与 str2[0,j)的最大公共字串长度
    forword:
    if(str1[i] == str2[j]) dp[i][j] = max{dp[i-1][j-1]+1}
    else  dp[i][j] = max{dp[i][j-1], dp[i-1][j]}
    */
int d[N][N]={0}, s[N][N]={0};
int CommonOrder(string x, string y){
    int n=x.length();
    int m=y.length();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                d[i][j]=d[i-1][j-1]+1;  s[i][j]=1;
            }else{
                if(d[i][j-1]>=d[i-1][j]){
                    d[i][j]=d[i][j-1];  s[i][j]=2;
                }else{
                    d[i][j]=d[i-1][j];  s[i][j]=3;
                }
            }
        }
    }

    int i=n, j=m;
    string com;
    while(i>=0 && j>=0){
        if(s[i][j]==1){
            com+=x[i-1];
            i--; j--;
        }else if(s[i][j]==2){
            j--;
        }else{
            i--;
        }
    }
    printf("最长公共子序列的长度：%d, 它是:%s\n", d[n][m], com.c_str());
    return d[n][m];
}

int main()
{
    freopen("1.txt", "r", stdin);
    string str1;
    cin >> str1;
    string str2(str1.rbegin(), str1.rend());
    //test reverse
    cout << str2<< endl;
    int c = CommonOrder(str1, str2);
    cout << str1.length() - c;

    return 0;
}
