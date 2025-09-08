#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> mpp;

        for(char ch: s) mpp[ch]++;

        priority_queue<pair<int, char>> heap;

        for(auto& [ch, num]: mpp){
            heap.push({num, ch});
        }

        string res;

        while(!heap.empty()){
            auto [count, ch] = heap.top();
            heap.pop();

            res+= string(count, ch);
        }


        return res;
    }
};

int main(){
    Solution s;

    string a = "tree";
    cout<<s.frequencySort(a)<<endl;
}