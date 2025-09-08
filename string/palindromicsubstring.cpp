#include<iostream>
#include<vector>
#include<string>
using namespace std;

int check(string res){
        int l=0;
        int r = res.size()-1;

        cout<<res<<"/n";

        while(l <= r){
            if(res[l] != res[r]){
                return 0;
            }
        }

        return 1;
    }

int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            string res;
            for(int j=i; j<n; j++){
                res += (s[j]);
                cnt += check(res);
            }
        }

        cout<<cnt<<"/n";

        return cnt;
    }

int main(){
    string res = "abc";

    int output = countSubstrings(res);

    cout<<output;
}