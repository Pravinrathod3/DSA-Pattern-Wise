class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;        //we use a stack to store the digits of the number, and we will pop the stack until we find a smaller digit than the current digit or the stack becomes empty, which means that we have removed all the larger digits from the stack and we can add the current digit to the stack
        string ans;

        for(int i=0; i<num.size(); i++){

            while(!st.empty() && k > 0 && st.top()-'0' > num[i]-'0'){  //till k is greater than 0 and the top of the stack is greater than the current digit, we pop the stack to remove the larger digits from the stack
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k > 0){   //if there are still some digits to remove after traversing the number, we pop the stack until we have removed k digits
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }


        reverse(ans.begin(), ans.end());

        while(!ans.empty() && ans[0] == '0'){ //we remove the leading zeros from the answer string until we find a non-zero digit or the answer string becomes empty
            ans.erase(ans.begin());
        }

        if(ans.empty()) return "0";

        return ans;
    }
};