//#include <iostream>
//#include <cstdio>
//#include <set>
//#include <algorithm>
////#include <climits>
//
//using namespace std;
//
//int graph[505][505]={0}, vis[505]={0};
//bool flag=true;
//vector<int> color(505);
//int v, e, k, n;
//void dfs(int in){
//    vis[in] = 1;
//    for(int i=1; i<=v; i++){
//        if(graph[in][i] != 0 && color[i] == color[in])
//            flag=false;
//    }
//    for(int i=1; i<=v; i++)
//        if( !vis[i] && graph[in][i]){
//            dfs(i);
//        }
//
//}
//int main()
//{
//    freopen("1.txt", "r", stdin);
//
//    cin >> v >> e>> k;
//
//    int ti, tj;
//    for(int i=0; i<e; i++) {
//        cin >> ti >> tj;
//        graph[ti][tj]=1;
//        graph[tj][ti]=1;
//    }
//    cin >> n;
//    set<int> cnt;
//    for(int i=0; i<n; i++){
//        cnt.clear();
//        flag  =true;
//        for(int j=1; j<=v; j++){
//            int temp;
//            cin >> temp;
//            color[j] = temp;
//            cnt.insert(temp);
//        }
//        if(cnt.size() == k){
//            fill(vis, vis+505, 0);
//            for(int j=1; j<=v; j++)//dfs总忘了图不连通的例子
//                if(!vis[j])
//                    dfs(j);
//            if(flag){
//                cout << "Yes" << endl;
//            }else
//                cout << "No" << endl;
//        }else{
//                cout << "No" << endl;
//        }
//    }
//
//
//    return 0;
//}
