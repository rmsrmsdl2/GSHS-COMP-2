#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
vector<int> pre,post;
ll ans=1;
void solve(int prel,int prer,int postl,int postr){
    if(postl>=postr||prel>=prer) return;
    if(post[postr]!=pre[prel]) return;
    if(pre[prel+1]==post[postr-1]){
        ans<<=1;
        solve(prel+1,prer,postl,postr-1);
    }else{
        int lp=-1;
        for(int i=postl;i<=postr;i++){
            if(post[i]==pre[prel+1]){
                lp=i;
                break;
            }
        }
        int lsz=lp-postl+1;
        solve(prel+1,prel+lsz,postl,lp);
        solve(prel+lsz+1,prer,lp+1,postr-1);
    }
}
int main(){
    cin>>n;
    pre.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>post[i];
    solve(0,n-1,0,n-1);
    cout<<ans<<"\n";
    return 0;
} // PROB AF 중위순회의 개수 


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,mod=9901,dp[201][101]={};
    cin>>n>>k;
    dp[1][1]=1;
    for (int i=3;i<=n;i+=2){
        for (int j=2;j<=k;j++){
            for (int l=1;l<i;l+=2){
                int r=i-l-1;
                for (int hl=1;hl<j;hl++){
                    for (int hr=1;hr<j;hr++){
                        if (max(hl,hr)==j-1){
                            dp[i][j]+=(dp[l][hl]*dp[r][hr])%mod;
                            dp[i][j]%=mod;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[n][k];
} // PROB AG Tree count


