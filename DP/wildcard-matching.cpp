class Solution {
public:

    bool wildcard(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true; 
        if(j < 0 && i >= 0) return false;
        if(i < 0){
            for(int ele = j; ele >= 0; ele--){
                if(p[ele] != '*'){
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            if(wildcard(i-1, j-1, s, p, dp)) return dp[i][j] = true;
        }
        else if(p[j] == '*'){
            if(wildcard(i-1, j, s, p, dp)) return dp[i][j] = true;
            if(wildcard(i, j-1, s, p, dp)) return dp[i][j] = true;
        }
    
        return dp[i][j] = false;
        
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return wildcard(n-1, m-1, s, p, dp);
    }
};