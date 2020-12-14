#solution1 哈希表 32ms O(n) O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> list;
        for(int num : nums){
            if(list[num] == 1) return num;
            list[num]++;
        }
        return false;
    }
};

#solution2 二分查找 24ms O(nlogn) O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                cnt += nums[i] <= mid;
            }
            if(cnt <= mid)
                l = mid + 1;
            else{
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

#solution3 快慢指针 24ms O(n) O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};