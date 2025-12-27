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
  int m;cin>>m;
  vector<int> a(n);
  vector<int> b(n);
  a[0] = 1;
  for(int i = 0;i<n-1;i++){
    cin>>a[i+1];  
  }
  for(auto &it : b)cin>>it;
  srt(a);
  srt(b);
  int cnt = 0;
  for(int i = 0,j = 0;i<a.size() and j < n;){
    if(a[i] >= b[j]){
      b[j] = -1;
      j++;
      a.pop_back();
      cnt++;
    }else{
      i++;
      j++;
    }
  }
  cout << cnt << endl;

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