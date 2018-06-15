#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
//TSP问题。分支限界法
using namespace std;
const int N=10, inf = (1<<31) - 1;//max_int

int n, m, arc[N][N]={0};
int high, low, cnt=0;

struct Node{
    int s, e;
    vector<int> path;
    vector<bool> vis;
    int sum, lb;
    bool operator < (const Node &x) const{//由于最短TSP路径。所以lb小的优先级高
        return lb > x.lb;
    }
    void display(){
        printf("*****************\n");
        printf("start city=%d , end city=%d\n", s, e);
        printf("path is : ");
        for(int i : path) cout << i << " ";
        cout << endl;
//        printf("Vis is : \n");
//        for(int i=0; i<n; i++) {
//            printf("%d is ", i); cout << vis[i]<< endl;
//        }
        printf("sum=%d , estimate=%d\n", sum, lb);

    }
};
priority_queue<Node> pq;
int high_bound(){//greedy
    int now=0, res=0;
    bool vis[N]={0}; vis[0]=1;
    for(int i=0; i<n-1; i++){
        int minInd, minW=inf;
        for(int j=0; j<n; j++){
            if(arc[now][j]<minW && !vis[j]){
                minW=arc[now][j]; minInd=j;
            }
        }
        now = minInd;
        vis[minInd]=1;
        res += minW;
    }
    return res+arc[now][0];
}
int low_bound(){
    int res=0;
    for(int i=0; i<n; i++){
        int minW=inf;
        for(int j=0; j<n; j++){
            if(arc[i][j]<minW ){
                minW=arc[i][j];
            }
        }
        res += minW;
    }
    return res;
}
int get_low_easy(const Node &a){//没啥信息的 限界函数
    int res=a.sum;
    int minW=inf;
    for(int j=0; j<n; j++){
        if(arc[a.e][j]<minW ){
            minW=arc[a.e][j];
        }
    }
    res += minW;
    for(int i=0; i<n; i++){
        if(!a.vis[i]){
            int minW=inf;
            for(int j=0; j<n; j++){
                if(arc[i][j]<minW ){
                    minW=arc[i][j];
                }
            }
            res += minW;
        }
    }
    return res;
}
int dist[N]={0};
int get_low(const Node &a){//有点厉害了
    int res=a.sum*2;
    if(a.s!=a.e){
        int minW=inf;
        for(int j=0; j<n; j++){
            if(arc[a.e][j]<minW ){
                minW=arc[a.e][j];
            }
        }
        res += minW;
        minW=inf;
        for(int j=0; j<n; j++){
            if(arc[a.s][j]<minW ){
                minW=arc[a.s][j];
            }
        }
        res += minW;
    }else{
        memcpy(dist, arc[a.s],n*sizeof(int));
        sort(dist, dist+n);
        res += dist[0]+dist[1];
    }

    for(int i=0; i<n; i++){
        if(!a.vis[i]){
            memcpy(dist, arc[i],n*sizeof(int));
            sort(dist, dist+n);
            res += dist[0]+dist[1];
        }
    }
    return (res+1)/2;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int t,a,b;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arc[i][i] = inf;
    for(int i=0; i<m; i++){
        cin >> a>>b>>t;
        arc[a][b]=t;
        arc[b][a]=t;
    }

    high = high_bound();//贪心发求上界
    low = low_bound();//先用信息量不太大的 估值函数

    Node tmp;
    tmp.s=0; tmp.e=0; tmp.sum=0;
    tmp.vis.resize(n);tmp.vis[0]=1;
    tmp.path.push_back(0); tmp.lb = get_low(tmp);
//    cout << tmp.lb;
    pq.push(tmp);
    while(!pq.empty()){
        tmp= pq.top(); pq.pop();
        cout << cnt++ << endl;
        tmp.display();
        int now=tmp.e;
        if(tmp.path.size()==n){//找到最优叶子节点
            tmp.sum += arc[now][0];
            if(tmp.sum <= pq.top().lb)
                break;
        }
        for(int i=0; i<n; i++){
            if(arc[now][i]!=inf&& !tmp.vis[i]){//可以走到i城市
                Node next;
                next.s=tmp.s; next.e=i; next.sum=tmp.sum+arc[now][i];
                next.vis = tmp.vis; next.vis[i]=1;//解决标记
                next.path = tmp.path; next.path.push_back(i);//解决路径
                next.lb= get_low(next);//估值函数
//                next.display();
                if(next.lb <= high){//比high还大的就剪掉
                    if(next.lb > low) low = next.lb;//更新low
                    pq.push(next);
                }
            }

        }
    }
    tmp.display();
//    cout << tmp.sum;



    return 0;
}
/*
{test priority_queue
    Node tmp;
    tmp.lb=1;
    pq.push(tmp);
    Node tmp1;
    tmp1.lb=10;
    pq.push(tmp1);
    cout << pq.top().lb<< endl;
}
{test inf high_bound() low_bound() get_low()
    cout << inf;
    cout << high;
    cout << low;
    cout << tmp.lb;
}
*/
/*input 1.txt
5 10
0 1 3
0 2 1
0 3 5
0 4 8
1 2 6
1 3 7
1 4 9
2 3 4
2 4 2
3 4 3
*/