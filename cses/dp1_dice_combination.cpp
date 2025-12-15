
/* 

problem statement : 

Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
Each throw produces an outcome between 1 and  6.

For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

*/




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

//also less optimized version
ll solve(ll n , vector<ll>&dp){
    if(n < 0)return 0;
    if(n == 0)return 1;
    if(dp[n] != -1)return dp[n];
    ll sum = 0;
    for(int i = 1;i<=6;i++){
        if(n < i)break;
        sum += solve(n-i,dp)%MOD;
    }
    return dp[n] = sum%MOD;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<ll> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int d=1; d<=6 && d<=i; ++d)
            dp[i]=(dp[i]+dp[i-d])%MOD;
    }
    cout<<dp[n]<<"\n";
}
