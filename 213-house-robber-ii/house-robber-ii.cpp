class Solution {
public:
    
    long long robLinear(vector<int>& nums, int l, int r) {
        long long prev = 0, curr = 0;
        for (int i = l; i <= r; i++) {
            long long take = prev + nums[i];
            long long skip = curr;
            long long next = max(take, skip);
            prev = curr;
            curr = next;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        long long case1 = robLinear(nums, 0, n - 2);   
        long long case2 = robLinear(nums, 1, n - 1);  

        return max(case1, case2);
    }
};