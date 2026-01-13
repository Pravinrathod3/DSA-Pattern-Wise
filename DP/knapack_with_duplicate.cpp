//memoization approach for unbounded knapsack problem

class Solution {
  public:
  
    int maxvalue(int i, int w, vector<int> &val, vector<int> &wt, int total, vector<vector<int>>& dp){
        if(total > w) return 0;
        if(i == val.size()){
            return 0;
        }
        
        if(dp[i][total] != -1) return dp[i][total];
        
        int exclude = maxvalue(i+1, w, val, wt, total, dp);    //not including the item but moving to next item
        
        int include = 0;
        if(total+wt[i] <= w){
            include = maxvalue(i, w, val, wt, total+wt[i], dp) + val[i]; //including the item and not moving to next item
        }
        
        
        return dp[i][total] = max(exclude, include);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
        
        return maxvalue(0, capacity, val, wt, 0, dp);
        
    }
};

//TC: O(N*W)
//SC: O(N*W) + O(W) for recursive stack space

//Tabulation approach for unbounded knapsack problem

class Solution {
  public:
  
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int> (capacity+1, 0));
        
        for(int i=wt[0]; i<=capacity; i++){          //filling first row
                dp[0][i] = (i / wt[0]) * val[0];     //including the first item as many times as possible and calculating its value in the knapsack
        }
        
        for(int i=1; i<n; i++){
            for(int total=0; total<=capacity; total++){
                int exclude = dp[i-1][total];       //not including the item
        
                int include = 0;
                if(total >= wt[i]){
                    include = dp[i][total-wt[i]] + val[i];   //including the item and not moving to next item
                }
                
                
                dp[i][total] = max(exclude, include);
            }
        }
        
        return dp[n-1][capacity];
        
    }
};

//TC: O(N*W)
//SC: O(N*W)