AH는 다른 분들의 코드가 훨씬 좋은 것 같아서 그거 참고하시면 됩니다 


#include<bits/stdc++.h>
using namespace std;

int h,w,ans;
char board[50][51];
int dist[50][50];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>board[i];

    deque<pair<int,int>> qu;
    memset(dist,0x3f,sizeof(dist));
    dist[h-1][w-1]=1;
    qu.push_back({h-1,w-1});

    while(!qu.empty()){
        int x=qu.front().first, y=qu.front().second;
        qu.pop_front();
        for(int d=0;d<4;d++){
            int nx=x+dx[d], ny=y+dy[d];
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
            if(board[nx][ny]=='.') continue;
            int w=board[nx][ny]!=board[x][y];
            if(dist[nx][ny]>dist[x][y]+w){
                dist[nx][ny]=dist[x][y]+w;
                if(w) qu.push_back({nx,ny});
                else qu.push_front({nx,ny});
            }
        }
    }

    int res=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(dist[i][j]!=0x3f3f3f3f) res=max(res,dist[i][j]);
        }
    }
    cout<<res<<"\n";
    return 0;
} // PROB AI
