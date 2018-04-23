#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

const int N=100, M=10000, inf = 1<<20; //10 6

int n, m, s, en;
/*
�ڽ����� ��������
firstE[i]��ʾ��i����� ��һ�����ߵ���š�
nextE[e]��ʾ��e���ߵ� ��һ���ߵ���š�
*/
int u[N]={0},v[N]={0},w[N]={0};
int firstE[N]={0},nextE[M]={0};


int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n>>m>>s>>en;
    fill_n(firstE, n, -1);
    for(int i=0; i<m; i++){
        cin >>u[i]>>v[i]>>w[i];
        nextE[i] = firstE[u[i]];
        firstE[u[i]] = i;
    }
    //test input
    for(int i=0; i<n; i++){
        printf("%d", i);
        for(int e=firstE[i]; e!=-1; e=nextE[e]){
            printf(" -%d->%d", w[e], v[e]);
        }cout << endl;
    }
    queue<int> que;
    bool vis[N] = {0};
    int cost[N]={0}, path[N]={0};
    //�о����ϵĴ�����bug����������׶κͶ�����Ų���Ӧ�Ļ�,�ͳ�����.
    fill_n(cost, n, inf);
    que.push(s); vis[s]=1;
    cost[s]=0, path[s]=-1;
    while(!que.empty()){
        int i = que.front(); que.pop();
        for(int e=firstE[i]; e!=-1; e=nextE[e]){
            if(cost[v[e]] > cost[u[e]] + w[e]){//��һ���׶�
                cost[v[e]] = cost[u[e]] + w[e];
                path[v[e]] = u[e];
                if(!vis[v[e]]){//��ֹ�ظ�����
                    que.push(v[e]);
                    vis[v[e]] = 1;
                }
            }
        }
    }
    int e=en;
    cout << e;
    while(path[e] != -1){
         printf(" <--%d",  path[e]);
         e = path[e];
    }
    return 0;
}

/*
10 18 0 9
0 1 4
0 2 2
0 3 3
1 4 9
1 5 8
2 4 6
2 5 7
2 6 8
3 5 4
3 6 7
4 7 5
4 8 6
5 7 8
5 8 6
6 7 6
6 8 5
7 9 7
8 9 3
*/
