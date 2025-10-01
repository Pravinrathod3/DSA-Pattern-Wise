#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void merge(vector<int> &arr, int beg, int mid, int end, int& cnt){
      vector<int> temp;
      
      int left = beg;
      int right = mid+1;
      
      while(left <= mid && right <= end){
          if(arr[left] <= arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          else{
              temp.push_back(arr[right]);
              right++;
              cnt += (mid - left + 1);
          }
      }
      
      while(left <= mid){
        temp.push_back(arr[left]);
        left++;
      }
      
      while(right <= end){
        temp.push_back(arr[right]);
        right++; 
      }
      
      for(int i=beg; i<= end; i++){
          arr[i] = temp[i-beg]; 
      }
  }
  
   void mergesort(vector<int> &arr, int beg, int end, int& cnt){
       if(beg >= end) return ;
       
       int mid = beg + (end - beg) / 2;
       
       mergesort(arr, beg, mid, cnt);
       mergesort(arr, mid+1, end, cnt);
       
       merge(arr, beg, mid, end, cnt);
   }
  
    int inversionCount(vector<int> &arr) {
        int cnt = 0;
        int n = arr.size();
        
        mergesort(arr, 0, n-1, cnt);
        
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << sol.inversionCount(arr) << endl; // Output: 3
    return 0;
}