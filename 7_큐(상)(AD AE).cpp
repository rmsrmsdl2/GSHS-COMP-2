#include <bits/stdc++.h>
using namespace std;
struct st
{
    int xc,yc,cnt;
};
int main()
{
    int h,w,ans=0;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    cin>>h>>w;
    vector<vector<int>> sand(h,vector<int>(w));
    vector<vector<bool>> visit(h,vector<bool>(w));
    queue<st> qu;
    for (int i=0;i<h;i++){
        string s;
        cin>>s;
        for (int j=0;j<w;j++){
            if (s[j]=='.') sand[i][j]=0;
            else sand[i][j]=s[j]-'0';
        }
    }
    for (int i=1;i<h-1;i++){
        for (int j=1;j<w-1;j++){
            if (sand[i][j]==0) continue;
            int flat1=0;
            for (int k=0;k<8;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if (sand[ni][nj]==0) flat1++;
            }
            if (flat1>=sand[i][j]){
                qu.push({i,j,1});
                visit[i][j]=true;
            }
        }
    }
    while(!qu.empty()){
        int x=qu.front().xc;
        int y=qu.front().yc;
        int z=qu.front().cnt;
        qu.pop();
        sand[x][y]=0;
        ans=max(ans,z);
        for (int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx>=1 && nx<h-1 && ny>=1 && ny<w-1 && sand[nx][ny]!=0 &&!visit[nx][ny]){
                int flat2=0;
                for (int j=0;j<8;j++){
                    int nnx=nx+dx[j];
                    int nny=ny+dy[j];
                    if (sand[nnx][nny]==0) flat2++;
                    if (flat2>=sand[nx][ny]){
                        qu.push({nx,ny,z+1});
                        visit[nx][ny]=true;
                    }
                }
            }
        }
    }
    cout<<ans;
} // PROB AE 모래성 
