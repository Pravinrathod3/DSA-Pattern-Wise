#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   void merge(vector<int> &arr, int beg, int mid, int end){
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

  void countpairs(vector<int> &arr, int beg, int mid, int end, int& cnt){
       int j = mid + 1;

       for(int i=beg; i<=mid; i++){
          
          while(j <= end && arr[i] > (2LL * arr[j])){
            j++;
          }

          cnt += (j - (mid + 1));

       }
  }
  
   void mergesort(vector<int> &arr, int beg, int end, int& cnt){
       if(beg >= end) return ;
       
       int mid = beg + (end - beg) / 2;
       
       mergesort(arr, beg, mid, cnt);
       mergesort(arr, mid+1, end, cnt);

       countpairs(arr, beg, mid, end, cnt);
       
       merge(arr, beg, mid, end);
   }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        mergesort(nums, 0, n-1, cnt);

        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,3,2,3,1};
    int ans = sol.reversePairs(arr);
    cout << ans << endl;
    return 0;
}