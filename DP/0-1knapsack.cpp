#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int maxvalue(int i, int w, vector<int> &val, vector<int> &wt, int total, vector<vector<int>>& dp){
        if(total > w) return 0;           //we cannot include this item as it exceeds capacity
        if(i == val.size()){             //no more items left to process
            return 0;
        }
        
        if(dp[i][total] != -1) return dp[i][total];       //return already computed value
        
        int exclude = maxvalue(i+1, w, val, wt, total, dp);  //not including the current item
        
        int include = 0;
        if(total+wt[i] <= w){                   //including the current item only if it doesn't exceed capacity
            include = maxvalue(i+1, w, val, wt, total+wt[i], dp) + val[i]; //including the current item
        }
        
        
        return dp[i][total] = max(exclude, include);   //storing the maximum value obtained
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int> (W+1, -1));  //dp table to store intermediate results with weight capacity as state and item index as state
        
        return maxvalue(0, W, val, wt, 0, dp);
        
    }
};

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    
    Solution ob;
    cout << ob.knapsack(W, val, wt) << endl;
    return 0;
}

// Time Complexity: O(N*W) where N is number of items and W is the maximum weight capacity of knapsack
// Space Complexity: O(N*W) for the dp table

//Tabluation Approach:

class Solution {
  public:
  

  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<int>prev(W+1, 0), curr(W+1, 0);     //dp table to store intermediate results with weight capacity as state only two rows needed because we are only using previous row values
        
        
        for(int wig = wt[0]; wig <= W; wig++) prev[wig] = val[0];  //initializing first row base case
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=W; j++){
                 int exclude = prev[j];          //not including the current item
         
                 int include = 0;
                 if(wt[i] <= j){
                     include = prev[j - wt[i]] + val[i] ;     //including the current item current weight capacity reduced by weight of current item
                 }
                 
                 curr[j] = max(exclude, include);      //storing the maximum value obtained
            }
            prev = curr;         //move to next row
        }
        
        return prev[W];        //final answer will be in the last row and last column
        
    }
};



