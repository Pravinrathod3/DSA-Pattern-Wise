class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;              //profit at the start is 0 
        int mini = prices[0];        //use to track the minimum buying price we have seen so far

        for(int i=1; i<n; i++){
            int sell = prices[i] - mini;  //calculate the profit at the end of the day 
            profit = max(profit, sell);   //compare the profit with the maximum profit we have seen so far and update it if necessary
            mini = min(mini, prices[i]);  //update the minimum buying price if we see a lower price than the current minimum
        }

        return profit;
    }
};