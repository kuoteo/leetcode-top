class Solution {
public:
    int maxSubArrayCenter(vector<int>& nums, int left, int center, int right){
        int s1 = INT_MIN, lefts = 0;
        for(int i = center; i >=left; i--){
            lefts += nums[i];
            s1 = max(s1, lefts);
        }
        int s2 = INT_MIN, rights = 0;
        for(int j = center + 1; j <= right; j++){
            rights += nums[j];
            s2 = max(s2, rights);
        }
        return (s1 + s2);
    }
    
    int maxSubArrayHelper(vector<int>& nums, int left, int right){
        if(left == right){
            return nums[left];            
        }
        int center = (left + right) / 2;
        int leftsum = maxSubArrayHelper(nums, left, center);
        int rightsum = maxSubArrayHelper(nums, center + 1, right);
        int centersum = maxSubArrayCenter(nums, left, center, right);
        int result = max(leftsum, rightsum);
        result = max(result, centersum);
        return result;       
    }
    
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();
        result = maxSubArrayHelper(nums, 0, n - 1);
        return result;
    }
};