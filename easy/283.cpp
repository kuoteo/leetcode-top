#solution1 52ms O(n2) O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] == 0){
                for(int j = i; j < n - 1; ++j){
                    nums[j] = nums[j + 1];
                }
                nums[n - 1] = 0;
            }
        }
    }
};

#solution1 8ms O(n) O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0) return;
        int j=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j++] = temp;
            }
        }
    }
};