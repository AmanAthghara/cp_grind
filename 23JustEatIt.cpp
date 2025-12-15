#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(auto &it : a)cin>>it;
    ll yassir = accumulate(a.begin(),a.end(),0LL);
    ll local = 0, global = LLONG_MIN;
    int cur_l = 0;
    int left = 0, right = -1;

    for (int i = 0; i < n; i++) {
        if (local + a[i] <= a[i]) {
            local = a[i];
            cur_l = i;
        } else {
            local += a[i];
        }

        if (local > global) {
            global = local;
            left = cur_l;
            right = i;
        }
    }
    // cout << " r - l + 1 = " << right-left+1 << endl;

    if(right - left + 1 == n){
        if(a[left] < a[right])left++;
        else right--;
    }
    ll adir = 0;
    for(int i = left;i<=right;i++){
        adir += a[i];
    }
    if(yassir > adir){
        cout << "YES" << endl;
    }else{
        cout << "NO"<<endl;
    }
    // cout << " the yassir = " << yassir << " the adir =  " << adir <<  endl;
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