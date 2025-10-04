#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n , m;cin>>n>>m;
    string s,x;cin>>x>>s;
    int cnt = -1;
    int ans = 0;
    while(x.size() <= 200){
        if(x.size() < s.size()){
            ans++;
            x = x + x;
        }else if(x.find(s) == string::npos){
            x = x+x;
            ans++;
        }else if(x.find(s) != string::npos){
            cnt=1;
            break;

        }
    }
    if(cnt == 1)cout << ans << endl;
    else cout << -1<<endl;
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