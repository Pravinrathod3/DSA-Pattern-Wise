class Solution {
public:

    int profit(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int ans;

        if(buy){    //can buy
          ans = max( (-prices[i] + profit(i+1, 0, prices, dp)), profit(i+1, 1, prices, dp) );  //if we buy, then we will have to pay the price, so -prices[i] or if we dont buy, then we will move to the next day and we can still buy, so profit(i+1, 1, prices, dp)
        }
        else{    //can sell
          ans = max( (prices[i] + profit(i+1, 1, prices, dp)), profit(i+1, 0, prices, dp) );  //if we sell, then we will get the price, so +prices[i] or if we dont sell, then we will move to the next day and we can still sell, so profit(i+1, 0, prices, dp)
        }

        return dp[i][buy] = ans;  //store the answer in dp array and return it
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, 0)); //dp array to store the maximum profit for each day and buy/sell state

        for(int i=n-1; i>= 0; i--){   //we will start from the last day and move towards the first day, because we need to know the profit for the next day to calculate the profit for the current day

            dp[i][1] = max( (-prices[i] + dp[i+1][0]), dp[i+1][1] );
    
            dp[i][0] = max( (prices[i] + dp[i+1][1]), dp[i+1][0] );
            
        }

        return dp[0][1]; //the maximum profit we can get on the first day when we can buy, because we want to start with buying the stock, so we will return dp[0][1]
    }
};