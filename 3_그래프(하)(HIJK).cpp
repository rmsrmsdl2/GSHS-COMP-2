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
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<bool> visit(n+1,false);
    queue<int> qu;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    qu.push(1);
    visit[1]=true;
    while(!qu.empty()){
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for (auto next:graph[node]){
            if (!visit[next]){
                visit[next]=true;
                qu.push(next);
            }
        }
    }
} // PROB J 너비우선탐색 I
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<bool> visit(n+1,false);
    queue<int> qu;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    qu.push(1);
    visit[1]=true;
    while(!qu.empty()){
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for (auto next:graph[node]){
            if (!visit[next]){
                visit[next]=true;
                qu.push(next);
            }
        }
    }
} // PROB K 너비우선탐색 II 
