class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> comp;
        for (int x = 0 ; x < nums.size() ; x++){
            if(comp.empty() || comp.back() != nums[x]){
                comp.push_back(nums[x]);
            }
        }

        int count = 0;
        for(int i = 1; i + 1 < comp.size() ; i++){
            if(comp[i] > comp[i-1] && comp [i]  > comp[i+1]){
                count ++;
            }
            else if(comp [i] < comp[i-1] && comp[i] < comp[i+1]){
                count ++;
            }
        }

        return count ;
        
    }
};