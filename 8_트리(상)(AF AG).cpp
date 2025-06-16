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


