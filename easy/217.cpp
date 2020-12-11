#solution1 哈希表 O(n) O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> list;
        for(int num : nums){
            if(list[num] == 1) return true;
            ++list[num];
        }
        return false;
    }
};