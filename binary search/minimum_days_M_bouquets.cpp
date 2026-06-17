class Solution {
public:

    int blooms(vector<int> &arr, int m, int k, int mid){
        int bouq = 0;

        int n = arr.size();

        int cnt = 0;

        for(int i=0; i<n; i++){  // we are counting the number of flowers that have bloomed on or before the mid day. If the count reaches k, it means we can make a bouquet and we reset the count. If we encounter a flower that has not bloomed by mid day, we also reset the count. This way, we can calculate how many bouquets can be made by mid day.
            if(arr[i] <= mid){
                cnt++;
            }
            else{
                bouq += floor((double)cnt / (double)k);
                cnt = 0;
            }
        }

        bouq += floor((double)cnt / (double)k);

        return bouq;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int bouq = blooms(bloomDay, m, k, mid);

            if(m <= bouq){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};