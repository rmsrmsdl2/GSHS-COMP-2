#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,w,ans=0;
    int sand[101][101],cnt[101][101];
    queue<pair<int,int>> qu;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={0,-1,1,-1,1,0,-1,1};
    cin>>h>>w;
    for (int i=0;i<h;i++){
        string s;
        cin>>s;
        for (int j=0;j<w;j++){
            if (s[j]=='.'){
                sand[i][j]=0;
                qu.push({i,j});
            }
            else{
                sand[i][j]=s[j]-'0';
            }
        }
    }
    while(!qu.empty()){
        int sz=qu.size();
        bool flag=false;
        while(sz--){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for (int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx<1 || ny<1 || nx>=h-1 || ny>=w-1) continue;
                if (sand[nx][ny]==0) continue;
                cnt[nx][ny]++;
                if (cnt[nx][ny]>=sand[nx][ny]){
                    sand[nx][ny]=0;
                    qu.push({nx,ny});
                    flag=true;
                }
            }
        }
        if (flag) ans++;
    }
    cout<<ans;
} // PROB AE 모래성 
