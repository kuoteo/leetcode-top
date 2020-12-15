#solution1 数学求和 44ms O(n) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int num : nums)
            sum += num;
        return (n * (n + 1)) / 2 - sum;
    }
};

#solution1 异或 28ms O(n) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            result = result ^ i ^ nums[i];
        return result;
    }
};