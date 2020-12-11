#solution1 84ms O(n) O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 1), R(n, 1);
        vector<int> result(n);
        for(int i = 1; i < n; ++i){
            L[i] = nums[i - 1] * L[i - 1];
        }
        for(int i = n - 2; i >= 0; --i){
            R[i] = nums[i + 1] * R[i + 1];
        }
        for(int i = 0; i < n; ++i){
            result[i] = L[i] * R[i];
        }
        return result;
    }
};