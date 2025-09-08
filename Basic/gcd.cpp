#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int gcd(int a, int b) {
        if(a <= 0){
            return b;
        }
        
        int maxi = max(a,b);
        int mini = min(a,b);
        
        return gcd(maxi % mini, mini);
    }
};

int main(){
    Solution s;
    cout<<s.gcd(20, 15);
}