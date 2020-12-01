class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        if(s.size() % 2 == 1){
            return false;
        }
        unordered_map<char,char> map{
            {'}','{'},
            {')','('},
            {']','['}
        };
        for(char ch : s){
            if(map.count(ch)){
                if(sta.empty() || sta.top() != map[ch]){
                    return false;
                }
                sta.pop();
            }
            else{
                sta.push(ch);
            }
        }
        return sta.empty();
    }
};