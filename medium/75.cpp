#solution1 单指针 O(n) O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for(int i = ptr; i < n; i++){
            if(nums[i] == 1){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
};

#solution2 双指针 O(n) O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for(int i = 0; i <= p2; i++){
            while(i <= p2 && nums[i] == 2){
                swap(nums[i], nums[p2]);
                --p2;
            }
            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};