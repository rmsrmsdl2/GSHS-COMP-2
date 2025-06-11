#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cur=1;
    queue<int> qu;
    cin>>n>>k;
    for (int i=1;i<=n;i++) qu.push(i);
    while(!qu.empty()){
        for (int i=1;i<=k-1;i++){
            qu.push(qu.front());
            qu.pop();
        }
        cout<<qu.front()<<" ";
        qu.pop();
    }
} // PROB A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> pos(m+1);
    for (int i=1;i<=n;i++){
        int t;
        cin>>t;
        pos[t].push_back(i);
    }
    for (int i=1;i<=m;i++){
        cout<<pos[i].size()<<" ";
        for (int x:pos[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
} // PROB B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,k,mod=1000000007;
    queue<int> qu;
    cin>>n>>m>>k;
    qu.push(1);
    while(k--){
        ll x=qu.front()%mod;
        qu.pop();
        qu.push((x*n)%mod);
        qu.push((x*m)%mod);
    }
    cout<<qu.front()%mod;
} // PROB C
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    queue<int> qu;
    cin>>n>>m;
    vector<int> dist(n+1,-1);
    for (int i=0;i<m;i++){
        int x;
        cin>>x;
        qu.push(x);
        dist[x]=1;
    }
    while(!qu.empty()){
        int k=qu.front();
        qu.pop();
        if (k-1>=1 && dist[k-1]==-1){
            qu.push(k-1);
            dist[k-1]=dist[k]+1;
        }
        if (k+1<=n && dist[k+1]==-1){
            qu.push(k+1);
            dist[k+1]=dist[k]+1;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
} // PROB D
