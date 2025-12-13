#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m;cin>>n>>m;
    vector<int> k(n);
    for(auto &it : k)cin>>it;
    vector<int> c(m);
    for(auto &it : c)cin>>it;
    for(int i = 0;i<n;i++){
        if(k[i] <= m)c.push_back(c[k[i]-1]);
    }
    sort(c.begin(),c.end());
    long long ans = 0;
    for(int i = 0;i<n;i++){
        ans += c[i];
    }
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