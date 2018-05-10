#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;
const int N = 10005,M = 20005;

/*
����˼·
1.
һ��ʼ�뵱Ȼ������UC����
���Ǻ���һ��ͼ�ŷ��֡������Ҫ����ƫ���ϵ��UC�����У�
m >= n*(n-1) / 2�Ų���UNCERTAIN
2.
��������������ж�CONFLICT�ˡ�
�����뵽����ͼ��ʾ������߱�ʾ���ڹ�ϵ
������л��ͳ�ͻ��
�������ͨ��ȱ��

3.
Ȼ����������;
����dfsһ�α���������������
����+break�Ļ� ����ôȷ������뵽�����������Ǹ��ء�

4.
�ٶ���һ�¡�Ҫ����������

*/

struct ccc
{
    int a, b;
    char c;
} ch[N];
int n, m, sum;
//int map[N][N];
bool vis[N];//��¼�Ƿ� �л�
int cnt=0, flag=0;//��¼�Ƿ� ����ͨ
//vector<set<int> > map;
vector<vector<int> > map;
int f[N]= {0}, in[N]= {0};
void dfs1(int a) //memory limit
{
    vis[a]=1;
    cnt++;
    vector<int> next;
    for(int i: map[a])
    {
        in[i]--;
        if(in[i]==0)
            next.push_back(i);
    }
    if(next.size()>1)
    {
        flag=1;
    }
    for(int i: next)
    {
        dfs1(i);
    }

}


int find(int a)
{
    return f[a]==a ? a : f[a]=find(f[a]);
}
bool Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return 0;
    f[b]=a;
    return 1;
}
void top_order()
{

    bool uncertain=false;
    queue<int> q;
    //�����Ϊ0�����Ǹ��Ľڵ��������У�
    //�������еĽ��������ڣ���˵����Ϣ��ȫ
    for(int i=0;i<N;i++)
    if(in[i]==0&&find(i)==i)
    q.push(i);
    while(!q.empty())
    {
        //ȷ����Ϣ��ȫ�����ǲ�����������ʱ�������ǳ�ͻ
        if(q.size()>1)uncertain=true;
        int cur = q.front();
        q.pop();
        sum--;
        for(int i=0;i<map[cur].size();i++)
        {
            if(--in[map[cur][i]]==0)
            q.push(map[cur][i]);
        }
    }
    if(sum>0)printf("CONFLICT\n");
    else if(uncertain)printf("UNCERTAIN\n");
    else printf("OK\n");
}

int main()
{
    //freopen("1.txt", "r", stdin);

    while(cin >> n >> m)
    {
        sum=n;
        map.clear();
        map.resize(n);
        fill(vis, vis+n, 0);
        fill(in, in+n, 0);
        for(int i=0; i<n; i++) f[i]=i;
        int a, b;
        char c;
        flag=0;
        cnt=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d %c %d", &ch[i].a, &ch[i].c, &ch[i].b);
            if(ch[i].c=='=') //����Ʒ
            {
                if(Union(ch[i].a,ch[i].b)){
                    cnt++;
                    sum--;
                }
            }

        }
        for(int i=0; i<m; i++)
        {
            a = find(ch[i].a);
            b = find(ch[i].b);
            c = ch[i].c;
            if(c=='>')
            {
//                if(!map[a].count(b))
                    in[b]++;
                map[a].push_back(b);
            }
            else if(c=='<')
            {
//                if(!map[b].count(a))
                    in[a]++;
                map[b].push_back(a);
            }
        }

//        for(int i=0; i<n; i++)
//        {
//            for(int in : map[i])
//            {
//                printf("%d ", in);
//            }
//            printf("\n");
//        }
        top_order();
//        int root=-1, rt_cnt=0;
//        for(int i=0; i<n; i++)
//        {
//            int now=f[i];
//            if(in[now]==0)
//            {
//                root=now;
//                rt_cnt++;
//            }
//        }
//        if(root==-1)
//        {
//            printf("CONFLICT\n");
//            continue;
//        }
//        dfs1(root);
//        if(cnt< n && rt_cnt==1)
//        {
//            printf("CONFLICT\n");
//        }
//        else if(flag==1 || rt_cnt>1)
//        {
//            printf("UNCERTAIN\n");
//        }else{
//            printf("OK\n");
//        }

    }
    return 0;
}
