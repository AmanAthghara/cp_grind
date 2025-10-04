#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;cin>>n;
    vector<vector<long long>>arr(n);
    for(long long i = 0;i<n;i++){
        long long m;cin>>m;
        while(m--){
            long long c;cin>>c;
            arr[i].push_back(c);
        }
    }
    for(vector<long long> &ar:arr){
        sort(ar.begin(),ar.end());
    }
    vector<long long>seconds;
    long long minimum = LLONG_MAX;
    for(auto it : arr){
        seconds.push_back(it[1]);
        minimum = min(it[0],minimum);
    }
    sort(seconds.begin(),seconds.end());
    long long sumSec = minimum;
    for(long long i = 1;i<n;i++){
        sumSec += seconds[i];
    }
    cout << sumSec << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}