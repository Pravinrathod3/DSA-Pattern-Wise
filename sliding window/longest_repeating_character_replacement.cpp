#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxi = 0;
        int l = 0;

        vector<int> freq(26, 0);   // frequency array to store the count of each character

        
        for(int r=0; r<n; r++){
            freq[s[r] - 'A']++;   // increment the frequency of the current character

            int change = (r-l+1) - *max_element(freq.begin(), freq.end());  // calculate the number of changes needed to make all characters in the window the same

            while(change > k){   // while the number of changes needed is greater than k
                freq[s[l] - 'A']--;    // decrement the frequency of the leftmost character 
                l++;
                change = (r-l+1) - *max_element(freq.begin(), freq.end());  // recalculate the number of changes needed

            }

            maxi = max(maxi, r-l+1);  // update the maximum length of the valid window
        }


        return maxi;


    }
};

int main(){
    Solution sol;
    string s = "AABABBA";
    int k = 1;

    int result = sol.characterReplacement(s, k);

    cout << "Longest repeating character replacement length: " << result << endl;

    return 0;
}

// Time Complexity: O(26 * N) where N is the length of the string s. In the worst case, for each character in the string, we may need to find the maximum frequency which takes O(26) time.
// Space Complexity: O(1) since the frequency array size is fixed at 26, regardless of the input size.