class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        long long prefix = 0;

        vector<long long> minPrefix(k, LLONG_MAX / 2);
        minPrefix[k - 1] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            int r = i % k;

            ans = max(ans, prefix - minPrefix[r]);
            minPrefix[r] = min(minPrefix[r], prefix);
        }

        return ans;
    }
};
