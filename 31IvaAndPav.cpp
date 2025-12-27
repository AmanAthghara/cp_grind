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
#define prt(x) for(auto it : x)cout << it << " "
#define mxi(x) max_element(x.begin(),x.end())- x.begin()
#define mxe(x) *max_element(x.begin(),x.end())
#define mne(x) *min_element(x.begin(),x.end())
#define mni(x) min_element(x.begin(),x.end())- x.begin()

void solve(){

  int n;cin>>n;
  vector<int> arr(n);
  for(auto &it : arr)cin>>it;

  int qsize;cin>>qsize;
  vector<PI> q(qsize);
  for(auto &[l , k] : q)cin>>l>>k;

  // for(auto [l , k ] : q )cout << l << " " << k << endl;

  vector<vector<int>> pref(n, vector<int>(32,0));
  
  for(int i = 0;i<n;i++){
    if(i) pref[i] = pref[i-1];
    bitset<32> b(arr[i]);
    for(int j = 0;j<32;j++){
      pref[i][j] += b[j]; 
    }
  }

  vector<int> ans(qsize, -1);

  for(int idx = 0;idx < qsize;idx++){
    int l = q[idx].first-1;
    int k = q[idx].second;
    // cout << " l = " << l << " arr[l] = " << arr[l] << " k = " << k << endl;
    if(arr[l] < k)continue;
    int low = l, high = n-1;

    while(low <= high){
      int mid = (low + high) / 2;

      vector<int> remBits = pref[mid];
      if(l != 0){
        for(int i = 0;i<32;i++){
          remBits[i] -= pref[l-1][i];
        }
      }

      int val = 0;
      for(int i = 0;i<32;i++){
        if(remBits[i] > (mid - l ))
          val |= (1 << i);
      }

      if(val >= k){
        ans[idx] = mid+1;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
  }

  for(auto it : ans) cout << it << " ";
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
