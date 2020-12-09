class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        for(int i = 0; i < intervals.size(); ++i){
            int L = intervals[i][0], R = intervals[i][1];
            if(!vec.size() || vec.back()[1] < L){
                vec.push_back({L, R});
            }
            else{
                vec.back()[1] = max(vec.back()[1], R);
            }
        }
        return vec;
    }
};