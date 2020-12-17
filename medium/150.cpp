class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int k = 0 ; k < tokens.size(); ++k){
            if(tokens[k] == "+" || tokens[k] == "-" || tokens[k] == "*" || tokens[k] == "/"){
                int i = s.top();s.pop();
                int j = s.top();s.pop();
                if(tokens[k] == "+") s.push(j + i);
                if(tokens[k] == "-") s.push(j - i);
                if(tokens[k] == "*") s.push(j * i);
                if(tokens[k] == "/") s.push(j / i);
            }else{
                s.push(stoi(tokens[k]));
            }
        }
        return s.top();
    }
};