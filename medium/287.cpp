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