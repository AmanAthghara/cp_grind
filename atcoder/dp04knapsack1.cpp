#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> points , vector<int> weights , int i , int weight , vector<vector<long long>>&dp){
  if( i >= points.size())return 0;
  if(dp[i][weight] != -1)return dp[i][weight];
  long long skip = solve(points , weights , i+1 , weight , dp);
  long long take = 0;
  if(weight >= weights[i] ) take = points[i] + solve(points , weights, i+1 ,weight - weights[i] , dp);
  return dp[i][weight] = max(take , skip);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  int w;cin>>w;
  vector<vector<long long>>dp(n+1 , vector<long long>(w+1, 0));
  vector<long long> points(n);
  vector<long long> weights(n);
  for(int i = 0;i < n;i++){
    cin >> weights[i];
    cin >> points[i];
  }
  for(long long i = 1;i<=n;i++){
    for(long long cap = 0; cap <= w;cap++){
      dp[i][cap] = dp[i-1][cap];
      if(cap >= weights[i-1])
      dp[i][cap] = max(dp[i][cap], points[i-1] + dp[i-1][cap - weights[i-1]]);
    }
  }
  cout << dp[n][w];
  


  return 0;
}

