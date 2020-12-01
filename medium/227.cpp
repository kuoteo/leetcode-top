class Solution {
public:
    int calculate(string s) {
        stack<int> sta;
        int res = 0;
        int num = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            if((!isdigit(c) && c!=' ') || i == s.size() - 1){
                int pre;
                switch(sign){
                    case '+' :
                        sta.push(num); 
                        break;
                    case '-' :
                        sta.push(-num); 
                        break;
                    case '*' :
                        pre = sta.top();
                        sta.pop();
                        sta.push(pre * num);
                        break;
                    case '/' :
                        pre = sta.top();
                        sta.pop();
                        sta.push(pre / num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};