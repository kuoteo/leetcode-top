#solution one 中心扩展 
class Solution {
public:
    pair<int,int>expandAroundCenter(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if(right1 - left1 > end - start){
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start){
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

#solution two 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        string ans;
        //k表示检索的长度+1
        for(int k = 0; k < n; k++){
            for(int i = 0; i + k < n; i++){
                int j = i + k;
                if(k == 0){
                    dp[i][j] = 1;
                }else if(k == 1){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if(dp[i][j] && k + 1 > ans.size()){
                    ans = s.substr(i, k + 1);
                }
            }
        }
        return ans;
    }
};