#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n,0);
        for(auto &it:arr)cin>>it;
        map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        if(mp.size() > 2){
            cout << "No"<<endl;
            continue;
        }
        if(mp.size() ==1){
            cout << "Yes" << endl;
            continue;
        }
        auto first = mp.begin();
        auto second = (mp.rbegin());
        if(abs(first->second - second->second) > 1)cout << "No"<<endl;
        else cout << "Yes" << endl;
    }
}