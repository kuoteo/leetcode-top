#solution1 36ms 使用set 空间O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //[rows][cols]
        set<int> rows, cols;
        //[m][n]
        int m = matrix.size(), n = matrix[0].size();
        //[i][j]
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int r : rows){
            for(int j = 0; j < n; j++)
                matrix[r][j] = 0;
        }
        for(int c : cols){
            for(int i = 0; i < m; i++)
                matrix[i][c] = 0;
        }
    }
};