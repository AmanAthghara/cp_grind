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
void dfs(int i , vector<vector<int>>&adj , set<int>&up , set<int> &down , bool putUp , int par){
    if(putUp)up.insert(i);
    else{
        down.insert(i);
    }
    for(auto it : adj[i]){
        if(it == par)continue;
        dfs(it , adj , up , down , !putUp , i);
    }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;cin>>n;
  set<int>up;
  set<int>down;
  vector<vector<int>>adj(n+1);                                    
  for(int i = 0;i<n-1;i++){
    int x,y;cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1 , adj , up , down , true , -1);
  cout << (1LL * up.size() * down.size()) - (n-1);
  return 0;
}