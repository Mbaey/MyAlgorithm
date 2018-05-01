#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N=10,M=20;//p's max length

int dp[N][M]= {0};

void dis(int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%d ", dp[i][j]);
        }
        cout << endl;
    }
}
void say_diff(string p, string t)
{
    int n=p.length();
    int m=t.length();
    int i=n, j=m;//"happy", "hppay"
    while(i != 1 || j != 1)
    {
        if(dp[i][j] == dp[i][j-1]+1){
            printf("T[%d]:%c is ²åÈë after P[%d]:%c\n", j-1, t[j-1], i-1, p[i-1]);
            j--;
        }else if(dp[i][j] == dp[i-1][j]+1){
            printf("T[%d]:%c is É¾³ý in P[%d]:%c\n", j-1, t[j-1], i-1, p[i-1]);
            i--;
        }else{
            if(dp[i][j] == dp[i-1][j-1]){
                i--; j--;
            }else{
                i--; j--;
                printf("T[%d]:%c is ÐÞ¸Ä with P[%d]:%c\n", j, t[j], i, p[i]);
            }
        }


    }

}
/*
pattern is right
def: dp[i][j] is the diff of p[0,i) and t[0,j)

*/
int similarity(string p, string t)
{
    int n=p.length();
    int m=t.length();
    for(int i=1; i<=n; i++)
        dp[i][0]=i;
    for(int i=1; i<=m; i++)
        dp[0][i]=i;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(p[i-1]==t[j-1])
            {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1]+1,dp[i-1][j]+1));
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
            }
        }
    }
    dis(n,m);
    say_diff(p,t);
    return dp[n][m];
}
int main()
{
    //7
    cout << similarity("Hello world!", "Hallo mbaey") << endl;
    cout << similarity("happy", "hppay") << endl;

    return 0;
}
