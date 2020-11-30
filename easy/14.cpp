#solution1 横向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
        int count = strs.size();
        string prefix = strs[0];
        for(int i = 1; i < count; i++){
            prefix = CommonPrefix(prefix, strs[i]);
            if(!prefix.size()){
                break;
            }
        }
        return prefix;
    }
    string CommonPrefix(const string& str1, const string& str2){
        int minlen = min(str1.size(), str2.size());
        int index = 0;
        while(index < minlen && str1[index] == str2[index]){
            ++index;
        }
        return str1.substr(0, index);
    }
};

#solution2 纵向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for(int i = 0; i < length; i++){
            for(int j = 1; j < count; j++){
                if(i == strs[j].size() || strs[j][i] != strs[0][i]){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

#solution3 二分查找

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
        //求数组中最短字符串的长度，第三次参数不是很懂...
        int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
        int low = 0, high = minLength;
        while(low < high){
            //为什么使用low + (high - low) / 2而不使用(high + low) / 2呢？目的是防止溢出！
            int mid = (high - low + 1)/2 + low;
            if(isCommonPrefix(strs, mid)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }
    bool isCommonPrefix(const vector<string>& strs,int length){
        string str0 = strs[0].substr(0,length);
        int count = strs.size();
        for(int i = 1 ;i < count;i++){
            string str = strs[i];
            for(int j = 0;j < length;j++ ){
                if(str0[j] != str[j]){
                    return false;
                }
            }
        }
        return true;
    }
};