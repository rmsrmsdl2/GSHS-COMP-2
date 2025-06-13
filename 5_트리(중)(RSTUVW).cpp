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
