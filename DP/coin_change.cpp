#include<bits/stdc++.h>
using namespace std;

//Memoization

class Solution {
public:

    int change(int node, vector<int>& coins, int amount, vector<vector<int>>& dp){

        if(amount == 0) return 0;                //if amount is 0, no coins needed
        if(node == coins.size()) return 1e9;        //if no coins left and amount is not 0, return large value

        if(dp[node][amount] != -1) return dp[node][amount];    //returning already computed value
        

        int exclude = change(node+1, coins, amount, dp);         //excluding current coin and moving to next coin

        int include = 1e9;
        if(amount >= coins[node]){                      //including current coin if amount is greater than or equal to coin value and not moving to next coin and reducing amount
            include = change(node, coins, amount-coins[node], dp) + 1;
        }

        return dp[node][amount] = min(exclude, include);        //storing minimum coin result in dp array 

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));    //dp array for memoization

        if( change(0, coins, amount, dp) == 1e9){                  //if no solution found
            return -1;
        }

        return change(0, coins, amount, dp);              //return minimum coins needed
    }
};

int main(){
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount) << endl; // Output: 3 (11 = 5 + 5 + 1)
    return 0;
}

//Time Complexity: O(n*amount) where n is number of coins
//Space Complexity: O(n*amount) for dp array + O(amount) for recursion stack

//Tabulation

class Solution {
public:


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int j = 0; j <= amount; j++){      //initializing first row as base case
            if(j % coins[0] == 0)              //if amount is multiple of first coin 
                dp[0][j] = j / coins[0];          //number of coins needed
            else
                dp[0][j] = 1e9;         //else large value not possible
        }


        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
        
                int exclude = dp[i-1][j];     //not including the current coin

                int include = 1e9;
                if(j >= coins[i]){          //including the current coin if amount is greater than or equal to coin value
                    include = dp[i][j - coins[i]] + 1;     //including the current coin current amount reduced by coin value
                } 
        
                dp[i][j] = min(exclude, include);
            }
        }

        

        if(dp[n-1][amount] == 1e9){
            return -1;
        }

        return dp[n-1][amount];
    }
};

// Time Complexity: O(n*amount) where n is number of coins
// Space Complexity: O(n*amount) for dp array

