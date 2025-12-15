#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;

        int l = x, r = x;

        for (int i = 0; i < m; i++) {
            int L, R;
            cin >> L >> R;

            if (max(l, L) <= min(r, R)) {
                l = min(l, L);
                r = max(r, R);
            }
        }

        cout << (r - l + 1) << '\n';
    }
    return 0;
}
