#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&a, int idx , int prev , vector<vector<int>>&dp){
  if(idx >= a.size())return 0;
  int take = 0;
  if(dp[idx][prev] != -1)return dp[idx][prev];
  for(int i= 0;i<3;i++){
    if(i == prev)continue;
    take = max(take ,a[idx][i] + solve(a, idx + 1, i , dp));
  }
  return dp[idx][prev] = take;
}




int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  vector<vector<int>>a(n,vector<int>(3,0));
  for(auto &it : a){
    for(auto &i : it)cin>>i;
  }
  vector<vector<int>>dp(n+1 , vector<int> (4,0));
  int res = 0;
  for(int i = 0;i<3;i++){
    dp[0][i]= a[0][i];
  }
  for(int i=1;i<n;i++){
    for(int act = 0;act < 3;act++){
      for(int prev = 0;prev < 3;prev++){
        if(act == prev)continue;
        dp[i][act] = max(dp[i][act] , dp[i-1][prev] + a[i][act]);
      }
    }
  }
  cout << max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]}) << endl;

  return 0;
}