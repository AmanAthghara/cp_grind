#include<bits/stdc++.h>
using namespace std;
int solve(int i , vector<int> &h,int k, vector<int> &dp){
  int n = h.size();
  if(i >= n)return 0;
  if(dp[i] != -1)return dp[i];
  int take = INT_MAX;
  for(int idx = 1;idx<=k;idx++){
    int take_idx = i + idx;
    if(idx >= n)break;
    take = min(take, abs(h[i] - h[i+idx] ) + solve(i+idx , h , k , dp));
  }
  return dp[i] = take;

  
}
int main(){
  int n;cin>>n;
  int k;cin>>k;
  vector<int> h(n);
  for(auto &it : h)cin>>it;
//   int res = 0;
  vector<int> dp(n+1,INT_MAX);
  dp[0] = 0;
  for(int i = 1;i<n;i++){
    for(int j = 1;j <= k;j++){
      if(i - j < 0)continue;
      dp[i] = min(dp[i] , abs(h[i] - h[i-j] ) + dp[i-j]);
    }
  }
  cout <<dp[n-1] << endl;
}