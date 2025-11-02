#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve() {
    // long long n;cin>>n;
    string s;cin>>s;
    int n = s.size();
    long long ans = 1;
    int diff = 1;
    int cnt = 1;
    for(int i = 1;i<n;i++){
        if(s[i] != s[i-1]){
            ans = (ans * cnt) % MOD;
            diff++;
            cnt = 1;
        }else{
            cnt++;
        }
    }
    ans = (ans*cnt)%MOD;
    for(int i = 1; i <= (n - diff);i++){
        ans = (ans * i)%MOD;
    }
    cout << (n - diff) << " " << ans << endl;


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