#include <bits/stdc++.h>
using namespace std;
bool is[1000001];
void solve() {
    int n;cin>>n;
    if(is[n]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    // for(int i = 0;i<100;i++)cout << is[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(is, 0,sizeof(is));
    for(int i = 2;i<=1000000;i++){
        int val = 1;
        for(int j = 1;val + pow(i,j)<=1000000; j++){
            val = val +pow(i,j);
            if(j > 1)is[val] = true;
        }
    }
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}