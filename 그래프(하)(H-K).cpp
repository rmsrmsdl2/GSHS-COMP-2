#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> graph(101);
vector<bool> visit(101,false);
void dfs(int node)
{
    visit[node]=true;
    cout<<node<<" ";
    for (auto next:graph[node]){
        if (!visit[next]){
            dfs(next);
        }
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(1);
} // PROB H 깊이우선탐색 I
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> graph(2001);
vector<bool> visit(2001,false);
void dfs(int node)
{
    visit[node]=true;
    cout<<node<<" ";
    for (auto next:graph[node]){
        if (!visit[next]){
            dfs(next);
        }
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
} // PROB I 깊이우선탐색 II
