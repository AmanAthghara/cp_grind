#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;i++){
        int k;cin>>k;
        vector<int> val(k);
        for(int j=0;j<k;j++){
            int t;cin>>t;
            val[j] = t - j + 1;
        }
        sort(val.begin(),val.end());
        a.push_back({val[k-1],k});
    }
    sort(a.begin(),a.end());
    int res = a[0].first;
    int prev = 0;
    for(auto it : a){
        res = max(res , it.first - prev);
        prev += it.second;
    }
    cout << res << endl;
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