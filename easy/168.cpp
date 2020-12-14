#solution1 数学求和 O(n) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int num : nums)
            sum += num;
        return (n * (n + 1)) / 2 - sum;
    }
};