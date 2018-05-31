#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int N = 1000;

/*
回溯法 ——素数环问题
*/
int n=6;

/*common*/
void out(vector<int> res);
bool prime(int p);
bool check(int i, vector<int> res);
//1.递归
bool vis1[N]={0};
vector<int> res1;
void backTrack1(int a);
//2.书上的N叉树
bool check2(int i, vector<int> res, int k);
vector<int> res2;
void backTrack2();
void backTrack3();

int main()
{
//    freopen("1.txt", "r", stdin);
//    cin >> n;
    res1.push_back(1); vis1[1]=1;//指定第一个位置。 因为是环，谁开始都一样
    backTrack1(1);

    backTrack2();
    return 0;
}
void backTrack1(int a){
    if(a==n){
        out(res1);
        return;
    }
    for(int i=1; i<=n; i++){
        if(!vis1[i] && check(i, res1)){
            res1.push_back(i);
            vis1[i]=true;
            backTrack1(a+1);
            vis1[i]=false;
            res1.pop_back();
        }
    }
}
void backTrack2(){
    int high=1;
    res2.resize(n);
    res2[0]=1;

    while(high>=1){
        int &tmp = res2[high];
        tmp++;
        while(tmp <= n )
            if(check2(tmp, res2, high)) break;
            else tmp++;
        if(tmp <= n && high==n-1){
            out(res2);
        }

        if(tmp <= n  && high <n-1){
            high++;
        }else{
            res2[high--]=0;
        }
    }
}
bool check(int i, vector<int> res){
    int len = res.size();
    if(len==0){
        return true;
    }
    bool flag=false;
    flag = prime(res[len-1]+i);
    if(len==n-1){
        flag =  flag & prime(i+res[0]);
    }
    return flag;
}
bool check2(int i, vector<int> res, int k){
    for(int j=0; j<k; j++)
        if(res[j]==i) return false;
    int len = k;
    if(len==0){
        return true;
    }
    bool flag=false;
    flag = prime(res[len-1]+i);
    if(k==n-1){
        flag =  flag & prime(i+res[0]);
    }
    return flag;
}
bool prime(int p){
    int n = sqrt(p);
    for(int i=2; i<=n; i++){
        if(p%i==0) return false;
    }
    return true;
}
void out(vector<int> res){
    for(int i: res){
        printf("%d ", i);
    }printf("\n");
}
