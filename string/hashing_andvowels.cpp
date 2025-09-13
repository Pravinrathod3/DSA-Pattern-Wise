#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
       map<char, int> hash;

        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }

        int vowel = 0;
        int consonant = 0;

        for(auto it: hash){
            char ch = it.first;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowel = max(vowel, it.second);
            }
            else{
                consonant = max(consonant, it.second);
            }
        }

        return vowel + consonant;
    }
};

int main(){
    Solution sol;
    string s = "abciiidef";
    cout << sol.maxFreqSum(s) << endl; // Output: 5
    return 0;
}