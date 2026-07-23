class Solution {
public:
    int calculate(string s) {
        int current_num = 0;
        int current_op = '+';
        stack<int> calc;
        int answer = 0;

        for(int i = 0; i<s.size(); i++) {
            char c = s[i];
            if(c >= '0' && c<='9') {
                current_num = current_num * 10 + ( c-'0');
            }
            if((!isdigit(c) && c != ' ') || i == s.size()-1) {
                if(current_op == '+') {
                    calc.push(current_num);
                } else if(current_op == '-') {
                    calc.push(-current_num);
                } else if(current_op == '*') {
                    int product = current_num * calc.top();
                    calc.pop();
                    calc.push(product);
                } else if(current_op == '/') {
                    int quotient = calc.top() / current_num;
                    calc.pop();
                    calc.push(quotient);
                }
                current_op = c;
                current_num = 0;
            }
        }
        while(!calc.empty()) {
            answer += calc.top();
            calc.pop();
        }
    return answer;
    }
};