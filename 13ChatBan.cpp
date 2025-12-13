#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll firstK(ll val){
    return 1LL * val * (val+1) / 2;
}
void solve() {
    ll k,x;cin>>k>>x;
    ll l = 1,r = (2*k) - 1;
    ll ans = 2*k - 1;
    while(l <= r){
        ll mid = (l+r)/2;
        ll val = 0;
        if(mid <= k){
            val = firstK(mid);
        }else{
            ll top = firstK(k);
            ll bottom = firstK(k-1) - firstK(2*k-1 - mid);
            val = top + bottom;
        }
        if(val >= x){
            ans = mid;
            r = mid-1;
        }else{
            l = mid + 1;
        }
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