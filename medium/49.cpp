class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> list;
        vector<vector<string>> vec;
        int sub = 0;
        for(auto ch : strs){
            string tmp = ch;
            sort(tmp.begin(), tmp.end());
            if(list.count(tmp)){
                vec[list[tmp]].push_back(ch);
            }else{
                vector<string> v(1,ch);
                vec.push_back(v);
                list[tmp] = sub++;
            }
        }
        return vec;
    }
};