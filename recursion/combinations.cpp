#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void recurse(int index, int n, vector<int>& res, int k, int x){
        if(index == k){
            ans.push_back(res);
            return ;
        }

        for(int i=x; i<=n; i++){
           res.push_back(i);
           recurse(index+1, n, res, k, i+1);
           res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> res;

        recurse(0, n, res, k, 1);
        
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> result = sol.combine(n, k);

    for(const auto& combination : result){
        for(int num : combination){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}