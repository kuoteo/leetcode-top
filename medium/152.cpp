class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN, imax = 1, imin = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            result = max(result, imax);
        }
        return result;
    }
};