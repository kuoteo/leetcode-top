class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        //初始化哈希表
        unordered_map<char, int> list{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        for(int i = 0; i < s.length(); i++){
            if(list[s[i]] < list[s[i + 1]]){
                result -= list[s[i]];
            }else{
                result += list[s[i]];
            }
        }
        return result;
    }
};