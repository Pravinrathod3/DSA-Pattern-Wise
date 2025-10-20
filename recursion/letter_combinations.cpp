#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   vector<string> ans;
  
    string letter(char ch){
        if(ch == '2'){
            return "abc";
        }
        else if(ch == '3'){
            return "def";
        }
        else if(ch == '4'){
            return "ghi";
        }
        else if(ch == '5'){
            return "jkl";
        }
        else if(ch == '6'){
            return "mno";
        }
        else if(ch == '7'){
            return "pqrs";
        }
        else if(ch == '8'){
            return "tuv";
        }
        else if(ch == '9'){
            return "wxyz";
        }
       
        return "";
        
    }

    void recursion(vector<string>& substrings, int n, int index, string& res){
        if(res.size() == n){
            ans.push_back(res);
            return;
        }

        for(int i=0; i<substrings[index].size(); i++){
            res.push_back(substrings[index][i]);
            recursion(substrings, n, index+1, res);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        string res;
        vector<string> substrings;

        for(int i=0; i<n; i++){
            substrings.push_back(letter(digits[i]));
        }

        recursion(substrings, n, 0, res);
        
        return ans;
    }
};

int main(){
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);

    for(const string& combination : result){
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}