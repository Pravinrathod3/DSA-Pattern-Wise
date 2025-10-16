#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


   void recursion(string& res, vector<string>& ans, int n, int open, int close){
      if(res.size() == (2 * n)){
           ans.push_back(res);
        return;
      }

      res.push_back('(');
      if(open < n){
        recursion(res, ans, n, open+1, close);
      }
      
      res.pop_back();
      res.push_back(')');

      if(close < open){
        recursion(res, ans, n, open, close+1);
      }
      
      res.pop_back();
      
   }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;

        recursion(res, ans, n, 0, 0);

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> a;
    int n;
    cin>>n;
    a = s.generateParenthesis(n);
    for(auto it: a){
        cout<<it<<" ";
    }
}