#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> nums(n);
    for(auto &it : nums)cin>>it;
    // sort(nums.begin(),nums.end());
    vector<int> res;
    for(int i = 0;i<n;i++){
        int l = 1, r = i+1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[i - mid + 1] >= mid){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        res.push_back(r);
    }
    for(auto it : res ) cout << it << " " ;
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