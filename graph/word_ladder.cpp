class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> qu;  // word and cnt

        unordered_set<string> st(wordList.begin(), wordList.end());  //set is used to check if the word is present in the wordList or not

        qu.push({beginWord, 1}); 

        st.erase(beginWord);

        while(!qu.empty()){
            auto [word, cnt] = qu.front();
            qu.pop();

            if(word == endWord) return cnt;  //if the word is equal to the endWord then return the count to find shortest path

            for(int i=0; i<word.size(); i++){
                char original = word[i];  //store the original character of the word at index i

                for(char ch='a'; ch<='z'; ch++){  //change the character at index i to all the characters from a to z
                    word[i] = ch;
                    if(st.find(word) != st.end()){  //if the word is present in the set then push it to the queue and erase it from the set
                        qu.push({word, cnt+1});  
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;


    }
};

// Time Complexity: O(N * M * 26) where N is the number of words in the wordList and M is the length of each word. For each word, we are changing each character to 26 possible characters and checking if the new word is present in the set or not.
// Space Complexity: O(N) where N is the number of words in the wordList. We are using a queue to store the words and a set to store the words in the wordList.

//to find the smallest path we can use BFS and to find the largest path we can use DFS.