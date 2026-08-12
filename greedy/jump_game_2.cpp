class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        

        int farthest = 0;
        int nearest = 0;

        int jump = 0 ;

        int maxrange = 0;

        while(maxrange < n-1){

            for(int i=nearest; i<=farthest; i++){
                maxrange = max(maxrange, nums[i]+i);
            }

            nearest = farthest + 1;
            farthest = min(maxrange, n-1);
            
            jump++;

        }

        return jump;
    }
};