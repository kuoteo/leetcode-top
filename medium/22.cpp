class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        int lc = 0, rc = 0;
        dfs(vec, "", lc, rc, n);
        return vec;
    }
    void dfs(vector<string>& vec,string path,int lc, int rc, int n){
        if(lc < rc || lc > n || rc > n){
            return;
        }
        if(lc == rc && lc == n){
            vec.push_back(path);
            return;
        }
        dfs(vec, path + "(", lc + 1, rc, n);
        dfs(vec, path + ")", lc, rc + 1, n);        
    }
};