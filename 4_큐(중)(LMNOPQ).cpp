#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if (n+1==k){
        int ans=0;
        queue<int> qu;
        qu.push(1);
        while(!qu.empty() && (n>0||m>0)){
            int s=qu.size();
            for (int i=0;i<s;i++){
                qu.pop();
                if (n>0){
                    qu.push(1);
                    qu.push(1);
                    n--;
                }
                else if (m>0){
                    qu.push(1);
                    m--;
                }
            }
            ans++;
        }
        cout<<ans;
    }
    else{
        cout<<"impossible.";
    }
} // PROB L Binary Tree


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> oper(m+1);
    vector<int> endtime(n+1,0);
    vector<vector<int>> res(n+1);
    for (int i=1;i<=m;i++){
        cin>>oper[i];
    }
    for (int i=1;i<=m;i++){
        int pick=1;
        for (int j=2;j<=n;j++){
            if (endtime[j]<endtime[pick]){
                pick=j;
            }
        }
        endtime[pick]+=oper[i];
        res[pick].push_back(i);
    }
    for (int i=1;i<=n;i++){
        for (auto x:res[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
} // PROB M 문백은행 


#include<bits/stdc++.h>
using namespace std;
bool inrange(int x,int y,int n,int m)
{
    if (x>=1 && x<=n && y>=1 && y<=m) return true;
    else return false;
}
int main()
{
    int n,m,k;
    int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
    cin>>n>>m>>k;
    vector<vector<int>> dist(n+1,vector<int>(m+1,-1));
    queue<pair<int,int>> qu;
    while(k--){
        int x,y;
        cin>>x>>y;
        dist[x][y]=1;
        qu.push({x,y});
    }
    while(!qu.empty()){
        int curx=qu.front().first;
        int cury=qu.front().second;
        qu.pop();
        for (int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if (inrange(newx,newy,n,m) && dist[newx][newy]==-1){
                qu.push({newx,newy});
                dist[newx][newy]=dist[curx][cury]+1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
} // PROB N 백신(2차원)


#include<bits/stdc++.h>
using namespace std;
bool inrange(int x,int y,int h,int w)
{
    if (x>=1 && x<=h && y>=1 && y<=w) return true;
    else return false;
}
int main()
{
    int h,w,sx,sy,fx,fy;
    int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
    cin>>h>>w;
    vector<vector<char>> mp(h+1,vector<char>(w+1));
    vector<vector<int>> dist(h+1,vector<int>(w+1,-1));
    queue<pair<int,int>> qu;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            cin>>mp[i][j];
            if (mp[i][j]=='S'){
                sx=i;
                sy=j;
            }
            else if (mp[i][j]=='G'){
                fx=i;
                fy=j;
            }
        }
    }
    dist[sx][sy]=0;
    qu.push({sx,sy});
    while(!qu.empty()){
        int curx=qu.front().first;
        int cury=qu.front().second;
        qu.pop();
        for (int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if (inrange(newx,newy,h,w) && (mp[newx][newy]=='G' || mp[newx][newy]=='.') && dist[newx][newy]==-1){
                qu.push({newx,newy});
                dist[newx][newy]=dist[curx][cury]+1;
            }
        }
    }
    cout<<dist[fx][fy];
} // PROB O 미로찾기 (Large)


#include<bits/stdc++.h>
using namespace std;
bool inrange(int x,int y,int n,int m)
{
    if (x>=1 && x<=n && y>=1 && y<=m) return true;
    else return false;
}
int main()
{
    int n,m,x,y;
    int dx[8]={-2,-2,-1,-1,1,1,2,2};
    int dy[8]={-1,1,-2,2,-2,2,-1,1};
    cin>>n>>m;
    cin>>x>>y;
    vector<vector<int>> dist(n+1,vector<int>(m+1,-1));
    queue<pair<int,int>> qu;
    dist[x][y]=0;
    qu.push({x,y});
    while(!qu.empty()){
        int curx=qu.front().first;
        int cury=qu.front().second;
        qu.pop();
        for (int i=0;i<8;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if (inrange(newx,newy,n,m) && dist[newx][newy]==-1){
                qu.push({newx,newy});
                dist[newx][newy]=dist[curx][cury]+1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
} // PROB P 나이트의 이동


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cur,target,n;
    int d[8]={1,10,100,1000,-1,-10,-100,-1000};
    cin>>cur>>target;
    cin>>n;
    vector<int> dist(10000,-1);
    vector<int> ban(10000,false);
    queue<int> qu;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        ban[x]=true;
    }
    qu.push(cur);
    dist[cur]=0;
    while(!qu.empty()){
        int x=qu.front();
        if (x==target){
            break;
        }
        qu.pop();
        for (int i=0;i<8;i++){
            int newx=(x+d[i]+10000)%10000;
            if (dist[newx]==-1 && !ban[newx]){
                dist[newx]=dist[x]+1;
                qu.push(newx);
            }
        }
    }
    cout<<dist[target];
} // PROB Q 다이얼 비밀번호
