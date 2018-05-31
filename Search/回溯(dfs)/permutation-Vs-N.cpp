#include <iostream>
#include <cstdio>
#include <algorithm>
#include<time.h>
using namespace std;
const int n=12;
int cnt1=0, cnt2=0;
/*
Hello permutationalTree! Totle Time : 9.572
Hello NTree!Totle Time : 22.954
Hello BackTrack!
*/


int x[n+1]={0};
void permutationalTree(int h){
    if(h >= n){//当h == n时 已经不用和自己交换了。
//        for(int i=1; i<=n; i++){ printf("%d ", x[i]);} printf("\n");
        cnt1++;
        return;
    }
    for(int i=h; i<=n; i++){
        swap(x[i], x[h]);
        permutationalTree(h+1);
        swap(x[i], x[h]);
    }
}
int vis[n+1]={0}, a[n+1]={0};
void NTree(int h){
    if(h > n){//算是增量构造法。 必须填完最后一个
//        for(int i=1; i<=n; i++){  printf("%d ", a[i]);} printf("\n");
        cnt2++;
        return;
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vis[i]=1;
            a[h] = i;
            NTree(h+1);
            a[h] = 0;
            vis[i]=0;
        }
    }
}
int main()
{
    clock_t startTime1, startTime2, endTime;
    startTime1 = clock();

    for(int i=0; i<=n; i++) x[i]=i;



    startTime1 = clock();
    permutationalTree(1);
    /*******************************************/
    startTime2 = clock();
    cout << "Hello permutationalTree! "<< "Totle Time : " <<(double)(startTime2 - startTime1) / CLOCKS_PER_SEC << endl;

    NTree(1);

    endTime = clock();
    cout << "Hello NTree!" << "Totle Time : " <<(double)(endTime - startTime2) / CLOCKS_PER_SEC<< endl;

    if(cnt1 == cnt2)
        cout << "Hello BackTrack! "<< endl;
    return 0;
}
