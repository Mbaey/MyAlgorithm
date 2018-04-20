#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<assert.h>
#include<map>
using namespace std;
/**
http://lx.lanqiao.cn/problem.page?gpid=T37
NIM问题
参考资料
https://www.zhihu.com/question/29910524
https://blog.csdn.net/mymilkbottles/article/details/51362703
https://baike.baidu.com/item/%E5%BC%82%E6%88%96/10993677

*/
const int N=105; //10 6
int a[N]= {0}, b[N]= {0};
//1 5 9
int main()
{
    freopen("1.txt", "r", stdin);
    int cnt=0, t;
    while(cin >> t){
        a[cnt++] = t;
    }
    int max=a[cnt-1];
    a[cnt] = max + 1;
    int bk=0;
    for(int i=0; i<= cnt-1; i+=2){
        //把a[i+1] - a[i] - 1 看作一堆硬币
        b[i] = a[i+1] - a[i] - 1;
        bk ^= b[i];
    }
    if(bk==0){
        printf("-1\n");
    }else{
        for(int i=0; i<=cnt-1; i+=2){
            bk ^= b[i];
            if(b[i] > bk ){
                //第i堆需要拿走n枚， 变成bk的硬币数
                printf("%d %d", a[i], a[i+1] - bk - 1);
                break;
            }
            bk ^= b[i];//归位 a ^ b ^ b = a
        }
    }


    return 0;
}
