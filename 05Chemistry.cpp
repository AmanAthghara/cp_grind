#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    map<char,int>mp;
    for(auto it:s)mp[it]++;
    int cnt = 0;
    for(auto it : mp){
        if(it.second % 2 == 1)cnt++;
    }
    if(cnt > k+1){
        cout << "NO"<<endl;
    }else{
        cout << "YES" <<endl;
    }

}

int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}