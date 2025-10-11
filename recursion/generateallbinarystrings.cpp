#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void generate(string& arr, int index, int n, vector<string>& ans){
      if(n == index){
          ans.push_back(arr);
          return;
      }
      
      generate(arr, index+1, n, ans);
      
      arr[index] = '1';
      
      generate(arr, index+1, n, ans);
      
      arr[index] = '0';
      
      return;
      
  }
  
  
    vector<string> binstr(int n) {
        vector<string> ans;
        string res(n, '0');
        
        generate(res, 0, n, ans);
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution obj;
    vector<string> result = obj.binstr(n);
    
    for(auto str : result){
        cout<<str<<endl;
    }
    
    return 0;   
}