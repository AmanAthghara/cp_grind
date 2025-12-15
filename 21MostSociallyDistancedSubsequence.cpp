#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &it : a)cin>>it;
        vector<int> res;
        res.push_back(a[0]);
        bool isUp = a[0] < a[1];
        for(int i = 1;i<n;i++){
            if(a[i]  > a[i-1] and isUp == false){
                res.push_back(a[i-1]);
                isUp = true;
            }else if(a[i] < a[i-1] and isUp == true){
                res.push_back(a[i-1]);
                isUp = false;
            }
        }
        // if(res.size() == 1)res.push_back(a.back());
        res.push_back(a.back());
        cout << res.size() <<endl;
        for(auto it : res){
            cout << it << " ";
        }
        cout << endl; 
    }
    return 0;
}