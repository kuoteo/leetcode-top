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

#加上括号运算
class Solution {
public: 
    int calculate(string s) {
        int begin = 0;
        return calhelper(string, begin)
    }

    int calhelper(string s, &i) {//i用来记录计算开始的索引
        stack<int> sta;
        int res = 0;
        int num = 0;
        char sign = '+';
        for(i = 0; i < s.size(); i++){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            if(s[i] == '('){
                num = calhelper(s, ++i);    //进入递归
                i++;
            }
            if(((s[i] > '9' || s[i] < '0') && c!=' ') || i == s.size() - 1){
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
            if(s[i] == ')'){
                break;
            }
        }
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};