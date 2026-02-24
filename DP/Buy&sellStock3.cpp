#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int profit(int i, int buy, int sell, vector<int>& prices, vector<vector<vector<int>>>& dp){

        if(sell == 2) return 0;  //we can sell at max 2 times, so if we have already sold 2 times, then we can't make any more profit, so return 0

        
        if(i == prices.size()) return 0;

        if(dp[i][buy][sell] != -1) return dp[i][buy][sell];

        int ans;

        if(buy){
            //we can either buy the stock or skip it, if we buy the stock, then we will have to pay the price of the stock, so we will subtract the price from our profit, and we will also change our state to sell, because after buying we can only sell, and we will also move to the next day, so we will call the function recursively with i+1, 0, sell, prices, dp
          ans = max( (-prices[i] + profit(i+1, 0, sell, prices, dp)), profit(i+1, 1, sell, prices, dp) );
        }
        else{

            //we can either sell the stock or skip it, if we sell the stock, then we will have to add the price of the stock to our profit, so we will add the price to our profit, and we will also change our state to buy, because after selling we can only buy, and we will also move to the next day, so we will call the function recursively with i+1, 1, sell+1, prices, dp
          ans = max( (prices[i] + profit(i+1, 1, sell+1, prices, dp)), profit(i+1, 0, sell, prices, dp) );
        }

        return dp[i][buy][sell] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(0, 1, 0, prices, dp);
    }

};

//tabulation

  int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--){
                for(int sell=0; sell<3; sell++){

                    //Buy

                    dp[i][1][sell] = max( (-prices[i] + dp[i+1][0][sell]), dp[i+1][1][sell] );

                    //sell
                    
                    if(sell < 2){ //we can only sell at max 2 times, so if we have already sold 2 times, then we can't sell anymore, so we will just take the profit from the next day, which is dp[i+1][0][sell]
                       dp[i][0][sell] = max( (prices[i] + dp[i+1][1][sell+1]), dp[i+1][0][sell] );
                    }
                    else{
                        dp[i][0][sell] = dp[i+1][0][sell];
                    }
                    
                }
        }

        return dp[0][1][0];
    }

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(prices);
    return 0;
}