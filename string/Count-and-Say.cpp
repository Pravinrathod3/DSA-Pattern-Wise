class Solution {
public:

    string rle(string ans){
        string res;

        int cnt = 1;

        for(int i=1; i<=ans.size(); i++){
            if(i < ans.size() && ans[i] == ans[i-1]){
               cnt++;
            }
            else{
                res += to_string(cnt);
                res += ans[i-1];
                cnt = 1;
            }
            
        }

        return res;
    }

    string countAndSay(int n) {
        string ans;

        if(n == 0) return ans;

        ans = "1";

        for(int i=1; i<n; i++){
            ans = rle(ans);
        }

        return ans;


    }
};