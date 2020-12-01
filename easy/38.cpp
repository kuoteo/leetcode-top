class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        int cout = 1;
        string prefix = countAndSay(n - 1), result = "";
        for(int i = 0; i < prefix.length(); ++i){
            if(prefix[i] == prefix[i + 1]){
                cout++;
            }
            else{
                result = result + to_string(cout) + prefix[i];
                cout = 1;
            }
        }
        return result;
    }
};