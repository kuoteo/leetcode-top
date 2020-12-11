#solution1 反转 4ms O(n) O(1)
class Solution {
public:
    void reverse(vector<int>& nums,int start,int end){
        int temp;
        while(start<end){
            temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums,0,nums.size()-1);  //反转所有数字
        reverse(nums,0,k%nums.size()-1);//反转前k个数字
        reverse(nums,k%nums.size(),nums.size()-1);//反转后n-k个数字
    }
};

#solution2 使用环状替换 4ms O(n) O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for(int start = 0; count < nums.size(); start++){
            int prekey = start;
            int preval = nums[start];
            do{
                //存值
                int nextkey = (prekey + k) % nums.size();
                int nextval = nums[nextkey];
                //赋值
                nums[nextkey] = preval;
                //存值
                prekey = nextkey;
                preval = nextval;
                count++;
            }while(start!= prekey);
        }
    }
};
