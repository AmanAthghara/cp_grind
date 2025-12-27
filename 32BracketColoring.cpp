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
  string s;cin>>s;
  int bal = 0;
  vector<string> segments;
  string trims = "";
  bool reg = false;
  bool antireg = false; 

   




  for(auto it : s){
    trims += it;
    if(it == '(')bal++;
    else bal--;
    if(bal < 0)antireg = true;
    else if(bal > 0)reg = true;
    else{
      segments.push_back(trims);
      trims = "";
    }
  }

   if(trims.size() != 0){
    cout << -1 << endl;
   }else{
     if(reg and antireg){
      cout << 2 << endl;
      for(auto it : segments){
       // bool regs = false;
       reg = false;
       antireg = false;
       // bool antiregs = false;
       bal = 0;
       for(auto ele : it){
         if(ele == ')')bal--;
         else bal++;
         if(bal > 0)reg = true;
         else antireg = true;
       }
       if(reg)for(auto ele : it)cout << 1 << " ";
       else for(auto ele : it)cout << 2 << " ";
      }
    }
    else{
      cout << 1 << endl;
      for(auto it : segments)for(auto ele : it)cout << 1 << " ";
    }
    cout << endl; 
  }
  // cout << endl;
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