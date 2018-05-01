#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
const int N=1<<20;//max amount of elephant
struct elephant{
    int w,iq, id;
}E[N];
bool cmp(elephant a, elephant b){
    return a.w < b.w;
}
/*
def: dp[i] is [0, i]最长递减子序列的长度
init dp[0]=1

forword:dp[i]= max{dp[j]+1} aj<ai  (0<j<i)
*/
int dp[N]={0}, cnt=0;
int max_increment(){
    int res=0;
    dp[0]=1;
    for(int i=1; i<cnt; i++){
        int maxL = 1;
        for(int j=i-1; j>=0; j--){
            if(E[i].iq < E[j].iq){
                if(E[i].w > E[j].w)
                    maxL = max(maxL, dp[j]+1);
                else
                    maxL = max(maxL, dp[j]);
            }else{
                maxL = max(maxL, dp[j]);
            }
        }
        dp[i]=maxL;
    }
    int max=dp[cnt-1];
    cout << max<<endl;
    stack<int> s;
    for(int i=cnt-1; i>=0; i--){
        if(dp[i] == max){
            s.push(E[i].id);
            max--;
        }
    }
    while(!s.empty()){
        printf("%d\n", s.top());
        s.pop();
    }
}
int main()
{
    freopen("1.txt", "r", stdin);

    while(cin >> E[cnt].w>>E[cnt].iq){
        E[cnt].id = cnt+1;
        cnt++;
    }
    sort(E, E+cnt, cmp);
    //test in
    for(int i=0; i<cnt; i++){
        printf("%d: %d %d\n", E[i].id, E[i].w, E[i].iq);
    }
    max_increment();
    return 0;
}
