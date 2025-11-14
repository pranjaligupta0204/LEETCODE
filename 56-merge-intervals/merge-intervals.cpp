class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;
        vector<int> current = intervals[0];

        for(int i = 0; i < intervals.size() ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start <= current[1]){
                current[1] = max(current[1],end);
            }else{
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};