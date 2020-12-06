class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> vec(n, 0);
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                vec[j] = (i > 0 && j > 0) ? vec[j] = vec[j - 1] + vec[j] : 1;
            }
        }
        return vec[n - 1];
    }
};