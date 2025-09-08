#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;

        while(x != 0){
            int ele = x % 10;
            cout<<ele<<endl;
            x = x / 10;
          
            res = res * 10 + ele;
        }


        if(res > INT_MAX || res < INT_MIN) return 0;

        return res;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(-123);
}