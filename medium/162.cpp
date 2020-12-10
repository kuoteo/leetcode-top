#solution1 递归 O(logn) O(logn) 8ms
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int>& nums, int l, int r){
        if(l == r)
            return l;
        int mid = (l + r) / 2;
        if(nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
};

#solution2 迭代 O(logn) O(1) 8ms
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }