#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI pair<int,int>
#define PPI pair<int,PI>
#define ps push
#define psb push_back
#define lb(x,v) lower_bound(x.begin(),x.end(),v)-x.begin()
#define ub(x,v) upper_bound(x.begin(),x.end(),v)-x.begin()
#define mxi(x) max_element(x.begin(),x.end())- x.begin()
#define mxe(x) *max_element(x.begin(),x.end())
#define mne(x) *min_element(x.begin(),x.end())
#define mni(x) min_element(x.begin(),x.end())- x.begin()
#define fr(i,n) for(int i = 0;i<n;i++)
#define frn(i,n) for(int i = 0;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define srt(x) sort(x.begin(),x.end());
#define prt(x) for(auto it : x)cout << it << " ";
#define int long long
void solve(){
}
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  int w;cin>>w;
  vector<int> value(n);
  vector<int> weight(n);
  for(int i = 0;i<n;i++){
    cin>>weight[i];
    cin>>value[i];
  }
  int mx = 0;
  for(auto it : value)mx += it ;
  int INF = 1e18;
  vector<int> prev(mx+1, INF);
  prev[0] = 0;
  for(int i = 1;i<=n;i++){
    vector<int> curr = prev;
    for(int p = value[i-1];p <= mx; p++){
        if(prev[p - value[i-1]] == INF )continue;
        curr[p] = min(curr[p] , prev[p - value[i-1]] + weight[i-1]);
    }
    prev = curr;
  }
  int ans = 0;
  for(int i = 0;i<= mx;i++){
    if(prev[i] <= w)ans = i;
  }
  cout << ans << endl;

  return 0;
}