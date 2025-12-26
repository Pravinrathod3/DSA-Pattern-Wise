#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> ycount(n+1, 0);
        vector<int> ncount(n+1, 0);


        for(int i=1; i<=n; i++){
           ncount[i] = ncount[i-1] + (customers[i - 1] == 'N');
        }

        for(int i=n-1; i>=0; i--){
            ycount[i] = ycount[i+1] + (customers[i] == 'Y');
        }
        

        int ans = INT_MAX;
        int hour = 0;

        for(int i=0; i<=n; i++){
            if(ycount[i]+ncount[i] < ans ){
                ans = ycount[i]+ncount[i];
                hour = i;
            }
        }

        
        return hour;


    }
};

int main(){
    Solution sol;
    string customers = "YYNY";
    cout << sol.bestClosingTime(customers) << endl; // Output: 2
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)