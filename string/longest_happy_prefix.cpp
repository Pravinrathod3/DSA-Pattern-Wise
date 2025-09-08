#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        vector<string> prefix;
        vector<string> suffix;

        string temp1;
        string temp2;
        
        int n = s.size();

        for(int i=0; i<n-1; i++){
            temp1 += s[i];
            prefix.push_back(temp1);
            temp2.insert(temp2.begin(), s[n-i-1]);
            suffix.push_back(temp2);
        }

        cout<<"Prefix: ";
        for(const auto& p : prefix) {
            cout << "'" << p << "' ";
        }
        cout << endl;
        cout<<"Suffix: ";       
for(const auto& s : suffix) {
            cout << "'" << s << "' ";
        }
        cout << endl;

        int l = prefix.size();

        for(int i=0; i<l; i++){
            if(prefix[l-i-1] == suffix[l-i-1]){
                return prefix[l-i-1];
            }
        }

        return " ";
    }
};

int main() {
    Solution sol;
    string s = "ababab";
    cout << "Longest happy prefix of '" << s << "' is: '" << sol.longestPrefix(s) << "'" << endl;
    return 0;
}