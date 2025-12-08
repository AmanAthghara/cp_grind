#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>&adj,int i, string &s,int &ans){
    if(adj[i].size()==0)return (s[i-1] == 'W'? 1:-1);
    int cnt = 0;
    for(auto it : adj[i]){
        cnt += dfs(adj,it,s,ans);
    }
    cnt += (s[i-1] == 'W' ? 1 : -1);
    if(cnt == 0)ans++;
    return cnt;
}


void solve() {
    int ans = 0;
    int n;cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i = 0;i<n-1;i++){
        int t;cin>>t;
        adj[t].push_back(i+2);
    }
    string s;cin>>s;
    dfs(adj,1,s,ans);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}