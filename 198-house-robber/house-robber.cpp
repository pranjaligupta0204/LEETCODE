class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        long long int prev = nums[0];
        long long int prev2 = 0;

        for(int i = 1; i< n ; i++ ){
            long long pick = nums[i];
            if( i > 1) {
                pick += prev2;
            }
            int long long nonpick = 0 + prev ;

            long long int cur_i = max(pick, nonpick);
            prev2 = prev;
            prev= cur_i;
        
         }
         return prev;
        
        
    }
};