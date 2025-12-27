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
void solve(){
  int n;cin>>n;
  vector<pair<int,int>> a(n);
  for(auto &it : a){
    cin >> it.first >> it.second;
  }
  int ans = 1e9 + 1;
  int left = 0, right = 1e9 + 1;
  while(left <= right){
    int mid = left + (right - left)/2;
    bool poss = true;
    int pL = 0;
    int pR = 0;
    for(auto it : a){
      auto [itL , itR] = it;
      int newL = max(itL, pL - mid);
      int newR = min(itR, pR + mid);
      if(newL > newR){
        poss = false;
        break;
      }
      pL = newL;
      pR = newR;
    }
    if(poss){
      ans = mid;
      right = mid - 1;
    }else{
      left = mid +  1;
    }
  }
  cout << ans << endl;
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