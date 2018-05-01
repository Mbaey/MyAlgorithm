#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=100, maxm=5000, inf=1<<20;
int n, m, k;
//邻接矩阵
int g[maxn][maxn]={0};
/*
邻接链表  class edge,graph太累了
1.入邻接表
first[node] 里存放node节点的第一条出边
next[e]里存放下一条边
2.出表
first[node] 里存放node节点的第一条入边
next[e]里存放下一条边
*/
int u[maxm]={0},v[maxm]={0},w[maxm]={0};
int first_e[maxn]={0}, next_e[maxm]={0};

int cost[maxn]={0}, path[maxn]={0};
int main()
{
    freopen("1.txt", "r", stdin);
    cin>>n>>m>>k;
    //input
    fill_n(first_e, m+5, -1);
    for(int i=0;i<m; i++){
        cin >> u[i]>>v[i]>>w[i];
        next_e[i] = first_e[v[i]];
        first_e[v[i]] = i;
    }
    //test input
    for(int i=0; i<n; i++){
        printf("%d:", i);
        for(int e=first_e[i]; e!=-1; e=next_e[e]){
            printf(" <-%d-%d", w[e], u[e]);
        }printf("\n");
    }


    fill_n(cost+1, n, inf);fill_n(path, n, -1);
    cost[0]=0;
    for(int j=1; j<n; j++){
        for(int e=first_e[j]; e!=-1; e=next_e[e]){
            if(cost[u[e]] + w[e] < cost[j]){
                cost[j] = cost[u[e]] + w[e];
                path[j] = u[e];
            }
        }
    }

    int i=k;
    printf("最短路径是：\n");
    cout << i;
    while(path[i] != -1){
        printf(" <-%d-%d", cost[i], path[i]);
        i=path[i];
    }
    return 0;
}

/*
10 18 9
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