#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;  // adjust to your upper limit
vector<int> spf(MAXN + 1);
void buildSPF(int n) {
    for (int i = 0; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}
vector<int> getFactorsUsingSPF(int n) {
    vector<int> res;
    while (n > 1) {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    return res;
}

vector<int> getFactors(int n){
    vector<int> factors;
    
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            factors.push_back(i);
            // If i is not the square root, then n/i is also a factor
            if(i * i != n){
                factors.push_back(n / i);
            }
        }
    }
    // Sort the factors in ascending order (optional, but often desired)
    sort(factors.begin(), factors.end());
    return factors;
}



void solve() {
    int n;cin>>n;
    vector<int> arr(n);
    map<int,int>mp;
    bool allZero = true;
    for(auto &it : arr){
        cin>>it;
        if(it)allZero = false;
        for(int i = 30;i>=0;i--){
            if(it & (1<<i))mp[i]++;
        }
    }
    int res = 0;
    for(auto it : mp){
        if(res == 0)res = it.second;
        res = gcd(it.second, res);
    }
    if(allZero){
        for(int i = 1;i<=n;i++){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    vector<int> fact = getFactors(res);
    for(auto it : fact)cout << it << " ";
    cout << endl;
}

int main() {
    buildSPF(200002);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}