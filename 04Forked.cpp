#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b;cin>>a>>b;
    int q1,q2,k1,k2;cin>>q1>>q2>>k1>>k2;
    set<pair<int,int>>st;
    int cnt = 0;
    vector<pair<int,int>>pos = {{a,b},{-a,-b},{-a,b},{a,-b}};
    for(auto [newa,newb] : pos){
        st.insert({q1+newa,q2+newb});
        st.insert({q1+newb,q2+newa});
    }
    for(auto [newa,newb] : pos){
        if(st.count({k1+newa,k2+newb}))cnt++;
        if(a != b)if(st.count({k1+newb,k2+newa}))cnt++;
    }
    cout << cnt << endl;


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