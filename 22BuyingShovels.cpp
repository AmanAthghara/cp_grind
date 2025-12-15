#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;  // adjust to your upper limit
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

vector<int> getPrimeFactors(int n) { 
//this function uses spf to generate all prime factors not unique
    vector<int> res;
    while (n > 1) {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    return res;
}

vector<int> getDivisors(int n){
    vector<int> factors;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            factors.push_back(i);
            if(i * i != n){
                factors.push_back(n / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

vector<int> getDivisorsUsingSPF(int n) {
    unordered_map<int,int> freq;

    // Step 1: get prime factorization using SPF
    while(n > 1){
        freq[spf[n]]++;
        n /= spf[n];
    }

    // Step 2: generate divisors from factorization
    vector<int> divisors = {1};

    for(auto &p : freq){
        int prime = p.first;
        int count = p.second;

        int currentSize = divisors.size();
        long long value = 1;

        // multiply prime^k for k from 1..count and add new divisors
        for(int i = 1; i <= count; i++){
            value *= prime;
            for(int j = 0; j < currentSize; j++){
                divisors.push_back(divisors[j] * value);
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}





void solve() {
    int n;cin>>n;
    int k;cin>>k;
    vector<int> divs = getDivisors(n);
    int lb = *(upper_bound(divs.begin(),divs.end(), k)-1);
    cout << n/lb << endl;
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