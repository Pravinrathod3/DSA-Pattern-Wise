class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi = *max_element(piles.begin(), piles.end());  //maximum number of bananas in a pile, which is the upper bound for the eating speed

        int ans;

        int low = 1;  //minimum eating speed can be 1 banana per hour, which is the lower bound for the eating speed
        int high = maxi;

        while(low <= high){
            int mid = (low + high) / 2;

            long long hrs = 0;

            for(int j=0; j<n; j++){  //calculate the total hours needed to eat all the bananas at the current eating speed (mid)
                hrs += ceil((double)piles[j] / (double)mid);
            }

            if(hrs <= h){  //if the total hours needed is less than or equal to h, it means we can eat all the bananas at this speed or even slower, so we try to find a smaller eating speed by moving the high pointer down
                ans = mid;
                high = mid - 1;
            }
            else{            //if the total hours needed is greater than h, it means we cannot eat all the bananas at this speed, so we need to try a faster eating speed by moving the low pointer up
                low = mid + 1;
            }

        }
        

        return ans;
    }
};