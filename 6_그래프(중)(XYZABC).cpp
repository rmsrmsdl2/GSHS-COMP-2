#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<bool> visit(11,false);
vector<vector<pair<int,int>>> adj(11);
vector<int> path;
vector<int> res;
void dfs(int cur,int sum)
{
    if (cur==n){
        for (auto w:path){
            res.push_back(sum-w+(w/2));
        }
        return;
    }
    for (auto i:adj[cur]){
        int next=i.first;
        int weight=i.second;
        if (visit[next]) continue;
        visit[next]=true;
        path.push_back(weight);
        dfs(next,sum+weight);
        path.pop_back();
        visit[next]=false;
    }
}
int main()
{
    cin>>n>>m>>k;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    visit[1]=true;
    dfs(1,0);
    if (res.size()<k) cout<<"-1\n";
    else{
        sort(res.begin(),res.end());
        cout<<res[k-1]<<"\n";
    }
} // PROB X R&E가는길 공사편 2 


#include<bits/stdc++.h>
using namespace std;
int w,h,cnt=0,ans=0;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
vector<vector<char>> mp(1000,vector<char>(80));
bool inrange(int x,int y)
{
    if (x>=0 && x<h && y>=0 && y<w) return true;
    else return false;
}
void dfs(int x,int y)
{
    cnt++;
    mp[x][y]='.';
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (inrange(nx,ny) && mp[nx][ny]=='*'){
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>w>>h;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin>>mp[i][j];
        }
    }
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (mp[i][j]=='*'){
                dfs(i,j);
                ans=max(ans,cnt);
                cnt=0;
            }
        }
    }
    cout<<ans;
} // PROB Y 위성 사진 


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,ans=1,mod=998244353;
    ll deg[300100]={},fac[300100]={1};
    cin>>n;
    for (int i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    for (int i=1;i<=n-1;i++){
        ll x,y;
        cin>>x>>y;
        deg[min(x,y)]++;
    }
    for (int i=1;i<=n;i++){
        ans=(ans*fac[deg[i]])%mod;
    }
    cout<<ans;
} // PROB Z 트리의 깊이우선탐색의 개수 


#include<bits/stdc++.h>
using namespace std;
int w,h,s1,s2,g1,g2,ans=0;
int oddx[3]={-1,0,1},oddy[3]={1,1,0};
int evenx[3]={0,1,1},eveny[3]={1,1,0};
bool inrange(int x,int y)
{
    if (y%2==1){
        if (x>=1 && x<=w && y>=1 && y<=h) return true;
        else return false;
    }
    else{
        if (x>=1 && x<w && y>=1 && y<=h) return true;
        else return false;
    }
}
void dfs(int x,int y)
{
    if (x==g1 && y==g2){
        ans++;
        return;
    }
    if (!inrange(x,y)) return;
    for (int i=0;i<3;i++){
        if (y%2==1){
            int nx=x+oddx[i];
            int ny=y+oddy[i];
            dfs(nx,ny);
        }
        else{
            int nx=x+evenx[i];
            int ny=y+eveny[i];
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>w>>h;
    cin>>s1>>s2>>g1>>g2;
    dfs(s1,s2);
    cout<<ans;
} // PROB AA 담벼락 이동하기


#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string comp="gshs";
vector<vector<char>> mp(1001,vector<char>(1001));
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
bool inrange(int x,int y)
{
    if (x>=0 && x<n && y>=0 && y<n) return true;
    else return false;
}
void dfs(int x,int y,int len,int dir)
{
    if (len==4){
        ans++;
        return;
    }
    int nx=x+dx[dir];
    int ny=y+dy[dir];
    if (inrange(nx,ny) && mp[nx][ny]==comp[len]){
        dfs(nx,ny,len+1,dir);
    }
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int j=0;j<n;j++){
            mp[i][j]=s[j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (mp[i][j]=='g'){
                for (int k=0;k<8;k++){
                    dfs(i,j,1,k);
                }
            }
        }
    }
    cout<<ans;
} // PROB AB 숨은 글자 찾기


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sx,sy,mx,my,fx,fy;
    int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
    cin>>n;
    vector<vector<char>> mp(n,vector<char>(n));
    vector<vector<int>> dist1(n,vector<int>(n,-1));
    vector<vector<int>> dist2(n,vector<int>(n,-1));
    queue<pair<int,int>> qu;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int j=0;j<n;j++){
            mp[i][j]=s[j];
            if (mp[i][j]=='S'){
                sx=i;sy=j;
            }
            else if (mp[i][j]=='T'){
                mx=i;my=j;
            }
            else if (mp[i][j]=='G'){
                fx=i;fy=j;
            }
        }
    }
    dist1[sx][sy]=0;
    qu.push({sx,sy});
    while(!qu.empty()){
        int curx=qu.front().first;
        int cury=qu.front().second;
        qu.pop();
        for (int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if ((mp[newx][newy]=='T' || mp[newx][newy]=='.') && dist1[newx][newy]==-1){
                qu.push({newx,newy});
                dist1[newx][newy]=dist1[curx][cury]+1;
            }
        }
    }
    dist2[mx][my]=0;
    qu.push({mx,my});
    while(!qu.empty()){
        int curx=qu.front().first;
        int cury=qu.front().second;
        qu.pop();
        for (int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if ((mp[newx][newy]=='G' || mp[newx][newy]=='.') && dist2[newx][newy]==-1){
                qu.push({newx,newy});
                dist2[newx][newy]=dist2[curx][cury]+1;
            }
        }
    }
    cout<<dist1[mx][my]+dist2[fx][fy];
} // PROB AC 경곽이의 보물 찾기 
