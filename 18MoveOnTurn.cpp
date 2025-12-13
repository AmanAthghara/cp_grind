#include<bits/stdc++.h>
using namespace std;
int main(){
          int n;cin>>n;
          int k = n/2;
          if(n % 2 == 0){
                    cout << (k + 1) * (k + 1);
          }
          else{
                    cout << 2 * (k + 1) * (k + 2);
          }
}