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
        deg[x]++;
        deg[y]++;
    }
    for (int i=1;i<=n;i++){
        ans=(ans*fac[(i==1)?deg[i]:deg[i]-1])%mod;
    }
    cout<<ans;
} // PROB Z 트리의 깊이우선탐색의 개수 
