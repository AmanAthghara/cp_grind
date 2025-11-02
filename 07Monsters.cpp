#include <bits/stdc++.h>
using namespace std;
class comp{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
void solve() {
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(auto &it : arr)cin>>it;
    priority_queue<pair<int,int>,vector<pair<int,int>> , comp>pq;
    for(int i = 0;i<n;i++){
        pq.push({arr[i],i});
    }
    vector<int>res;
    while(pq.size() >=2){
        auto [val1,idx1] = pq.top();
        pq.pop();
        auto [val2,idx2] = pq.top();
        pq.pop();
        int x = (val1+val2)/k;
        val1 -= (x*k);
        val1 -= k;

        if(val1>0)pq.push({val1,idx1});
        else res.push_back(idx1);
        pq.push({val2,idx2});

    }
    while(!pq.empty()){
        auto [val,idx] = pq.top();
        pq.pop();
        val -= k;
        if(val > 0)pq.push({val,idx});
        else res.push_back(idx);
    }
    
    for(auto it : res)cout << it << " ";
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