#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &i : a)cin>>i;
    for(auto &i : b)cin >> i;
    vector<bool> mp(n+1,false);
    int i= 0,j = 0;
    int fine = 0;
    while(i < n ){
        if(a[i] == b[j]){
            i++;j++;
        }else{
            if(mp[a[i]])i++;
            else{
                mp[b[j]]=true;
                fine++;
                j++;
            }
        }
    }
    cout << fine << endl;


    return 0;
}
