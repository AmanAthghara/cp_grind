#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> num1(n);
    vector<int> num2(n);
    for(auto &it: num1)cin>>it;
    for(auto &it : num2)cin>>it;
    vector<int> diff(n);
    for(int i = 0;i<n;i++){
        diff[i] = num1[i] - num2[i];
    }
    int mx = *max_element(diff.begin(),diff.end());
    vector<int>res;
    for(int i = 0;i<n;i++){
        if(diff[i] == mx){
            res.push_back(i+1);
        }
    }
    sort(res.begin(),res.end());
    cout << res.size() << endl;
    for(auto it : res)cout << it << " ";
    cout << endl;
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