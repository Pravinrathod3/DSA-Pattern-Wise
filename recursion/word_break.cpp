#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool recurse(int index, string& s, unordered_set<string>& wordDict, vector<int>& memo){
        int n = s.length();

        if(index == n){
            return true;
        }

        if(memo[index] != -1) return memo[index];

        string res = "";

        for(int i=index; i<n; i++){
            res += s[i];
            
            if(wordDict.find(res) != wordDict.end()){
                    if(recurse(i + 1, s, wordDict, memo)){
                       return memo[index] = true;
                    }         
            }
        }

        return memo[index] = false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(n, -1);

        return recurse(0, s, dict, memo);

    }
};

int main(){
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << sol.wordBreak(s, wordDict) << endl; // Output: 1 (true)
    return 0;
}