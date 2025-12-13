#include<bits/stdc++.h>
using namespace std;

int findMaxDivisor(int n) {
    int divisor = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divisor = max(divisor , i); 
            divisor = max(divisor , n/i); 
        }
    }
    return divisor;
}
int main(){
          int t;cin>>t;
          while(t--){
                    int n;cin>>n;
                    if(n%2 == 0){
                              cout << n/2 << " " << n/2 << endl;
                    }else{
                              int max_divisor = findMaxDivisor(n);
                              cout << n - max_divisor << " " << max_divisor << endl;
                    }
                    
          }
}