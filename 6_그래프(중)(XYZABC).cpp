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
