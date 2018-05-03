#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int N=100;
const int inf=1<<20;
int cty[N][N]={0};
int n, m, s;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n>>m>>s;
    int a, b, w;
    for(int i=0; i<m; i++){
        cin>>a>>b>>w;
        cty[a][b]=w;
        cty[b][a]=w;
    }
    for(int i=1; i<=n; i++) cty[i][i]=inf;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", cty[i][j]);
        }printf("\n");

    }
    bool vis[N]={0};
    //loop n-1
    vis[s]=1;
//    vector<pair<int, int> > res;
    int len=0, u=s, v=0;
    for(int i=1; i<n; i++){
        int min=inf;
        for(int j=1; j<=n; j++){
            if(!vis[j]&&cty[u][j]!=0 && cty[u][j]<min){
                v=j;
                min=cty[u][j];
            }
        }
        vis[v]=1;
        len+=cty[u][v];
//        res.push_back(make_pair(j, cty[i][j]));
        printf(" -%d->%d", cty[u][v], v);

        u=v;
    }
    len+=cty[u][s];
    printf(" -%d->%d", cty[u][s], s);
//    res.push_back(make_pair(j, cty[i][j]));
    printf("\ntsp Len£º%d", len);
    return 0;
}
/*
5 10 1
1 2 3
1 3 3
1 4 2
1 5 6
2 3 7
2 4 3
2 5 2
3 4 2
3 5 5
4 5 3
*/
