#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
void getnextKMP(string t, int nextKMP[])
{
    int n=t.size();
    nextKMP[0]=-1;
    nextKMP[1]=0;
    for(int i=2; i<=n; i++)
    {

        //t0~ti-1 = t1~ti   ¡­¡­   t0t1 = titi-1; t0 = ti;
        for(int len=i-1; len>=1; len--)
        {
            int j=0;
            for( ; j<len; j++)
            {
//                printf("t[%d]%c cmp t[%d]%c\n", j,t[j] ,i-len+j,t[i-len+j] );
                if(t[j] != t[i-len+j])
                {
                    break;
                }
            }
            if(j==len)
            {
                nextKMP[i] = len;
                break;
            }
        }
        //t0 = ti; t0t1 = titi-1 ¡­¡­   error£¡
//        int j=0;        int max=0;
//        while(i>j && t[i-j] == t[j])
//        {
//            j++;
//            if(j>max) max=j;
//        }
//
//        nextKMP[i+1] = max;

    }
}
void getnextKMP2(string t, int nextKMP[])
{
    int i=0, j=-1;
    nextKMP[0]=-1;
    nextKMP[1]=0;
    //t0~ti-1 = t1~ti   ¡­¡­   t0t1 = titi-1; t0 = ti;
    while(i !=  (int)t.size()-1)
    {
        if(j==-1 || t[i]==t[j])
        {
            i++;
            j++;
            nextKMP[i]=j;
        }
        else
        {
            j=nextKMP[j];
        }
    }
}
int kmp(string s,string  t)
{
    int nextKMP[100]= {0};
//    getnextKMP(t, nextKMP);
    getnextKMP2(t, nextKMP);

    int sin=0, tin=0;//sindex & tindex
    while(sin< (int)s.size() && tin<(int)t.size())
    {
        if(tin ==-1 || s[sin]==t[tin])
        {
            sin++;
            tin++;
        }
        else
        {
            tin = nextKMP[tin];
        }
    }
    if(tin==(int)t.size())
        return sin - tin+1;
    else
        return -1;
}

int main()
{
//    freopen("1.txt", "r", stdin);
    string s, t;
    s="ababaababcb";
    t="ababc";
    cout << kmp(s, t);
    return 0;
}
