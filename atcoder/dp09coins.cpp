#include <bits/stdc++.h>
using namespace std;

int N;
vector<double> p;




int main() {
    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; i++) cin >> p[i];

    vector<vector<double>>dp(N+1, vector<double>(N+1, 0.0));

    dp[0][0] = 1.0;
    for(int i = 1;i<= N;i++){
      for(int heads = 0;heads <= i;heads++){
        if(heads > 0)dp[i][heads] = (dp[i-1][heads-1] * p[i-1]);
        dp[i][heads] += dp[i-1][heads] * (1.0 - p[i-1]);
      }
    }
    double ans = 0.0;
    for(int i = N/2 + 1; i<=N;i++){
      ans += dp[N][i];
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
