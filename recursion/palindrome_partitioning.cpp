#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    bool palindrome(string s){
        int n = s.size();

        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }

        return true;
    }

    void recursion(int index, int n, vector<string>& res, string s){
        if(index == n){
            ans.push_back(res);
            return;
        }

        string temp;

        for(int i=index; i<n; i++){
            temp += s[i];
            if(palindrome(temp)){
                res.push_back(temp);
                recursion(i+1, n, res, s);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> res;
        int n = s.length();

        recursion(0, n, res, s);

        return ans;
    }
};


int main(){
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);

    for(const auto& partition : result){
        for(const auto& str : partition){
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}


// TC: O(N * 2^N)
// SC: O(N)