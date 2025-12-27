#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;
    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            dp[v] = max(dp[v], dp[u] + 1);
            if(--indeg[v] == 0)
                q.push(v);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
