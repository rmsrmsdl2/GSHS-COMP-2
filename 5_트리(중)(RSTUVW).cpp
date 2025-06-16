#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> vec(1);
bool isoperator(string s)
{
    return s=="+"||s=="-"||s=="*"||s=="/";
}
void in(int x)
{
    if(x>n) return;
    if(isoperator(vec[x])) cout << "(";
    in(2*x);
    cout<<vec[x];
    in(2*x+1);
    if(isoperator(vec[x])) cout << ")";
}
void post(int x)
{
    if(x>n) return;
    post(2*x);
    post(2*x+1);
    cout<<vec[x]<<" ";
}
long long int ans(int x)
{
    if(!isoperator(vec[x])) return stoll(vec[x]);
    long long int l=ans(2*x), r=ans(2*x+1);
    if(vec[x] == "+") return l+r;
    if(vec[x] == "-") return l-r;
    if(vec[x] == "*") return l*r;
    if(vec[x] == "/") return l/r;
}
int main()
{
    while(cin>>s){
        vec.push_back(s);
    }
    n=vec.size()-1;
    in(1);
    cout<<"\n";
    post(1);
    cout<<"\n";
    cout<<ans(1);
    return 0;
} // PROB R 수식 트리로 연산하기 


#include<bits/stdc++.h>
using namespace std;
int n;
string in,pre;
void f(int is,int ie,int ps,int pe){
    if (is>ie || ps>pe) return;
    int idx;
    for (int i=0;i<n;i++){
        if (in[i]==pre[ps]){
            idx=i;
            break;
        }
    }
    int lsize=idx-is;
    f(is,idx-1,ps+1,ps+lsize);
    f(idx+1,ie,ps+lsize+1,pe);
    cout<<pre[ps];
}
int main()
{
    cin>>in;
    cin>>pre;
    n=in.length();
    f(0,n-1,0,n-1);
} // PROB S 트리의 순회


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,dp[21]={1};
    cin>>n;
    for (int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            dp[i]+=(dp[j]*dp[i-1-j]);
        }
    }
    cout<<dp[n];
} // PROB T 트리의 수


#include<bits/stdc++.h>
using namespace std;
int h,n;
void f(int x,int y,int z)
{
    if (n>y){
        f(2*x+1,y+pow(2,z-1),z-1);
    }
    else if (n<y){
        f(2*x,y-pow(2,z-1),z-1);
    }
    else{
        cout<<x;
        return;
    }
}
int main()
{
    cin>>h>>n;
    f(1,int(pow(2,h)),h);
} // PROB U 포화이진트리 (Perfect Binary Tree)의 중위순회


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,ns,t;
    cin>>p>>ns>>t;
    vector<int> par(p+1);
    vector<int> path;
    par[1]=-1;
    while(ns--){
        int x,y,z;
        cin>>x>>y>>z;
        par[y]=x;
        par[z]=x;
    }
    int cur=t;
    while(cur!=-1){
        path.push_back(cur);
        cur=par[cur];
    }
    cout<<path.size()<<"\n";
    for (int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<"\n";
    }
} // PROB V 보물 찾기 


#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
vector<vector<int>> cave(31,vector<int>(31));
vector<int> siz;
bool inrange(int x,int y)
{
    if (x>=0 && x<n && y>=0 && y<n) return true;
    else return false;
}
void dfs (int x,int y)
{
    cave[x][y]=0;
    cnt++;
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (inrange(nx,ny) && cave[nx][ny]==1){
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int j=0;j<n;j++){
            cave[i][j]=s[j]-'0';
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (cave[i][j]==1){
                dfs(i,j);
                siz.push_back(cnt);
                cnt=0;
            }
        }
    }
    sort(siz.begin(),siz.end());
    cout<<siz.size()<<"\n";
    for (int i=0;i<siz.size();i++){
        cout<<siz[i]<<"\n";
    }
} // PROB W 두더지굴
