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


#solution2 28ms 空间O(1) 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        //[R,C]
        int R = matrix.size();
        int C = matrix[0].size();
        //[i,j]
        for(int i = 0; i < R; i++){
            //第一行看[0][0] 第一列看isCol
            if(matrix[i][0] == 0)
                isCol = true;
            
            for(int j = 1; j < C; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //赋值0
        for(int i = 1; i < R; i++){
            for(int j = 1; j < C; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        //若[0][0]为0->第一行为0
        if(matrix[0][0] == 0){
            for(int j = 1; j < C; j++)
                matrix[0][j] = 0;
        }
        
        //若isCol为true->第一列为0
        if(isCol){
            for(int i = 0; i < R; i++)
                matrix[i][0] = 0;
        }
    }
};