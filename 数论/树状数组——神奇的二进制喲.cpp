#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
//#define ONLINE_JUDGE
//树状数组 1010. Lehmer Code (35)
using namespace std;
const int N=10, inf = (1<<31) - 1;//max_int

struct Node
{
    int id;
    int val;
};
int n;
int c[100005];
int cmp(Node node1,Node node2)
{
    return node1.val>node2.val;
}
//求管辖范围2^k
int lowbit(int x)
{
    return x&-x;
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
void add(int x)
{
    while(x<=n)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    cin>>n;
    Node vec[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>vec[i].val;
        vec[i].id=i;
    }
    sort(vec+1,vec+1+n,cmp);
    int a[n+1];
//把这些数的val映射到1-n区间。 a[]为映射后的数组
    for(int i=1; i<=n; i++)
    {
        a[vec[i].id]=i;
    }
//  for(int i=1;i<=n;i++){
//      cout<<<" ";
//  }
//  cout<
    vector<int> res(n+1);
//从后往前遍历这n个数
    for(int i=n; i>=1; i--)
    {
//这个数加入前，区间1-a[i]已经有几个数了
        int t = sum(a[i]);
        res[i]=t;
//将这个数加入到树状数组中
        add(a[i]);
         for(int i=1; i<=n; i++) printf("%d ", c[i]);
         printf("\n");
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=1)
        {
            cout<<" ";
        }
        cout<< res[i];
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
