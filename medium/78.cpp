#solution1 数学归纳 超出时间限制 O(n*2^n) O(n*2^n) 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        int n = nums.back();
        nums.pop_back();
        vector<vector<int>> res = subsets(nums);
        for(int i = 0;i < res.size();i++){
            res.push_back(res[i]);
            res.back().push_back(n);
        }
        return res;
    }
};