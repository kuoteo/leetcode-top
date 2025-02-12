class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& word, int k){
        if(board[i][j] != word[k]){
            return false;
        }else if(k == word.size() - 1){
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> diretions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for(const auto& dir : diretions){
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()){
                if(!visited[newi][newj]){
                    bool flag = check(board, visited, newi, newj, word, k + 1);
                    if(flag){
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int> (w));
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                bool flag = check(board, visited, i, j, word, 0);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};