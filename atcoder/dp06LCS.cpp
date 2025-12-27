#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI pair<int,int>
#define PPI pai*r<int,PI>
#define ps push
#define psb push_back
#define lb(x,v) lower_bound(x.begin(),x.end(),v)-x.begin()
#define ub(x,v) upper_bound(x.begin(),x.end(),v)-x.begin()
#define fr(i,n) for(int i = 0;i<n;i++)
#define frn(i,n) for(int i = 0;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define srt(x) sort(x.begin(),x.end());
#define prt(x) for(auto it : x)cout << it << " ";
#define mxi(x) max_element(x.begin(),x.end())- x.begin();
#define mxe(x) *max_element(x.begin(),x.end());
#define mne(x) *min_element(x.begin(),x.end());
#define mni(x) min_element(x.begin(),x.end())- x.begin();



int solve(string &s , string &t , int i, int j, vector<vector<int>>&dp){
    if(i >= s.length() or j >= t.length())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = 1 + solve(s, t , i+1, j+1,dp);
    }
    int skipI = solve(s , t , i+1 , j,dp);
    int skipJ = solve(s , t , i , j+1 , dp);
    return dp[i][j] = max(skipJ , skipI);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans.push_back(s[i-1]);
            i--; j--;
        }else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else{
            j--;
        } 
    }
    
    reverse(ans.begin(),ans.end());
    cout << ans;
  return 0;
}