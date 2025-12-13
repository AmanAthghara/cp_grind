#include <bits/stdc++.h>
using namespace std;
int getMSBPosition(unsigned int n) {
    if (n == 0) {
        return -1; // Or handle as an error, 0 has no set bits
    }
    int position = 0;
    while (n > 1) {
        n >>= 1; // Right shift by 1
        position++;
    }
    return position;
}

bool isEmpty(vector<int> &a){
    for(auto it : a)if(it)return false;
    return true;
}

void solve() {
    int n;cin>>n;
    int k;cin>>k;
    vector<int> arr(n,0);
    vector<int> mask(22,0);
    for(auto &it : arr){
        cin >> it;
        for(int i = 0;i<=21;i++){
            if(it & (1<<(21-i))){
                mask[i]++;
            }
        }
    }
    int cnt = 0;
    int ans = 0;
    while(cnt < n){
        int val = k;
        for(int i = 0;i<=21;i++){
            if(mask[i]){
                int mval = (1 << (21-i));
                while(mask[i] > 0 and mval <= val){
                    val -= mval;
                    cnt++;
                    mask[i]--;
                }
            }
        }
        ans++;
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