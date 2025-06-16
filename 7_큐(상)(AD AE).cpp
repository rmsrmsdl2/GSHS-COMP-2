#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,k;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int dist[401][401];
int main()
{
    cin>>n>>m>>x>>y>>k;
    x--; y--;
    int minx=max(0,x-2*k), maxx=min(n-1,x+2*k);
    int miny=max(0,y-2*k), maxy=min(m-1,y+2*k);
    int h=maxx-minx;
    int w=maxy-miny;
    x-=minx; y-=miny;
    if (k > 0){
        bool stuck=true;
        for(int d=0;d<8;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0 || nx>h || ny<0 || ny>w) continue;
            stuck=false;
            break;
        }
        if (stuck){
            cout<<1LL*n*m<<"\n";
            return 0;
        }
    }
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            dist[i][j]=-1;
        }
    }
    queue<pair<int,int>> qu;
    qu.push({x,y});
    dist[x][y]=0;
    while(!qu.empty()){
        int cx=qu.front().first, cy=qu.front().second;
        qu.pop();
        for(int d=0;d<8;d++){
            int nx=cx+dx[d], ny=cy+dy[d];
            if(nx<0||nx>h||ny<0||ny>w) continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[cx][cy]+1;
            qu.push({nx,ny});
        }
    }
    int cnt=0;
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            if(dist[i][j]!=-1 && dist[i][j]<=k && dist[i][j]%2==k%2){
                cnt++;
            }
        }
    }
    cout<<1LL*n*m-cnt<<"\n";
} // PROB AD 나이트의 이동 2


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,w,ans=0;
    int sand[1001][1001],cnt[1001][1001];
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
