#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
//1234569873146546
const int N=1<<20;
int c=0, a[N]={0};
int n;
//×îÐ¡¶Ñ
bool ok(int h){
    if(a[h] > a[h/2]){
        return true;
    }
    return false;
}
void getSum(int h){
    if(h > n){
        c++;
//        for(int i=1; i<=n; i++){
//            printf("%d ", a[i]);
//        }printf("\n");
    }else{
        for(int i=h; i<=n; i++){
            swap(a[h], a[i]);
            if(ok(h)){
                getSum(h+1);
            }
            swap(a[h], a[i]);
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n;
    for(int i=1; i<=n; i++) a[i] = i;
    getSum(1);
    cout << c;
    return 0;
}
