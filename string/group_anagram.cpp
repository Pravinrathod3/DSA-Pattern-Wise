#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        map<string, vector<string>> mpp;

        for(int i=0; i<n; i++){
            string s = strs[i];
            vector<int> hash(26, 0);
            for(int j=0; j<s.size(); j++){
                hash[s[j] - 'a']++;
            }

            s.clear();

            for(int j=0; j<26; j++){
                if(hash[j] > 0){
                    s += string(hash[j], 'a' + j);
                }
            }

            mpp[s].push_back(strs[i]);
        }

        for(auto [fr, sec]: mpp){
            ans.push_back(sec);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:" << endl;
    for(auto group: result){
        for(auto word: group){
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}