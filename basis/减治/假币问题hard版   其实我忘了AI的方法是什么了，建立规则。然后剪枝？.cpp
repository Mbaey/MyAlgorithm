#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<assert.h>
#include<time.h>
using namespace std;

const int N=1<<20; //10 6
long long a[N]= {0}, n=0, cnt=0;
/*
先减半 假币轻。  那不就成了折半查找了吗。
还是三分吧
input:
 假币轻 f=1
 假币重 f=0
output:
 假币的位置
*/
int Coin1(int l, int r, int n, int f){//[l,r)
    if(n==1) return l;
    int num1, num2, num3;
    if(n%3==0){
        num1=num2=num3=n/3;
    }else{
        num1=num2=n/3+1;// 8/3 +1
        num3=n-2*num1;
    }
    int add1=0, add2=0;
    for(int i=0; i<num1; i++){
        add1 += a[l+i];
        add2 += a[l+i+num1];
    }
    if(f){
        if(add1 < add2){
            return Coin1(l, l+num1, num1, f);
        }else if(add1 > add2){
            return Coin1(l+num1, l+2*num1, num1, f);
        }else{
            return Coin1(l+2*num1, r, num3, f);
        }
    }else{
        if(add1 > add2){
            return Coin1(l, l+num1, num1, f);
        }else if(add1 < add2){
            return Coin1(l+num1, l+2*num1, num1, f);
        }else{
            return Coin1(l+2*num1, r, num3, f);
        }
    }

}

/*
三分 假币不知轻重
返回 1.假币的位置
     2.假币的轻重 f=1 轻
                  f=0 重
*/
int Coin2(int l, int r, int n, bool &f){//[l,r)
    if(n==1) return l;
    int num1, num2, num3;
    if(n%3==0){
        num1=num2=num3=n/3;
    }else{
        num1=num2=n/3+1;// 8/3 +1
        num3=n-2*num1;
    }
    int add1=0, add2=0;
    for(int i=0; i<num1; i++){
        add1 += a[l+i];
        add2 += a[l+i+num1];
    }
    if(add1 != add2){//a[r] 是标准
        int standard=a[r-1]*num1;
        if(add1 != standard){//假币在 add1中
            if(add1 >= standard)//假币重 且在 add1中
                return Coin1(l, l+num1, num1, f=false);
            else
                return Coin1(l, l+num1, num1, f=true);
        }else{//假币在 add2中
            if(add2 >= standard)//假币重 且在 add2中
                return Coin1(l+num1, l+2*num1, num1, f=false);
            else
                return Coin1(l+num1, l+2*num1, num1, f=true);
        }
    }else{//不知道轻重
        return Coin2(l+2*num1, r, num3, f);
    }
}
int main()
{
    n=120;
    fill_n(a, a+n, 2);
    srand(time(NULL));
    int ind = rand()%n+1;
//    ind = 5;
//    a[ind]= 3;//假币重
    a[ind]= 1;//假币轻
    bool f=0;
    cout << Coin2(1, n+1, n, f) << endl;
//    cout << Coin1(1, n+1, n, false) << endl;
    cout << ind << endl;

    return 0;
}
