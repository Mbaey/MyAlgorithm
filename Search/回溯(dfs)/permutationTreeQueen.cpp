#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N=100;
int n=8, cnt=0;
int a[N] ={0};
void out(){
    printf("No.%d\n", cnt++);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j == a[i]){
                printf(" X");
            }else
                printf(" ��");
        }printf("\n");
    }printf("\n");
//    system("pause");
}
bool ok(int i){//��i�з� a[i]����
    for(int j=0; j<i; j++){
        if( a[j] + j == a[i]+i){//���Խ���
            return false;
        }else if(a[j] - j == a[i] -i)//���Խ���
            return false;

    }
    return true;
}
void out2(){
     for(int j=0; j<n; j++){
        printf("%d ", a[j] );
    }printf("\n");
}
bool ok2(int i){
    return 1;
}
/*
NTree
[0,n) ���i�еĻʺ�
*/
void permutationTreeQueen(int h){
    if(h == n-1){
        if(ok(h)){ out(); }
        return;
    }
    for(int i=h; i<n; i++){
        swap(a[i], a[h]);//֮���h�߶����ڵ������������ !!
        if(ok(h))
            NQueen(h+1);
        swap(a[i], a[h]);
    }
}
int main()
{
    for(int i=0; i<n; i++) a[i]=i;
    NQueen(0);
    cout << "Hello world!" << endl;
    return 0;
}
