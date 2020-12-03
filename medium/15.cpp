class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = int(nums.size());
        if(n <= 2){
            return result;
        }
        int possibleSize = n - 2;
        sort(nums.begin(), nums.end());
        for(int index = 0; index < possibleSize; index++){
            int intIndex = nums[index];
            if(intIndex > 0){
                break;
            }
            int negative = 0 - intIndex;
            int left = index + 1;
            int right = n - 1;
            while(left < right){
                int intLeft = nums[left];
                int intRight = nums[right];
                if(intLeft + intRight == negative){
                    vector<int> vec{intIndex, intLeft, intRight};
                    result.push_back(vec);
                    while(left < right && nums[left] == intLeft){
                        left++;
                    }
                    while(left < right && nums[right] == intRight){
                        right--;
                    }
                }
                else if(intLeft + intRight < negative){
                    left++;
                }
                else if(intLeft + intRight > negative){
                    right--;
                }
            }
            while(index + 1 < possibleSize && nums[index] == nums[index + 1]){
                index++;
            }
        }
        return result;
    }
};