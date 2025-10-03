#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>arr(n,0);
    for(auto &it:arr)cin>>it;
    for(int i =0;i<n;i++){
        for(int j = 1;j<n-1;j++){
            if(arr[j-1] < arr[j] and arr[j] > arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
    bool notSorted = false;
    for(int i = 1;i<n;i++){
        if(arr[i-1] > arr[i]){
            notSorted = true;
            break;
        }
    }
    if(notSorted){
        cout << "No"<<endl;
    }
    else{
        cout << "Yes" << endl;
    }
}


int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    solve();
	}

}