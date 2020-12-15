#solution1 0ms O(nm) O(nm)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {-1, 0 , 1}; 
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> copyboard(rows, vector<int>(cols, 0));
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                copyboard[row][col] = board[row][col];
            }
        }
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                int livenum = 0;
                for(int i = 0; i < 3; ++i){
                    for(int j = 0; j < 3; ++j){
                        if(!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r = (neighbors[i] + row);
                            int c = (neighbors[j] + col);

                            if((r < rows && r >= 0) && (c < cols && c >= 0) && (copyboard[r][c] == 1)){
                                ++livenum;
                            }
                        }
                    }
                }

                if(copyboard[row][col] == 1 && (livenum < 2 || livenum > 3))
                    board[row][col] = 0;
                if(copyboard[row][col] == 0 && livenum == 3)
                    board[row][col] = 1;
            }
        }
    }
};