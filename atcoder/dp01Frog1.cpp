#include<bits/stdc++.h>
using namespace std;
int solve(int i , vector<int> &h, vector<int> &dp){
  int n = h.size();
  if(i >= n)return 0;
  if(dp[i] != -1)return dp[i];
  int take1 = INT_MAX;
  if(i + 1 <= n)take1 = abs(h[i-1] - h[i]) + solve(i+1, h , dp );
  int take2 = INT_MAX;
  if(i + 2 <= n)take2 = abs(h[i-1] - h[i+1]) + solve(i+2 , h , dp);
  return dp[i] =  min(take1, take2);
  
}
int main(){
  int n;cin>>n;
  vector<int> h(n);
  for(auto &it : h)cin>>it;
  int res = 0;
  vector<int> dp(n+1,INT_MAX);
  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);
  for(int i = 2;i<n;i++){
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]) , dp[i-2] + abs(h[i] - h[i-2]));
  }
  cout << dp[n-1] << endl;
}