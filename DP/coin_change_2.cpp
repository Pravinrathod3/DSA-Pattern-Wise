class Solution {
public:


    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int coin=0; coin<=amount; coin++){
            if(coin % coins[0] == 0){
                dp[0][coin] = 1;
            }
            
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                long long exclude = dp[i-1][j];

                long long include = 0;
                if(coins[i] <= j){
                  include = dp[i][j-coins[i]];
                }

                dp[i][j] = (include+exclude) ;
            }
        }

        return (int)dp[n-1][amount];
    }
};

//TC: O(N*amount)
//SC: O(N*amount)