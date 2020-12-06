#上 (top,left)..(top,right)
#右 (top + 1,right)..(bottom,right)
#下 (bottom ,right - 1)..(bottom,left + 1)
#左 (bottom,left)..(top + 1,left)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> vec;
        if(rows == 0 && cols == 0){
            return vec;
        }
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while(left <= right && top <= bottom){
            for(int column = left; column <= right; column++){
                vec.push_back(matrix[top][column]);
            }
            for(int row = top + 1; row <= bottom; row++){
                vec.push_back(matrix[row][right]);
            }
            if(left < right && top < bottom){
                for(int column = right - 1; column > left; column--){
                    vec.push_back(matrix[bottom][column]);
                }
                for(int row = bottom; row > top; row--){
                    vec.push_back(matrix[row][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return vec;
    }
};