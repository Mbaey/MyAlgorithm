#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<assert.h>
#include<time.h>
using namespace std;

const int N=1<<20; //10 6
long long a[N]= {0}, n=0;

int nlogn2(int l, int r)//MY 。。。分治法
{
    if(l == r) return a[l];
    else if(l > r) {
        printf("竟然l>r？");
        return 0;
    }
    int mid = (r+l)/2;//l+(r-l)/2
    int max1 = max(nlogn2(l, mid),nlogn2(mid+1, r));//(⊙o⊙)…这个bug我找了半节课。竟然是没写max 就写了(,);。。。。
    int mlf=0, mri=0, sum=0;
    for(int i=mid; i>=l; i--)
    {
        sum+=a[i];
        mlf = max(sum, mlf);
    }

    sum=0;
    for(int i=mid+1; i<=r; i++)
    {
        sum+=a[i];
        mri = max(sum, mri);
    }
    int mid_max = mri+mlf;
    return max(max1, mid_max);
}

int nlogn3(int l, int r)//分治法
{
    int sum=0, midSum=0, ls=0, rs=0;
    int center,s1,s2;
    if(l == r){
        sum=a[l];
    }else{
        center=(l+r)/2;
        ls=nlogn3(l, center);
        rs=nlogn3(center+1, r);
        sum=max(ls, rs);
        s1=0; ls=0; rs=0;
        for(int i=center;i>=l; i--){
            ls+=a[i];
            if(ls > s1) s1=ls;
        }
        s2=0;
        for(int i=center+1;i<=r; i++){
            rs+=a[i];
            if(rs > s2) s2=rs;
        }
        sum=max(sum, s1+s2);
    }

    return sum;
}
long long nlogn(int l, int r) { //[l,r)
    if(l+1 == r) return a[l];
    int m = l + (r - l)/2;
    long long max = nlogn(l, m);
    long long v = nlogn(m, r);
    if(v > max) max = v;
    long long lmax = a[m-1], rmax = a[m];
    v = 0;
    for(int i = m-1; i>=l; i--) {v+=a[i]; if(v>lmax) lmax = v;}
    v = 0;
    for(int i = m; i < r; i++) {v+=a[i]; if(v>rmax) rmax = v;}
    if(lmax+rmax > max) max = lmax+rmax;
    return max;
}
int n2()//BF
{
    int maxS=0;

    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=a[j];
            if(maxS < sum)
            {
                maxS=sum;
            }
        }
    }
    return maxS;
}
long long n1()//greedy
{
    long long res=0, max=0;
    for(int i=0; i<n; i++){
        if(res < 0) res = a[i];
        else res += a[i];

        if(res > max) max= res;
    }
    return max;
}

int main()
{
//    printf("%d %f", (int)n, 5/3.0);
//    printf("%d %f", n, 5/3.0);//很坑的bug!!
    freopen("time.txt", "at+", stdout);
    long long startTime,endTime;
    for(int j=10; j<=1000000; j*=10){
        n=j;
        for(int i=0; i< n; i++)
            a[i] = rand() % 1000 - 500;

        startTime = clock();
        int N1= n1();
//        int N2=  n2();
//        int Nlogn= nlogn(0, n);

//        int Nlogn2= nlogn2(0, n-1);
    //    int Nlogn3= nlogn3(0, n-1);
        endTime = clock();
        double t=(double)(endTime-startTime);//        ,
        printf("n=%d, O(N)'s time = %f secends \n", (int)n,(double)(endTime - startTime) / CLOCKS_PER_SEC  );//这个printf都有错？？
//        printf("n=%d, O(N2)'s time = %f secends \n", (int)n,(double)(endTime - startTime) / CLOCKS_PER_SEC  );//这个printf都有错？？
//        printf("n=%d, O(Nlog2n)'s time = %f secends \n", (int)n,(double)(endTime - startTime) / CLOCKS_PER_SEC  );//这个printf都有错？？
//        cout << N2<< endl;
    //    cout << Nlogn<< endl;
    //    cout << Nlogn2<< endl;
    //    cout << Nlogn3<< endl;
    //    assert(n2 == nlogn);
//        assert(N2 == N1);
    }
    return 0;
}
