/*思路：假设d[i]是以完全二叉树i号位置为根结点的二叉子堆个数，则考虑我们现在需要把n个点放入这个完全二叉树里，显然根节点已经被确定，只能放最小的，然后假设左子树的节点个数为lsize，则我们需要从n-1个节点中选出lsize个节点放入左子树，选法一共组合数C(n-1,lsize)种，剩余的放在右子树中，所以d[i]=C(n-1,lsize)*d[i的左儿子]*d[i的右儿子]；

注意：求组合数需要用logn的算法,以i为根节点个数可以先用动态规划算出来，s[i]=s[i的左儿子]+s[i的右儿子];

此算法的时间复杂度O(nlongn),在本题最大数据10^5下，具有时间可行性；
---------------------
作者：heyAmos
来源：CSDN
原文：https://blog.csdn.net/yinxiaobao97/article/details/84881317
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
#include <iostream>
#include <cstdio>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define _unfor(i,a,b) for(int i=a;i>=b;i--)
#define mset(a,val,n) for(int i=0;i<n;i++)a[i]=val;

using namespace std;
typedef long long LL;
//d[i] : 以完全二叉树i号位置为根结点的二叉子堆个数
//s[i] : 以完全二叉树i号位置为根结点的 子树，所含有的节点的个数。
LL d[100005],s[100005],mod=1000000009;
int n;
LL C(int m,int n)
{
    if(!n||!m)
        return 1;
    if(n==1)
        return m;
    return (C(m,n/2)*C(m-n/2,n-n/2)/2)%mod;
}

int main()
{
    cin>>n;
    _unfor(i,n,1)
    s[i]=(i*2<=n?s[i*2]:0)+((i*2+1)<=n?s[i*2+1]:0)+1; //s[i]<=n所以不用取余
    //初始化子树节点个数
    mset(d,1,n+5);
    _unfor(i,n,1)if(i*2+1<=n)
        d[i]= ((C(s[i]-1,s[i*2+1])*d[i*2])%mod*d[i*2+1])%mod;
    cout<<d[1]<<endl;
}
