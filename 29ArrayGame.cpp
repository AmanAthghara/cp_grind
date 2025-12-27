#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI pair<int,int>
#define PPI pair<int,PI>
#define ps push
#define psb push_back
#define lb(x,v) lower_bound(x.begin(),x.end(),v)-x.begin()
#define ub(x,v) upper_bound(x.begin(),x.end(),v)-x.begin()
#define fr(i,n) for(int i = 0;i<n;i++)
#define frn(i,n) for(int i = 0;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define srt(x) sort(x.begin(),x.end());
#define prt(x) for(auto it : x)cout << it << " ";
#define mxi(x) max_element(x.begin(),x.end())- x.begin();
#define mxe(x) *max_element(x.begin(),x.end());
#define mne(x) *min_element(x.begin(),x.end());
#define mni(x) min_element(x.begin(),x.end())- x.begin();
#define int long long
void solve(){
  int n;cin>>n;
  int k;cin>>k;
  vector<int> ar(n);
  for(auto &it : ar)cin>>it;
  // vector<int> all_pairs(ar.begin(),ar.end());
  vector<int> all_pairs;
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      all_pairs.push_back(abs(ar[i] - ar[j]));
    }
  }
  sort(all_pairs.begin(),all_pairs.end());
  int mn = mne(ar);
  mn = min(mn , all_pairs[0]);
  if(k == 1){
    cout << mn << endl;
    return;
  }

  if(k == 2){
    for(auto it : ar){
      int dI = ub(all_pairs , it);
      if(dI == all_pairs.size())dI--;
      mn = min(abs(it - all_pairs[dI]) , mn);
      if(dI != 0)dI--;
      mn = min(abs(it - all_pairs[dI]) , mn);
    }
    cout << mn << endl;
    return;
  }

  cout << 0 << endl;
  return;
}
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}